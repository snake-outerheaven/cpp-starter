/*
  Crie em C++ um programa que solicite ao usuário os coeficientes a, b e c
  (tipo double) de uma equação de segundo grau e depois imprima o delta, x,
  x2 (raizes reais)
*/

#include <cmath> // biblioteca de funções matemáticas do C, que pode ser usada no C++
#include <iostream> // biblioteca de fluxos (tipo importante de objeto que usa operador >> <<) que lida com entrada e saída de dados

using namespace std; // limita o namespace global para o da biblioteca padrão, dá problemas com libs externas

int
main (void)
{
  double a{}, b{}, c{};
  double d{}, x1{}, x2{};

  // declaração moderna de variáveis, inicializadas de forma segura, ao invés do modelo c antigo que continha lixo.

  cout << "a, b, c? ";
  cin >> a >> b >> c;

  d = b * b - 4 * a * c;

  x1 = (-b + sqrt (d)) / (2 * a);
  x2 = (-b - sqrt (d)) / (2 * a);

  cout << "\n\tdelta = " << d << "\n\tx1= " << x1 << "\n\tx2= " << x2 << endl;

  return 0;
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
