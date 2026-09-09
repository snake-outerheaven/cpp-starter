/*
    Os alunos deverão gravar a tela do computador enquanto criam o
   código-fonte, em C++, de um programa que calcule o valor do discriminante
   (delta) e das raízes reais de uma equação o segundo grau a partir dos
   coeficientes fornecidos via teclado. O programa deve testar se a entrada é
   valida e ter uma região usando switch e case para os três tipos de delta.
    Mostre também o processo de compilação e execução do programa. Poste,
   preferencialmente no YouTube.
*/

#define WIN32_LEAN_AND_MEAN // para reduzir bloat da api do windows
#include <cctype>
#include <cmath>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#ifdef WIN_32
#include <windows.h>
#endif

std::string lower (const std::string &);

int
main (void)
{
  double a{}, b{}, c{};
  double d{}, x1{}, x2{};

  std::string user_input{};

  int state{};

#ifdef WIN_32
  SetConsoleCp (CP_UTF);
  SetConsoleOutputCp (CP_UTF);
#endif

  while (1)
    {
      user_input.clear ();
      std::cout << "A, B, C: ";
      std::getline (std::cin, user_input);

      if (lower (user_input) == "sair")
        {
          std::cout << "Saindo do programa...";
          break;
        }

      try
        {
          std::stringstream s (user_input);

          s.exceptions (
              std::ios::failbit
              | std::ios::badbit); // desmascara exceções, para tratar erros de
                                   // forma mais clara

          s >> a >> b >> c;

          if (a == 0)
            throw std::runtime_error (
                "Não existe equação quadrática com a = 0");

          std::cout << "Números lidos pelo programa: " << a << " " << b << " "
                    << c << '\n';

          std::cout << "Você confirma os números? ";

          user_input.clear ();

          std::getline (std::cin, user_input);

          if (lower (user_input) == "n")
            continue;
        }
      catch (const std::exception &e)
        {
          std::cerr << "Falha em seção crítica do programa " << e.what ()
                    << '\n';
          continue;
        }

      d = b * b - (4 * a * c);

      std::cout << "Delta calculado: " << d << '\n';

      if (d < 0)
        state = -1;
      else if (d == 0)
        state = 0;
      else
        state = 1;

      switch (state)
        {
        case -1:
          std::cout << "Não existem raízes reais para delta < 0\n";
          break;
        case 0:
          x1 = -b + sqrt (d) / (2.0 * a);

          std::cout << "Existe apenas uma raíz real para delta = 0\nRaíz = "
                    << x1 << '\n';

          break;
        case 1:
          x1 = -b + sqrt (d) / (2.0 * a);
          x2 = -b - sqrt (d) / (2.0 * a);

          std::cout << "Existe duas raízes reais para delta > 0\nRaíz 1 = "
                    << x1 << '\n'
                    << "Raiz 2 = " << x2 << '\n';
          break;
        }
    }

  return 0;
}

std::string
lower (const std::string &str)
{

  std::string result{};

  for (char c : str)
    result += std::tolower (c);

  return str;
}