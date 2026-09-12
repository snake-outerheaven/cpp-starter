/*
Criar um vetor de número de ponto flutuante contendo a soma de número anterior
com seu quadrado. O primeiro (ìndice 0 é o que o usuário digitar.) Imprima a
soma de todos os termos.
*/

#define WIN32_LEAN_AND_MEAN
#include <cctype>
#include <cmath>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

std::string lower (const std::string &);

#ifdef _WIN32
#include <windows.h>
#endif

int
main (void)
{
  std::vector<long double> v{};

  std::string user_input{};

  std::stringstream s{};

#ifdef _WIN32
  SetConsoleCP (CP_UTF8);
  SetConsoleOutputCP (CP_UTF8);
#endif

  while (1)
    {
      int idx{};
      long double first{};
      long double prod_final{ 0 };
      user_input.clear ();
      v.clear ();
      s.clear ();
      std::cout << "Digite o tamanho do vector desejado: ";
      std::getline (std::cin, user_input);

      if (lower (user_input) == "sair")
        break;

      s.str (user_input);
      s.exceptions (std::ios::failbit | std::ios::badbit);

      try
        {
          s.clear ();
          s >> idx;

          if (idx <= 0)
            throw std::invalid_argument ("Não existe vetores com idx <= 0");

          v.resize (idx); // faz a préalocação de memória aqui, para facilitar.

          std::cout << "Digite o número do índice 0: ";
          std::getline (std::cin, user_input);
          s.str (user_input);
          s.clear ();
          s >> first;
          v.at (0) = first;

          prod_final += first;

          for (auto i = (v.begin () + 1); i < v.end (); i++)
            {
              auto ant = *(
                  i
                  - 1); // desreferencia o iterador para obter o valor anterior
              *i = ant + std::pow (ant, 2);

              prod_final += *i;
            }
        }
      catch (const std::exception &e)
        {
          std::cerr << "Erro crítico em sessão importante do programa: "
                    << e.what () << '\n';
          continue;
        }

      std::cout << "Produto final: " << prod_final << std::endl;

      break; // remover, debug
    }

  return 0;
}

std::string
lower (const std::string &str)
{
  std::string result{};

  for (auto c : str)
    {
      result.push_back (
          static_cast<char> (std::tolower (static_cast<unsigned char> (c))));
    }

  return result;
}
