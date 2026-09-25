#include <cmath>
#include <cstdint>
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

#if defined(_MSC_VER)
#define FORCE_INLINE __forceinline
#else
#define FORCE_INLINE __attribute__((always_inline)) inline
#endif

// Sem std::pow para permitir que o compilador use instruções SIMD/FMA de hardware
FORCE_INLINE double f(double t)
{
    return (3.0 * t * t) + (4.0 * t) - 5.0;
}

double calcular_riemann(double a, double b, uint64_t steps)
{
    const double base = (b - a) / steps;
    double global_sum = 0.0;

// Paralelismo OpenMP para distribuição de carga entre os núcleos da CPU
#pragma omp parallel reduction(+ : global_sum)
    {
        double local_sum = 0.0;

#pragma omp for nowait
        for (int64_t i = 0; i < static_cast<int64_t>(steps); i++)
        {
            double t = a + (static_cast<double>(i) + 0.5) * base;
            local_sum += f(t);
        }
        global_sum += local_sum;
    }

    return global_sum * base;
}

int main(void)
{
#ifdef _WIN32
    setconsole();
#endif

    double a{1.0}, b{5.0};
    uint64_t passos = 10e10; // 1 bilhão de iterações

    std::cout << std::fixed << std::setprecision(10);
    std::cout << "Calculando integral com " << passos << " iterações...\n";

    double resultado = calcular_riemann(a, b, passos);

    std::cout << "Resultado: " << resultado << " m\n";

    return 0;
}
