#include <boost/algorithm/string.hpp>
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <thread>

#define MIN 1
#define MAX 100

#define STD_WAIT 750

/*
  Refazer com orientação a objetos.
*/

int
main (void)
{
  std::random_device rd;
  std::mt19937 rand (rd ());
  std::uniform_int_distribution<int> dist (MIN, MAX);

  std::string user_input;

  int secret = dist (rand);

  int num, tries = 0, diff;

  while (1)
    {
      std::cin.clear ();

      tries++;

      std::cout << "Digite um número entre " << MIN << " e " << MAX
                << "\n(digite sair para encerrar o "
                   "jogo)\nVocê está na tentativa "
                << tries << ".\n-> ";
      std::getline (std::cin, user_input);

      boost::trim (user_input);

      if (boost::equals (user_input, "sair"))
        {
          std::cout << "Entendido, saindo do programa...";
          std::this_thread::sleep_for (std::chrono::milliseconds (1250));
          return 0;
        }

      try
        {
          num = std::stoi (user_input);
        }
      catch (const std::exception &e)
        {
          std::cerr << "Digite um número válido!!!!" << '\n';
          std::this_thread::sleep_for (std::chrono::milliseconds (STD_WAIT));
          continue;
        }

      std::cout << "O número digitado lido pelo programa é " << num << ".\n";

      std::this_thread::sleep_for (std::chrono::milliseconds (STD_WAIT));

      diff = secret - num;

      if (diff)
        {
          if (diff > 0)
            {

              if (diff <= 2)
                std::cout
                    << "Está muito perto, tente um número um pouco maior!\n";

              else if (diff <= 10)
                std::cout
                    << "Está pelando!!!! tente um número um cadinho maior!\n";
              else
                std::cout << "Está muito longe, tente um número maior.\n";
            }
          else if (diff < 0)
            {
              if (diff >= -2)
                std::cout
                    << "Está muito perto, tente um número um pouco menor!\n";
              else if (diff >= -10)
                std::cout
                    << "Está pelando!!!! tente um número um cadinho menor!\n";
              else
                std::cout << "Está muito longe, tente um número menor\n";
            }
          continue;
        }
      else
        {
          if (tries > 2)
            std::cout << "Você acertou o número secreto com " << tries
                      << "tentativas!\n";

          else

            std::cout << "Você acertou o número secreto de primeira!\n";
          break;
        }
    }

  return 0;
}
