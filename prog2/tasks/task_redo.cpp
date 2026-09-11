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
#include <array> // classe da biblioteca padrão que representa um vetor estático, com baterias
#include <cctype>    // biblioteca de caracteres do C, pro C++
#include <cmath>     // biblioteca de funções matemáticas do C, pro C++
#include <iostream>  // biblioteca de fluxos de entrada e saída do C++
#include <sstream>   // biblioteca de fluxos
#include <stdexcept> // biblioteca de exceções padrão da biblioteca, usada para controle de erros mais fino
#include <string> // classe da biblioteca padrão que representa um vetor dinâmico de caracteres.
#ifdef _WIN32
#include <windows.h> // include da api do windows, usada para criar programas que vão além do padrão C++ na plataforma
#endif

std::string lower (const std::string &);

int
main (void)
{
  std::string user_input{};

  double a{}, b{}, c{};

  double d{}, x1{}, x2{};

  int state;

  a = b = c = 0;

#ifdef _WIN32
  SetConsoleCP (CP_UTF8);
  SetConsoleOutputCP (CP_UTF8);
#endif

  // funções da win32, do subsistema do console, para manipular o code page
  // (tipo o locale, mas nativo do Windows, no Unix é mais fácil) pois o
  // codepage do Windows segue o legado do DOS, que é a página 850, de Latim
  // (????) tb n entendo mas é o que precisa ser feito.

  while (1)
    {
      user_input.clear ();
      std::cout << "Digite \"sair\" para sair do programa.\nA, B, C: ";
      std::getline (std::cin, user_input);

      if (lower (user_input) == "sair")
        break;

      try
        {
          std::stringstream s (user_input);

          s.exceptions (
              std::ios::failbit
              | std::ios::badbit); // desmascaro bit mask de exceções de input
                                   // output pro stringstream
          // q é um objeto da biblioteca padrão usado para transformar strings
          // em fluxos, bom para parsear como estamos fazendo aq.

          s >> a >> b >> c; // se subir exceção, cai no catch.

          if (a == 0)
            throw std::runtime_error (
                "Não existe função de segundo grau com coeficiente a = 0");
          // considera regra de existência da função quadrática.
        }
      catch (const std::exception
                 &e) // classe pai de todas as exceções da biblioteca padrão
        {
          std::cout << "Falha em seção crítica do programa: " << e.what ()
                    << '\n';
          continue;
        }

      d = b * b - (4 * a * c);

      if (d < 0)
        state = -1;
      else if (d == 0)
        state = 0;
      else
        state = 1;

      std::cout << "Delta calculado: " << d << '\n';

      switch (state)
        {
        case -1:
          std::cout << "Não existem raízes reais para delta < 0.\n";
          break;

        case 0:
          std::cout << "Só existe uma raiz real para delta = 0.\n";
          x1 = (-b + sqrt (d)) / (2.0 * a);
          std::cout << "Raíz real = " << x1 << ".\n";
          break;
        case 1:
          std::cout << "Existem duas raizes reais para delta > 0.\n";
          x1 = (-b + sqrt (d)) / (2.0 * a);
          x2 = (-b - sqrt (d)) / (2.0 * a);
          std::cout << "1ª Raíz real = " << x1 << ".\n"
                    << "2ª Raíz real = " << x2 << ".\n";
          break;
        default:
          std::cout << "Isso é impossível!\n";
          break; // XD
        }
    }

  return 0;
}

// função ajudante para gerar uma cópia de uma string com todos os seus
// caracteres minusculos
std::string
lower (const std::string &s)
{
  std::string result = s;

  for (char &c : result)
    c = std::tolower ((unsigned char) c);

  return result;
}
