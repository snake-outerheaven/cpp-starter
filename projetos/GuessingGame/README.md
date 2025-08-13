# GuessingGame

Apenas um jogo simples para eu aprender um pouco mais sobre como me expressar em C++


## Objetivo

O jogo, além de ser o clássico loop que vai receber uma entrada do jogador até ela for igual, com mensagens
que indicam o quão perto ele está de encontrar, também pretende dar uma melhorada na UX com pausas para
dar a impressão de um fluxo mais suave, pretende registrar o nome do usuário, o número secreto sorteado e
o número de tentativas até acertar o número em um arquivo de texto, além da exibição de tentativas anteriores.

Tambem será feito uso de um Makefile para automatzação da geração de executáveis e limpeza da pasta bin, que
será utilizada para limpar os executáveis ( por enquanto apenas presente em sistemas linux )

## Estrutura
- `bin/`: aqui contém os arquivos objetos e demais arquivos gerados pelo processo de compilação.
- `src/`: aqui contém o código fonte (main.cpp)
- `include/`: conterá os headers públicos, contendo os protótipos das funções (lib1.hpp,lib2.hpp).
- `libs/`: conterá as implementações dos headers (lib1.cpp,lib2.cpp,lib3.cpp)
- `Makefile`: script que cuida da criação da compilação, execução e limpeza do diretório do projeto.

## Como compilar

Em um sistema Linux, após rodar make para rodar a parte da compilação do projeto, há dois outros comandos
que podem ser executados:

**1º**
```
  make run
```

*Este executará o código.*


**2º**
```
  make clean
```
*Este limpara o projeto dos arquivos compilados.*

## Exemplos de uso

***Em construção***

## Notas de implementação

***Em construção, mas uma das ideias é fazer o código dizer "Seja bem vindo novamente, nome_do_usuario"
ao usuário que digitar um nome presente no arquivo de texto***

