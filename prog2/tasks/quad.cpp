/*
  Crie em C++ um programa que solicite ao usuário os coeficientes a, b e c
  (tipo double) de uma equação de segundo grau e depois imprima o delta, x,
  x2 (raizes reais)
*/

#include <cmath> // biblioteca de funções matemáticas do C, que pode ser usada no C++
#include <iostream> // biblioteca de fluxos (tipo importante de objeto que usa operador >> <<) que lida com entrada e saída de dados
#include <sstream> // objeto mais genérico de fluxo, permite um parsing mais avançado
#include <string> // classe da biblioteca padrão que gerencia um vetor dinâmico de caracteres.

std::string lower (const std::string &);

int
main (void)
{
  double a{}, b{}, c{};
  double d{}, x1{}, x2{};

  std::string user_input;

  // declaração moderna de variáveis, inicializadas de forma segura, ao
  // invés do modelo c antigo que continha lixo.

  while (1)
    {
      user_input.clear (); // truca o buffer dinâmico para permitir o reset
                           // do buffer de entrada do usuário, em C, seria
                           // user_input[0] = '\0';

      std::cout << "a, b, c? ";

      std::getline (std::cin, user_input); // leio até \n do std::cin, fluxo de
                                           // entrada em CLI do programa.

      if (lower (user_input) == "Sair")
        break;

      d = b * b - 4 * a * c;

      x1 = (-b + sqrt (d)) / (2 * a);
      x2 = (-b - sqrt (d)) / (2 * a);

      std::cout << "\n\tdelta = " << d << "\n\tx1= " << x1 << "\n\tx2= " << x2
                << std::endl;
    }

  return 0;
}

std::string
lower (const std::string &ref)
{
  std::string prod;

  for (char c : ref)
    prod += std::tolower ((char) c);

  return prod;
}

/*
 * Coisas a melhorar no código:
 *
 * - Testes do delta;
 * - Validar a resposta do usuário;
 * - Criar loop de eventos do programa
 *
 *   A tarefa é criar um programa mais robusto e com mais features
 */
