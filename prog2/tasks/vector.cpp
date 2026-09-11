/*
Criar um vetor de número de ponto flutuante contendo a soma de número anterior
com seu quadrado. O primeiro (ìndice 0 é o que o usuário digitar.) Imprima a
soma de todos os termos.
*/

#include <cmath>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

using std::cerr;
using std::cin;
using std::cout;
using std::getline;
using std::pow;
using std::string;
using std::stringstream;

int
main (void)
{
  size_t i{};
  string user_input{};
  cout << "Digite o índice desejado para o primeiro vetor do exercício: ";
  getline (cin, user_input);

#ifdef _WIN32
  SetConsoleCP (CP_UTF8);
  SetConsoleOutputCP (CP_UTF8);
#endif

  try
    {
      stringstream s (user_input);
      s.exceptions (std::ios::failbit | std::ios::badbit);
      size_t siz{};

      s >> siz;

      if (siz <= 0)
        throw std::runtime_error (
            "Não é possível criar vetores com indices negativos!");

      double vec[siz], prod[siz];

      for (i = 0; i < siz; i++)
        {
          cout << "Digite o " << i + 1 << "º número: ";
          cin >> vec[i];
          prod[i] = vec[i] + pow (vec[i], 2.0);
        }

      double prod_final{ 0 };

      for (i = 0; i < siz; i++)
        prod_final += prod[i];

      cout << "A soma de todos os termos do vetor produzido com o vetor "
              "inserido "
              "pelo usuário é : "
           << prod_final << '\n';
    }
  catch (const std::exception &e)
    {
      cerr << e.what () << '\n';
      return 1;
    }

  return 0;
}
