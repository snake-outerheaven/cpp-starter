# cpp-starter

[![C++](https://img.shields.io/badge/C%2B%2B-17-00599C?logo=cplusplus&logoColor=white)](https://en.cppreference.com/w/cpp/17)
[![Estilo: Allman](https://img.shields.io/badge/estilo-clang--format%20(Allman)-blue)](.clang-format)
[![Licença: MIT](https://img.shields.io/badge/licen%C3%A7a-MIT-yellow.svg)](LICENSE)

Exercícios, trabalhos acadêmicos e pequenos projetos do estudo de C++ com o
*C++ Primer* (5ª ed.) e da disciplina de *Programação de Computadores 2*.

## Sumário

- [Contexto](#contexto)
- [Requisitos](#requisitos)
- [Compilação](#compilação)
- [Estrutura do repositório](#estrutura-do-repositório)
- [Padrão de código](#padrão-de-código)
- [Contribuição](#contribuição)
- [Contato](#contato)
- [Licença](#licença)

## Contexto

Este repositório é um registro de estudos. Cada arquivo-fonte é um programa
independente, salvo indicação em contrário. Não há biblioteca compartilhada nem
sistema de build global.

| Origem | Escopo |
|---|---|
| *C++ Primer*, 5ª ed. (Lippman, Lajoie & Moo) | Exercícios do livro, em `primer/` |
| Programação de Computadores 2 (Sistemas de Informação, FEMASS) | Trabalhos de aula e de casa, em `prog2/` ([detalhes](prog2/README.md)) |
| Pessoal | Programas avulsos, em `projects/` |

## Requisitos

| Componente | Mínimo | Testado com |
|---|---|---|
| Compilador | Qualquer compilador C++17 | GCC, Clang, MSVC 19.5x |
| Plataforma | POSIX ou Windows | Debian 13, OpenBSD, Windows 11 |
| Opcional | Boost (algoritmos de string) | Só `projects/guessing-game` |
| Opcional | clang-format | Para formatação, ver [Padrão de código](#padrão-de-código) |

## Compilação

Cada `.cpp` compila sozinho:

```sh
# GCC / Clang (Linux, BSD, macOS)
c++ -std=c++17 -Wall -Wextra -O2 caminho/do/arquivo.cpp -o prog
./prog
```

```powershell
# MSVC (Developer Command Prompt)
cl /std:c++17 /W4 /EHsc caminho\do\arquivo.cpp
.\arquivo.exe
```

Programas com vários arquivos precisam de todas as unidades de tradução:

```sh
cd prog2/tasks/in_class/trabn2proj
c++ -std=c++17 -Wall -Wextra main.cpp produto.cpp -o produto
```

## Estrutura do repositório

```text
.
├── primer/
│   └── ch01/            Exercícios do capítulo 1 do C++ Primer
├── prog2/
│   └── tasks/
│       ├── in_class/    Trabalhos feitos em aula
│       │   └── trabn2proj/   Trabalho da N2 em dupla (classe Produto)
│       └── in_home/     Trabalhos de casa
├── projects/
│   ├── guessing-game/
│   ├── hello/
│   ├── linkedlist/
│   └── unicode/
├── .clang-format
├── LICENSE
└── README.md
```

## Padrão de código

A formatação está definida no [`.clang-format`](.clang-format): chaves no
estilo Allman, indentação de 4 espaços e limite de 120 colunas. Formate antes
de commitar:

```sh
git ls-files '*.cpp' '*.hpp' '*.c' '*.h' | xargs clang-format -i
```

Commits que só mudam a formatação usam o prefixo `style:` e não contêm
alterações de comportamento.

## Contribuição

Este é um repositório pessoal de estudos. Issues apontando erros ou sugerindo
soluções alternativas são bem-vindas. Pull requests devem seguir o
[Padrão de código](#padrão-de-código) e tratar um assunto por commit.

## Contato

Dúvidas, sugestões ou discussões sobre C++: <https://github.com/snake-outerheaven>

## Licença

[MIT](LICENSE) © snake-outerheaven

---

Feito com foco, disciplina e prática deliberada.
