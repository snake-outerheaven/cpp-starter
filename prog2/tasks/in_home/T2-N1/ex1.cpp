// ler notas de alunos usando um vetor alocado dinamicamente na memória

// Pergunta teórica: Responda por que não podemos declarar `double notas[n]`
// quando $n$ é lido em tempo de execução e compare as regiões de memória (stack
// vs. heap).

// resposta: C++ não permite vetores estáticos estilo C com tamanho variádico,
// isto é, sendo inicializado com uma variável cujo valor é determinado em tempo
// de execução, a memória stack é estática. só podemos usar ponteiros tipados
// (ou não) para a memória dinâmica, a heap.

#include <chrono>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <thread>

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
void setConsole(void) {
  SetConsoleCP(CP_UTF8);
  SetConsoleOutputCP(CP_UTF8);
}
#endif

constexpr auto STD_WAIT = 750;

constexpr auto MIN_GRADE = 0.0;
constexpr auto MAX_GRADE = 10.0;

void waitMillis(unsigned int);

void bubbleSort(double *, int);

void printVec(double *, int);

int main(void) {

#ifdef _WIN32
  setConsole();
#endif
  double *notas{nullptr}, menor{}, maior{};
  double media{}, sum{0};
  int siz{};
  std::string user_input{};
  std::stringstream s{};

  s.exceptions(std::ios::failbit | std::ios::badbit);

  // loop de eventos do programa

  while (1) {
    try {
      free(notas); // free nullptr não dá nada
      notas = nullptr; // evitar dangling pointer
      s.clear();
      user_input.clear();
      std::cout << "Digite o total de notas a serem registrados por este "
                   "programa\nDigite \"sair\" para sair\n> ";
      std::getline(std::cin, user_input);

      if (user_input == "sair")
        return 0;

      s.str(user_input);

      s >> siz;

      if (siz <= 0)
        throw std::domain_error(
            "Não existem listas de notas com tamanho 0 ou negativo.");
      else if (siz >= 40)
        throw std::domain_error("A turma não pode ser maior que 40 pessoas!");

      std::cout << "Tamanho da lista lido: " << siz
                << ".\nTem certeza?(s/n)\n> ";
      std::getline(std::cin, user_input);

      if (user_input == "n") {
        std::cout << "Ok, reiniciando...";
        waitMillis(STD_WAIT);
        continue;
      }

      notas = static_cast<double *>(calloc(siz, sizeof(double)));

      if (notas == nullptr)
        throw std::runtime_error(
            "Falha ao alocar memória para o cálculo das notas");

      // eu acho que não vou colocar try catch aqui aninhado, porque isso vai
      // muito além do escopo da aula, aqui é só pra provar um conhecimento
      // básico da stdlib do C++
      for (int i = 0; i < siz; i++)
        while (1) {
          std::cout << "Digite a " << i + 1 << " ª nota\n> ";
          std::getline(std::cin, user_input);
          s.clear();
          s.str(user_input);
          s >> notas[i]; // se levantar exceção aqui, o usuário volta pro começo
                         // de tudo
          // kkkkkkkkkkkkkkkkkkkkkkkkkkk

          if (notas[i] < MIN_GRADE || notas[i] > MAX_GRADE)
            continue;

          if (notas[i] != 0.0)
            break;
        }

      // depois daqui, o vetor deve estar preenchido corretamente.

      std::cout << "Notas lidas: \n";
      printVec(notas, siz);
      std::cout << "Organizando as notas...";
      bubbleSort(notas, siz);
      waitMillis(2000);
      std::cout << "Notas organizadas: \n";
      printVec(notas, siz);

      for (int i = 0; i < siz; i++)
        sum += *(notas + i);

      media = sum / siz;

      menor = notas[0];
      maior = notas[siz - 1];

      std::cout << "A menor notas é : " << menor
                << " e a maior notas é: " << maior << ".\n";

      std::cout << "A média das notas é: " << media << '\n';

      free(notas);
      notas = nullptr;
      std::cout << "Deseja fazer mais registros? (s/n)\n> ";
      std::getline(std::cin, user_input);

      if (user_input == "n")
        return 0;
    }

    catch (const std::exception &e) {
      std::cerr << "Exceção jogada: " << e.what() << '\n';
      continue;
    }
  }

  return 0;
}

void waitMillis(unsigned int millis) {
  std::this_thread::sleep_for(std::chrono::milliseconds(millis));
}

void bubbleSort(double *ptr, int siz) {
  double temp{};

  for (int i = 1; i < siz; i++)
    for (int x = siz - 1; x >= i; x--)
      if (ptr[x] < ptr[x - 1]) // ..i.....x if x > i, swap po, ai fui muleke
                               // kkkkkkkkkkkkkkkkkkkkkkkkkkkkk
      {
        temp = ptr[x-1];
        ptr[x-1] = ptr[x];
        ptr[x] = temp;
      }
}

void printVec(double *ptr, int siz) {
  for (int i = 0; i < siz; i++)
    std::cout << *(ptr + i) << '\n';
}

// podia ter deixado vector para poder usar iteradores, mas bora de alocação
// dinamica manual hehe, vou ter que reiventar isso tb

// eu vou reescrever como void, porque a alternativa seria criar um cronometro e
// retornar se a espera realmente rolou
