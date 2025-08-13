#include <iostream>
// biblioteca padrão para entrada e saida de dados no terminal
// o que eu mais vou usar: std::cin, std::cout e std::cerr

#include <iomanip>
// biblioteca padrão para manipulação de streams, sendo útil
// para controlar o número de casas decimais de um número
// exibido no texto, por ex ( std::cout << std::fixed << std::setprecision(2) << var << std::endl; )

#include <string>
// biblioteca que introduz o objeto String
// e diversos métodos úteis para facilitar
// o manejamento de texto.

#include <cstdlib>
// não há muito o que falar, este é um include essencial
// para usar funções da stdlib de C em C++, sendo essencial
// para poder usar rand, srand, system e outras funções.

#include <ctime>
// bibiioteca que me permite incluir implementações da biblioteca
// time de C, sendo usada aqui pela função time, que vai retornar
// o número de segundos decorridos desde 1970 ( não sei por quais motivos )
// mas é a forma perfeita de obter a semente do números aleatórios.

#include <thread>
// biblioteca de C++ que adiciona o objeto Thread, me permitindo controlar
// os diversos processos do meu programa, ele ainda vai rodar single thread,
// os projetos são mais simples, mas isso logo virá a calhar quando precisar
// manipular diversos threads para resolver algum problema.

#include <chrono>
// biblioteca de C++ que adiciona diversos tipos relacionados ao tempo
// (segundos, horas, e outras abstrações)

#include <algorithm>
// biblioteca de algoritmos úteis, como os de pesquisa, ordenação,
// transformação e etc.

using namespace std;
// como vou me limitar as funções providas pela stdlib,
// limitar o namespace ao std é uma boa para escrever mais
// facilmente o código.

// área das funções 
