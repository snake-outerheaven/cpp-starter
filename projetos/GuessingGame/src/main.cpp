#include <iostream>
// biblioteca padrão para entrada e saida de dados no terminal
// o que eu mais vou usar: std::cin, std::cout e std::cerr

#include <iomanip>
// biblioteca essencial para manipulação de streams

#include <string>
// biblioteca que introduz o objeto String
// e diversos métodos úteis para facilitar
// o manejamento de texto.

#include <sstream>
// me permite tratar strings como arquivos.

#include <cstdlib>
// não há muito o que falar, este é um include essencial
// para usar funções da stdlib de C em C++, sendo essencial
// para poder usar rand, srand, system e outras funções.

#include <thread>
// biblioteca de C++ que adiciona o objeto Thread, me permitindo controlar
// os diversos processos do meu programa, ele ainda vai rodar single thread,
// pois os projetos são mais simples, mas isso logo virá a calhar quando
// precisar manipular diversos threads para resolver algum problema.

#include <chrono>
// biblioteca de C++ que adiciona diversos tipos relacionados ao tempo
// (segundos, horas, e outras abstrações)

#include <fstream>
// manipulação de arquivos: ofstream (escrita) e ifstream (leitura)

#include <filesystem>
// manipulação do sistema de arquivos: criar diretórios, listar arquivos...

#include <tuple>
// tuplas são grupos de variáveis de diferentes tipos sobre um nome,

#include <random>
// biblioteca com funções e tipos úteis sobre números aleatórios.

using namespace std;
// como vou me limitar as funções providas pela stdlib,
// limitar o namespace ao std é uma boa para escrever mais
// facilmente o código.

namespace fs = std::filesystem;
// setando um namespace para escrever menos.

// área das funções

// função que busca o máximo de portabilidade na limpeza do terminal
// através do uso de diretivas de pré processamento para determinar
// o sistema operacional no qual o sistema é utilizado

void clear(void) {
#ifdef _WIN32
  system("cls");
#elif __APPLE__
  system("clear");
#elif __linux__
  system("clear");
#else
  std::cout << "\033[2J\033[1;1H"; // saida de escape ANSI
                                   // para o máximo de
                                   // portabilidade.

#endif
}

// agora, uma função para facilitar a criação de pausas visuais
// para o usuário, para o código não rodar rápido demais, para
// maior controle, o tempo usado será em milissegundos

void dormir(int tempo) { this_thread::sleep_for(chrono::milliseconds(tempo)); }

// como este é um programa que vai sempre obter a entrada do usuário,
// este pode acabar digitando algo como "  meu nome de usuario    "
// o que gera a necessidade de uma "limpeza" de espaços vazios
// ao redor da string digitada, como em C++ não há algo que faz isso
// é necessário uma implementação manual antes de prosseguirmos.
// em C, eu estaria trabalhando com um char *string, mas em C++, a
// melhor forma de fazer isso é usar o tipo string, que possui vários
// métodos úteis.

