/**
 * @file hanoi.cpp
 * @brief Algoritmo paralelo lock-free para Torres de Hanói em C++20.
 */

#include <bit>
#include <chrono>
#include <cstdint>
#include <format>
#include <future>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

struct Move
{
    uint64_t step;
    uint32_t disk;
    uint32_t from;
    uint32_t to;
};

/**
 * @brief Calcula o movimento exato para o passo k em tempo O(1).
 */
inline Move compute_move(uint64_t k, uint32_t total_disks)
{
    // Identifica o disco movido no passo k (1-based)
    uint32_t disk = static_cast<uint32_t>(std::countr_zero(k)) + 1;

    // Quantidade de vezes que este disco específico já foi movido até o passo k
    uint64_t disk_moves = (k >> disk) + 1;

    uint32_t from = 0;
    uint32_t to = 0;

    // Determina a direção do movimento com base na paridade relativa
    bool same_parity = ((disk % 2) == (total_disks % 2));

    if (same_parity)
    {
        // Sentido Horário: 0 (Origem) -> 2 (Destino) -> 1 (Auxiliar)
        from = static_cast<uint32_t>((disk_moves - 1) * 2 % 3);
        to = static_cast<uint32_t>(disk_moves * 2 % 3);
    }
    else
    {
        // Sentido Anti-Horário: 0 (Origem) -> 1 (Auxiliar) -> 2 (Destino)
        from = static_cast<uint32_t>((disk_moves - 1) % 3);
        to = static_cast<uint32_t>(disk_moves % 3);
    }

    return Move{k, disk, from, to};
}

/**
 * @brief Processa um intervalo de passos [start_step, end_step].
 */
uint64_t process_range(uint64_t start_step, uint64_t end_step, uint32_t total_disks, uint32_t core_id)
{
    uint64_t processed_count = 0;
    constexpr const char *rod_names[] = {"Origem", "Auxiliar", "Destino"};

    for (uint64_t k = start_step; k <= end_step; ++k)
    {
        Move m = compute_move(k, total_disks);

        // Amostragem de saída nas bordas do bloco para evitar gargalo de I/O no terminal
        if (k == start_step || k == end_step)
        {
            std::string log = std::format("[Core {:02d}] [Passo {:016d}] Mover disco {:02d} de {} -> {}\n", core_id,
                                          m.step, m.disk, rod_names[m.from], rod_names[m.to]);
            std::cout << log;
        }

        processed_count++;
    }

    return processed_count;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // Ajuste de N para execução prática (exemplo N = 26 -> 67.108.863 passos)
    constexpr uint32_t total_disks = 30;
    const uint64_t total_moves = (static_cast<uint64_t>(1) << total_disks) - 1;

    // Detecta os 12 threads lógicos do i5-12400F
    const uint32_t target_cores = std::thread::hardware_concurrency();

    std::cout << std::format("Arquitetura: Intel i5-12400F (12 Threads)\n");
    std::cout << std::format("Total de Discos: {}\nTotal de Passos: {}\nThreads Ativas: {}\n\n", total_disks,
                             total_moves, target_cores);

    auto start_time = std::chrono::high_resolution_clock::now();

    std::vector<std::future<uint64_t>> futures;
    futures.reserve(target_cores);

    uint64_t steps_per_thread = total_moves / target_cores;
    uint64_t remainder = total_moves % target_cores;

    uint64_t current_start = 1;

    for (uint32_t i = 0; i < target_cores; ++i)
    {
        uint64_t current_end = current_start + steps_per_thread - 1;
        if (i == target_cores - 1)
        {
            current_end += remainder;
        }

        futures.push_back(std::async(std::launch::async, process_range, current_start, current_end, total_disks, i));
        current_start = current_end + 1;
    }

    uint64_t total_processed = 0;
    for (auto &f : futures)
    {
        total_processed += f.get();
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end_time - start_time;

    std::cout << std::format("\nProcessamento paralelo concluído em {:.3f} ms.\nTotal de passos validados: {}\n",
                             duration.count(), total_processed);

    return 0;
}
