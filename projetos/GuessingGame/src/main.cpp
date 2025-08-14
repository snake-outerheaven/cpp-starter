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
// pois os projetos são mais simples, mas isso logo virá a calhar quando precisar
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

// função que busca o máximo de portabilidade na limpeza do terminal
// através do uso de diretivas de pré processamento para determinar
// o sistema operacional no qual o sistema é utilizado

void limparTela (void) {
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

void dormir (int tempo) {
    this_thread::sleep_for(chrono::milliseconds(tempo));
}

// como este é um programa que vai sempre obter a entrada do usuário,
// este pode acabar digitando algo como "  meu nome de usuario    "
// o que gera a necessidade de uma "limpeza" de espaços vazios
// ao redor da string digitada, como em C++ não há algo que faz isso
// é necessário uma implementação manual antes de prosseguirmos.
// em C, eu estaria trabalhando com um char *string, mas em C++, a
// melhor forma de fazer isso é usar o tipo string, que possui vários
// métodos úteis.

string trim (const string& word ) {
    // o parametro const string& indica que vou pegar somente
    // o que a variável passada como argumento tem, sem gerar cópias,
    // sei que não é a forma mais adequada para um iniciante, mas acho
    // melhor quebrar logo a cabeça para o conhecimento entrar.

    const auto start = word.find_first_not_of(" \n\t\r");
    if (start == string::npos) return "";

    // certo, muita coisa aconteceu aqui agora, vamos para a documentação:
    //
    // o tipo auto, usado aqui, indica para o compilador determinar o tipo automaticamente
    // de acordo com o valor que a variável recebe, uma forma de abstrair tipos não comuns.
    //
    // agora, o método find_first_not_of(" \n\t\r") procura o primeiro valor/es que não está
    // no argumento, retornando um número do tipo size_type, que é usado para se referir a
    // posições na string, aqui ele é usado para "ir contando a posição dos caracteres até encontrar
    // algum caractere que não esteja na lista (o parametro do método)", acredito que isto seja legível
    // e fácil de entender.
    //
    // abaixo segue um exemplo mais claro do uso de métodos dessa familia, que estão
    // descritos no header string:
    //
    // // find
    // - Procura a primeira ocorrência de um caractere ou substring e retorna seu índice; retorna npos se não encontrado.
    // Exemplo:
    // std::string s = "Neo"; auto pos = s.find('e'); // pos == 1
    //
    // find_first_of
    // - Retorna o índice do primeiro caractere que está presente na lista fornecida; npos se nenhum for encontrado.
    // Exemplo:
    // std::string s = "Neo"; auto pos = s.find_first_of("aeiou"); // pos == 1 ('e')
    //
    // find_first_not_of
    // - Retorna o índice do primeiro caractere que não está na lista fornecida; npos se todos pertencerem.
    // Exemplo:
    // std::string s = "   Neo"; auto pos = s.find_first_not_of(" "); // pos == 3 ('N')
    //
    // find_last_of
    // - Retorna o índice do último caractere que está presente na lista fornecida; npos se nenhum for encontrado.
    // Exemplo:
    // std::string s = "Neo"; auto pos = s.find_last_of("aeiou"); // pos == 1 ('e')
    //
    // find_last_not_of
    // - Retorna o índice do último caractere que não está na lista fornecida; npos se todos pertencerem.
    // Exemplo:
    // std::string s = "Neo   "; auto pos = s.find_last_not_of(" "); // pos == 2 ('o')
    //
    // o segundo if, usa um uma constante estática que é definida em string, retornada
    // pelos métodos de procura a seguir, que basicamente é o valor retornado quanto o
    // método não obtém êxito, a implementação de npos nesse código serve para retornar
    // uma string vazia, para não gerar problemas.

    // agora, sigamos para a parte que cuida do fim da string

    auto end = word.find_last_not_of(" \t\n\r"); // usa o método descrito acima para gerar o número de posições
                                                 // a serem rifadas na string

    return word.substr(start,end - start + 1);

    // substr: cria e retorna uma nova string que começa em 'start'
    // e tem tamanho 'end - start + 1' (+ 1 para incluir o caractere encontrado pelo método, porque se não,
    // o ultimo caracter válido seria rifado, o que não é desejável)
}