string trim(const string &word) {
  // o parametro const string& indica que vou pegar somente
  // o que a variável passada como argumento tem, sem gerar cópias,
  // sei que não é a forma mais adequada para um iniciante, mas acho
  // melhor quebrar logo a cabeça para o conhecimento entrar.

  auto start = word.find_first_not_of(" \n\t\r\b");
  if (start == string::npos)
    return "";

  // certo, muita coisa aconteceu aqui agora, vamos para a documentação:
  //
  // o tipo auto, usado aqui, indica para o compilador determinar o tipo
  // automaticamente de acordo com o valor que a variável recebe, uma forma de
  // abstrair tipos não comuns.
  //
  // agora, o método find_first_not_of(" \n\t\r") procura o primeiro valor/es
  // que não está no argumento, retornando um número do tipo size_type, que é
  // usado para se referir a posições na string, aqui ele é usado para "ir
  // contando a posição dos caracteres até encontrar algum caractere que não
  // esteja na lista (o parametro do método)", acredito que isto seja legível e
  // fácil de entender.
  //
  // abaixo segue um exemplo mais claro do uso de métodos dessa familia, que
  // estão descritos no header string:
  //
  // // find
  // - Procura a primeira ocorrência de um caractere ou substring e retorna seu
  // índice; retorna npos se não encontrado. Exemplo: std::string s = "Neo";
  // auto pos = s.find('e'); // pos == 1
  //
  // find_first_of
  // - Retorna o índice do primeiro caractere que está presente na lista
  // fornecida; npos se nenhum for encontrado. Exemplo: std::string s = "Neo";
  // auto pos = s.find_first_of("aeiou"); // pos == 1 ('e')
  //
  // find_first_not_of
  // - Retorna o índice do primeiro caractere que não está na lista fornecida;
  // npos se todos pertencerem. Exemplo: std::string s = "   Neo"; auto pos =
  // s.find_first_not_of(" "); // pos == 3 ('N')
  //
  // find_last_of
  // - Retorna o índice do último caractere que está presente na lista
  // fornecida; npos se nenhum for encontrado. Exemplo: std::string s = "Neo";
  // auto pos = s.find_last_of("aeiou"); // pos == 1 ('e')
  //
  // find_last_not_of
  // - Retorna o índice do último caractere que não está na lista fornecida;
  // npos se todos pertencerem. Exemplo: std::string s = "Neo   "; auto pos =
  // s.find_last_not_of(" "); // pos == 2 ('o')
  //
  // o segundo if, usa um uma constante estática que é definida em string,
  // retornada pelos métodos de procura a seguir, que basicamente é o valor
  // retornado quanto o método não obtém êxito, a implementação de npos nesse
  // código serve para retornar uma string vazia, para não gerar problemas.

  // agora, sigamos para a parte que cuida do fim da string

  auto end = word.find_last_not_of(
      " \t\n\r\b"); // usa o método descrito acima para gerar o número de
                    // posições a serem rifadas na string

  return word.substr(start, end - start + 1);

  // substr: cria e retorna uma nova string que começa em 'start'
  // e tem tamanho 'end - start + 1' (+ 1 para incluir o caractere encontrado
  // pelo método, porque se não, o ultimo caracter válido seria rifado, o que
  // não é desejável)
}

// função responsável por obter o nome do usuário.
string obter_nome(void) {
  dormir(750);
  string resposta{};
  string nome{};

  while (true) {

    nome.clear();

    cout << "Este programa precisa do seu nome de usuário,"
         << " por favor, digite-o abaixo! \n"
         << endl;

    getline(cin, nome);
    nome = trim(nome);

    if (nome.empty()) {
      dormir(500);
      cout << "Nome vazio detectado!" << endl;
      cout << "Digite novamente: ";
      continue;

    } else {
      cout << endl;
      cout << "Voce confirma " << nome << " como seu nome de usuário? (s/n)"
           << endl;
      getline(cin, resposta);

      if (resposta == "s") {
        dormir(750);
        cout << "Certo! " << nome << " confirmado!" << endl;
        dormir(500);

        fs::path log_dir{"log"};
        fs::path log_file{log_dir / "game_log.txt"};

        if (!(fs::exists(log_file))) {
          dormir(750);
          cout << "Não foi possível verificar se este nome de usuário já foi "
                  "usado..."
               << endl;
          return nome;
        }

        ifstream log_read{log_file};
        string buscador{};
        unsigned int vezes{0};

        while (getline(log_read, buscador)) {
          buscador = trim(buscador);
          if (buscador.find(nome) != string::npos) {
            vezes++;
          }
        }

        if (vezes > 0) {
          cout << "Bem vindo novamente " << nome << ", você jogou este jogo "
               << vezes << "X." << endl;
        } else {
          cout << "Bem vindo novo jogador!" << endl;
        }

        return nome;

      } else if (resposta == "n") {
        dormir(550);
        cout << "Certo, aguarde para digitar o seu nome de usuário novamente..."
             << endl;
        clear();
        dormir(350);
        continue;
      } else {
        dormir(250);
        cout << "Por favor, digite s ou s! Reiniciando função por segurança..."
             << endl;
        dormir(400);
        clear();
        continue;
      }
    }
  }
}

