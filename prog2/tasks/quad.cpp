/*
  Crie em C++ um programa que solicite ao usuário os coeficientes a, b e c
  (tipo double) de uma equação de segundo grau e depois imprima o delta, x,
  x2 (raizes reais)
*/

#define WIN32_LEAN_AND_MEAN // define especial para cortar partes da API do
                            // Windows que são extras, a doc é mt grande, só vi
                            // o básico para controlar o code page do terminal,
                            // pois há o legado do DOS da pagina 850, que força
                            // para o latim (code page 850)

#include <chrono> // biblioteca de tempo da biblioteca padrão
#include <cmath> // biblioteca de funções matemáticas do C, que pode ser usada no C++
#include <complex> // habilita os recursos para números complexos da biblioteca padrão
#include <iomanip>  // manipulação de i/o
#include <iostream> // biblioteca de fluxos (tipo importante de objeto que usa operador >> <<) que lida com entrada e saída de dados
#include <sstream> // objeto mais genérico de fluxo, permite um parsing mais avançado
#include <stdexcept> // habilita o controle fino de exceções da biblioteca padrão
#include <string> // classe da biblioteca padrão que gerencia um vetor dinâmico de caracteres.
#include <thread> // manipulação de processos da biblioteca padrão

#ifdef _WIN32 // diretiva de pré processamento para compilação condicional
#include <windows.h> // adiciona API do Windows para controle de baixo nível do subsistema do console
#endif

#define MAX_WAIT 7.5e2 // define a pausa máxima para wait function.

std::string
lower (const std::string &); // protótipo de função que retorna uma string com
                             // todos os caracteres minúsculos
void wait (double); // wrapper que envolve uma chamada de uma função mais chata
                    // de escrever para pausar o processo principal.

int
main (void)
{
  double a{}, b{}, c{}, d{};
  std::complex<double> x1{}, x2{};

  std::string user_input{};

#ifdef _WIN32
  SetConsoleCP (CP_UTF8);
  SetConsoleOutputCP (CP_UTF8);
#endif

  // declaração moderna de variáveis, inicializadas de forma segura, ao
  // invés do modelo c antigo que continha lixo.

  while (1)
    {
      user_input.clear (); // trunca o buffer dinâmico para permitir o reset
                           // do buffer de entrada do usuário, em C, seria
                           // user_input[0] = '\0';

      std::cout << "a, b, c? ";

      std::getline (std::cin, user_input); // leio até \n do std::cin, fluxo
                                           // de entrada em CLI do programa.

      if (lower (user_input) == "sair")
        {
          std::string exit_prompt{ "Saindo" };
          int loop{ 0 };
          while (loop < 4)
            {
              std::cout << '\r' << exit_prompt << std::flush;
              exit_prompt += '.';
              wait (MAX_WAIT);
              loop++;
            }

          break;
        }

      try
        {
          std::stringstream s (user_input); // instancio um fluxo baseado em
                                            // cima do input do usuário
          s.exceptions (
              std::ios::failbit
              | std::ios::badbit); // ativo exceções, desmascarando bits
                                   // específicos do buffer de conversão

          s >> a >> b >> c; // uso o operador >> do fluxo para ir preenchendo
                            // as variáveis, aqui sobe exeção de falhar.

          if (a == 0)
            throw std::runtime_error ("Não é possível montar uma equação do "
                                      "segundo grau com a = 0.");
        }
      catch (const std::exception &e)
        {
          std::cerr << "Erro em seção crítica do código: " << e.what ()
                    << '\n';
          continue;
        }

      // o uso de tratamento de exceções é essencial até para compreender
      // formas modernas de tratamentos de erros na engenharia de software
      // moderna, já se foram os tempos de verificar o código de erro (se é 1
      // se é 2, se é 3), agora é o tipo de exceção que importa.

      d = b * b - 4 * a * c;

      if (d < 0)
        {
          double real = -b / (2.0 * a); // gero o componente real das raizes
          double imag
              = std::sqrt (-d) / (2.0 * a); // gero o componente imaginário
          x1 = std::complex<double> (
              real, imag); // instancio a classe que representa um número
                           // complexo pro x1
          x2 = std::complex<double> (real, -imag); // o mesmo pro x2.
          std::cout << "\n\tdelta = " << d << "\n\tx1= " << x1
                    << "\n\tx2= " << x2 << std::endl;
          // o número complexo é formatado da seguinte maneira
          // (x real, y imaginário)
          // seria possível desenvolver eventualmente um modelo gráfico da
          // equação, usando alguma biblioteca de gráficos, mas isso é pra
          // depois
          break;
        }
      if (d == 0)
        {
          std::cout << "Como d é zero, só há uma raíz real\n";
          x1 = (-b) / (2.0 * a);
          std::cout << "\n\tx = " << x1 << ".\n";
          break;
        }
      if (d > 0)
        {
          std::cout << "Como d é maior que zero, existem duas raízes reais.\n";
          x1 = (-b + std::sqrt (d)) / (2.0 * a);
          x2 = (-b - std::sqrt (d)) / (2.0 * a);
          std::cout << "\n\tdelta = " << d << "\n\tx1= " << x1
                    << "\n\tx2= " << x2 << std::endl;
          break;
        }
    }

  return 0;
}

std::string
lower (const std::string &ref)
{
  std::string prod;

  for (char c : ref)
    prod += (char) std::tolower (c);

  return prod;
}

void
wait (double ms)
{
  std::this_thread::sleep_for (std::chrono::duration<double, std::milli> (ms));
}

/*
 * Coisas a melhorar no código:
 *
 * - Testes do delta;
 * - Validar a resposta do usuário;
 * - Criar loop de eventos do programa
 * - Adicionar persistência no programa <- TODO
 *
 * -> A tarefa é criar um programa mais robusto e com mais features
 */
