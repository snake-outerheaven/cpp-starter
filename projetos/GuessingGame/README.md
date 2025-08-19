# GuessingGame

Apenas um jogo simples para eu aprender um pouco mais sobre como me expressar em C++


## Objetivo

O jogo, além de ser o clássico loop que vai receber uma entrada do jogador até ela for igual, com mensagens
que indicam o quão perto ele está de encontrar, também pretende dar uma melhorada na UX com pausas para
dar a impressão de um fluxo mais suave, pretende registrar o nome do usuário, o número secreto sorteado e
o número de tentativas até acertar o número em um arquivo de texto, além da exibição de rodadas anteriores.

## Estrutura
- `bin/`: aqui contém os arquivos objetos e demais arquivos gerados pelo processo de compilação.
- `build`: arquivos objetos estão aqui
- `src/`: aqui conterá os arquivos fonte do projeto.
- `include/`: conterá os headers públicos, contendo os protótipos das funções (lib1.hpp,lib2.hpp). *caso seja necessário*
- `libs/`: conterá as implementações dos headers (lib1.cpp,lib2.cpp,lib3.cpp) *caso seja necessário*
- `Makefile`: script que cuida da criação da compilação, execução e limpeza do diretório do projeto.

## Como compilar

Em um sistema Linux, após executar o comando make para gerar os objetos e executáveis do projeto, há dois outros comandos
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

Versão 1.0, ainda em CLI
Bem vindo ao jogo da adivinhação! Vamos jogar!
Este programa precisa do seu nome de usuário, por favor, digite-o abaixo! 

Mako    

Voce confirma Mako como seu nome de usuário? (s/n)
s
Certo! Mako confirmado!
Bem vindo novamente Mako, você jogou este jogo 2X.
Certo Mako, vamos iniciar o jogo.
O número secreto está entre 1 a 100
Por favor, Mako, digite o seu palpite.
: 77
Interpretando número...
77 é menor que o número secreto!
O número secreto está entre 1 a 100
Por favor, Mako, digite o seu palpite.
: 80
Interpretando número...
80 é maior que o número secreto!
O número secreto está entre 1 a 100
Por favor, Mako, digite o seu palpite.
: 78
Interpretando número...
Parabéns, voce descobriu o número secreto com 3 tentativas.
Iniciando função de salvamento...
Dados salvos!
Exibindo ultimas partidas:
Data do registro: 19/08/2025 - 03:35:18
Nome de usuário: neneo | Número secreto: 93 | Número de tentativas: 6
Data do registro: 19/08/2025 - 11:13:00
Nome de usuário: Mako | Número secreto: 86 | Número de tentativas: 10
Data do registro: 19/08/2025 - 12:03:20
Nome de usuário: Mako | Número secreto: 14 | Número de tentativas: 13
Data do registro: 19/08/2025 - 12:33:46
Nome de usuário: Mako | Número secreto: 78 | Número de tentativas: 3


## Notas de implementação

***Em construção, mas uma das ideias é fazer o código dizer "Seja bem vindo novamente, nome_do_usuario"
ao usuário que digitar um nome presente no arquivo de texto (Concluído)***

***Talvez seja relevante reescrever este jogo em modelo OOP para experimentar algo novo, e também usar o framework
QT para o jogo subir da CLI para o mundo gŕafico***