// função que gera uma tupla de valores, que será desestrututrada na função
// principal.
tuple<unsigned int, unsigned int> game(string user) {
  mt19937_64 mt{static_cast<unsigned long long>(
      chrono::high_resolution_clock::now().time_since_epoch().count())};
  // gerador de "números aleatórios" usando Mersenne Twister
  // static cast<type> é a forma
  uniform_int_distribution<> roll{1, 100};
  // abstração para representar uma
  // distribuição de numeros de 1 a 100

  unsigned int rand_num = roll(mt);
  unsigned int tries{0};
  unsigned int guess_int{};
  string guess{};
  string resposta{};

  dormir(750);
  cout << "Certo " << user << ", vamos iniciar o jogo." << endl;

  while (true) {
    tries++;
    guess.clear();
    cout << "O número secreto está entre 1 a 100" << endl;
    cout << "Por favor, " << user << ", digite o seu palpite.\n: ";
    getline(cin, guess);
    guess = trim(guess);
    dormir(750);
    try {
      cout << "Interpretando número..." << endl;
      dormir(750);
      guess_int = stoi(guess);
    } catch (...) {
      cout << "Oops, digite um número entre 1 e 100 " << user << "." << endl;
      clear();
      continue;
    }
    if (guess_int == rand_num) {
      cout << "Parabéns, voce descobriu o número secreto com " << tries
           << " tentativas." << endl;
      return make_tuple(rand_num, tries);
    } else if (guess_int < rand_num && guess_int >= 1) {
      cout << guess_int << " é menor que o número secreto!" << endl;
      dormir(750);
      continue;
    } else if (guess_int > rand_num && guess_int <= 100) {
      cout << guess_int << " é maior que o número secreto!" << endl;
      dormir(750);
      continue;
    } else {
      cout << "Número fora do intervalo!" << endl;
      dormir(250);
      continue;
    }
  }
}

// função que busca salvar o progresso do jogador
void save(const string &user, unsigned int &a, unsigned int &b) {
  cout << "Iniciando função de salvamento..." << endl;
  dormir(1250);

  fs::path log_dir{"log"};

  if (!fs::exists(log_dir)) {
    try {
      cout << "Pasta de logs não localizada! Criando uma nova..." << endl;
      dormir(750);
      fs::create_directory(log_dir);
    } catch (...) {
      dormir(750);
      cout << "Não foi possível criar a pasta de logs, veja suas permissões no "
              "sistema."
           << endl;
      return;
    }
  }

  fs::path log_txt{log_dir /
                   "game_log.txt"}; // funciona multiplataforma, mas no código é
                                    // escrito como se fosse em um sistema UNIX

  ostringstream log_flow{}; // inicialização segura

  auto now = chrono::system_clock::now();

  auto time = chrono::system_clock::to_time_t(now);

  log_flow << "Data do registro: "
           << put_time(localtime(&time), "%d/%m/%Y - %H:%M:%S") << "\n"
           << "Nome de usuário: " << user << " | Número secreto: " << a
           << " | Número de tentativas: " << b << "\n";

  string log_string = log_flow.str();

  ofstream log_file(log_txt, ios::app);

  try {
    dormir(750);
    log_file << log_string;
    dormir(500);
    log_file.close();
    cout << "Dados salvos!" << endl;
  } catch (...) {
    cout << "Não foi possível salvar por algum motivo..." << endl;
    dormir(250);
    cout << "Encerrando..." << endl;
    dormir(500);
    return;
  }

  dormir(400);
  cout << "Exibindo ultimas partidas:" << endl;
  ifstream log_outp(log_txt);
  string leitor{}; // inicialização segura
  while (getline(log_outp, leitor)) {
    cout << leitor << endl;
  }
  log_outp.close();
}

int main() {
  clear();
  cout << "Bem vindo ao jogo da adivinhação! Vamos jogar!" << endl;
  string user = obter_nome();
  dormir(750);
  auto [rand_num, tries] =
      game(user); // forma recomendada de desmontar uma tupla.
  save(user, rand_num, tries);
  return 0;
}
