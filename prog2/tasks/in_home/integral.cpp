#include <iomanip>
#include <iostream>

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>
void setconsole(void)
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
}
#endif

inline double f(double t)
{
    return t * (t * (t + 2.0) - 5.0);
}

// inline força o compilador à inserir o código da função diretamente na função principal, ao invés
// de fazer a instruçao de chamada para o código.

int main(void)
{
#ifdef _WIN32
    setconsole();
#endif

    double a{1.0};
    double b{5.0};

    double resultado{f(b) - f(a)};

    std::cout << std::fixed << std::setprecision(10);
    std::cout << "Calculando integral via solucao analitica...\n";
    std::cout << "Resultado: " << resultado << " m\n";

    return 0;
}
