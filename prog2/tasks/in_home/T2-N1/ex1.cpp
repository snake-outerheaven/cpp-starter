#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

using string = std::string;

// typeinference, acho q a gente n vai ver isso

constexpr auto MIN = 0.0;

constexpr auto MAX = 10.0;

int main(void)
{
    int n{0};

    size_t siz{};

    double *notas = nullptr, media{0}, sum{0}, menor, maior;

    double temp;

    string user_input{};

    // vou fazer mais simples

    while (1)
    {

        try
        {

            std::cout << "Por favor, digite o número de alunos: ";
            std::getline(std::cin, user_input);

            n = std::stoi(user_input);

            if (n <= 0)
                throw std::logic_error("Não existe turmas com número nulo ou negativo de alunos.");

            siz = static_cast<size_t>(n) * sizeof(double);

            std::cout << "Bytes alocados para o trabalho: " << siz << ".\n";

            notas = static_cast<double *>(malloc(siz));

            for (int i = 0; i < n; i++)
                while (1)
                {
                    std::cout << "Digite a " << i + 1 << "ª nota: ";
                    std::getline(std::cin, user_input);
                    notas[i] = std::stod(user_input); // se isso der ruim, cai no catch ali embaixo

                    if (notas[i] < MIN || notas[i] > MAX)
                    {
                        std::cerr << "Digite uma nota válida entre 0.0 ou 10.0\n";
                        continue;
                    } // nota não pode quebrar a lógica de negócio.

                    break; // tudo certo
                }

            for (int i = 0; i < n; i++)
                sum += notas[i];

            for (int i = 1; i < n; i++) // o acesso indevido se deu aqui, no swap na posição anterior ao inicio
                for (int x = n - 1; x >= i; x--)
                    if (notas[x] < notas[x - 1])
                    {
                        temp = notas[x];
                        notas[x] = notas[x - 1];
                        notas[x - 1] = temp;
                    }

            // bubble sort

            menor = notas[0];
            maior = notas[n - 1];

            media = sum / static_cast<double>(n);

            std::cout << std::fixed << std::setprecision(2);

            std::cout << "A média da turma é: " << media << " e a menor nota é: " << menor
                      << " e a maior nota é: " << maior << ".\n";

             free(notas); // a memória é liberada aqui e o loop acaba, mas gostaria de ver o que acontece se eu esqueço de liberar

	     // dps q o programa retorna a main, o espaço de trabalho é limpo pelo kernel.

            break;
        }
        catch (const std::exception &e)
        {
            std::cout << "Erro de execução: " << e.what() << '\n';
            continue;
        }
    }

    return 0; // fim aqui
}
