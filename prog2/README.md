# prog2

Trabalhos da disciplina de **Programação de Computadores 2**, do curso de
Sistemas de Informação da FEMASS.

## Sumário

- [Estrutura](#estrutura)
- [Compilação](#compilação)
- [Trabalhos](#trabalhos)

## Estrutura

```text
prog2/
└── tasks/
    ├── in_class/        Trabalhos feitos em aula
    │   └── trabn2proj/  Trabalho da N2 em dupla
    └── in_home/         Trabalhos de casa
```

## Compilação

Os arquivos de `in_class/` e `in_home/` compilam individualmente:

```sh
c++ -std=c++17 -Wall -Wextra tasks/in_class/quad.cpp -o quad
```

O `trabn2proj` tem várias unidades de tradução:

```sh
cd tasks/in_class/trabn2proj
c++ -std=c++17 -Wall -Wextra main.cpp produto.cpp -o produto
```

Requisitos e padrão de código estão no [README principal](../README.md).

## Trabalhos

| Caminho | Tipo | Conteúdo |
|---|---|---|
| `tasks/in_class/quad.cpp` | Aula | Equação do 2º grau com raízes reais e complexas |
| `tasks/in_class/trabn2proj/` | Aula, N2, dupla | Classe `Produto` (código, nome, preço e estoque) |
| `tasks/in_class/*.cpp` | Aula | Demais exercícios de aula |
| `tasks/in_home/*.cpp` | Casa | Exercícios para casa |
