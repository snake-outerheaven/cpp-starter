/* Escreva um programa em C++ que calcula a distancia euclidiana entre dois pontos, ˆ
P1(x1, y1) e P2(x2, y2), em um plano cartesiano. O programa deve solicitar ao usuario ´
as quatro coordenadas (‘x1‘, ‘y1‘, ‘x2‘, ‘y2‘) e, em seguida, exibir a distancia calculada ˆ
com base na formula: ´
d = √︁(x2 − x1) 2 + (y2 − y1) 2

Dica: A funcão ‘sqrt()‘ da biblioteca ˜ cmath pode ser usada para calcular a raiz quadrada. */

#include <chrono>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <thread>

constexpr auto STD_WAIT = 750; // expressão constante em tempo de compilação

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
void consoleSetup(void)
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
}
#endif

void waitMillis(int);

int main(void)
{
    double x1{}, y1{}, x2{}, y2{}, inter1{}, inter2{}, interFinal{}, r{};
    std::string userInput{};

#ifdef _WIN32
    consoleSetup();
#endif

    std::cout << std::fixed << std::setprecision(2); // setar precisão máxima do cout (printf mais fácil)

    while (1)
    {
        userInput.clear();
        std::cout << "(digite \"sair\" para sair do programa)\nx1, y1, x2, y2: ";
        std::getline(std::cin, userInput);
        std::cout << "Input lido: " << userInput << '\n';
        if (userInput == "sair")
        {
            std::cout << "Saindo...\n";
            waitMillis(STD_WAIT);
            return 1;
        }

        try
        {

            if (userInput.empty())
                throw std::invalid_argument("Entrada vazia detectada, reescreva novamente!");

            std::stringstream s(userInput);

            s.exceptions(std::ios::badbit | std::ios::failbit);

            s >> x1 >> y1 >> x2 >> y2;

            std::cout << "Números lidos pelo programa\nx1: " << x1 << "\ty1: " << y1 << "\tx2: " << x2 << "\ty2: " << y2
                      << '\n';

            std::cout << "Você concorda com os números? (s/n)\n> ";
            std::getline(std::cin, userInput);

            if (userInput != "s")
                throw std::logic_error("Usuário negou ou respondeu de forma inválida, por favor, digite novamente.");

            inter1 = ((x2 - x1) * (x2 - x1));
            inter2 = ((y2 - y1) * (y2 - y1));

            interFinal = inter1 + inter2;
            
            r = std::sqrt(interFinal);

            std::cout << "A distância euclidiana entre os pontos 1 (x1: " << x1 << " y1: " << y1
                      << ") e ponto 2 (x2: " << x2 << " y2: " << y2 << ") é " << r << ".\n";

            break;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Exceção levantada: " << e.what() << '\n';
            waitMillis(STD_WAIT);
            continue;
        }
    }
    return 0;
}

void waitMillis(int millis)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(millis));
}
