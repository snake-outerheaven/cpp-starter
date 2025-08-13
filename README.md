# cpp-starter

> Repositório voltado para estudos.

Um espaço organizado para registrar a evolução em **C++**: exercícios, pequenos experimentos, protótipos educacionais e bibliotecas didáticas — sempre com foco em **aprender**, **praticar** e **documentar**.

---

## Resumo

Este repositório existe para estudar C++ na prática: implementar ideias, explorar a linguagem, testar algoritmos e registrar o raciocínio de forma transparente. Não é voltado a aplicações para uso final.

---

## Estrutura do repositório

```
cpp-starter/
├── projetos/
│   ├── <nome-do-projeto>/
│   │   ├── README.md   # objetivo, contexto e instruções do projeto
│   │   ├── src/        # código-fonte (.cpp/.hpp)
│   │   └── include/    # headers públicos (.hpp/.h) — interfaces do projeto
├── libs/               # bibliotecas e utilitários reutilizáveis
├── LICENSE             # MIT
└── README.md           # este arquivo
```

> Observação: não versionar binários nem artefatos de build.

---

## Regras do repositório

- Cada projeto vive em `projetos/<nome-do-projeto>/` e **deve** ter um `README.md` explicando objetivo, como compilar e notas de implementação.
- Código reutilizável vai em `libs/`, com documentação mínima e exemplos curtos de uso.
- Licença: **MIT**.
- Prefira **commits pequenos** com mensagens claras e objetivas.
- Sempre crie uma **branch** específica para cada alteração ou contribuição.
- Use **Issues** para sugerir melhorias, relatar bugs e discutir ideias.
- Mantenha a clareza e a consistência dos arquivos de documentação.

---

## Como começar

Pré-requisitos sugeridos:
- Compilador C++ moderno (g++ ou clang, com C++20 recomendado).

Exemplo mínimo de compilação local:

```
# dentro de projetos/<nome-do-projeto>/
g++ -std=c++20 -O2 src/main.cpp -Iinclude -o <nome-do-projeto>
./<nome-do-projeto>
```

Para múltiplos arquivos:

```
g++ -std=c++20 -O2 src/main.cpp src/outro.cpp -Iinclude -o <nome-do-projeto>
```

---

## Template para `projetos/<nome>/README.md`

```
# Nome do Projeto

Descrição curta (1–2 linhas) — objetivo educacional do projeto.

## Objetivo
Explique o que você pretende aprender ou demonstrar com este projeto.

## Estrutura
- `src/`: código-fonte (.cpp/.hpp)
- `include/`: headers públicos — interfaces expostas (.hpp/.h)
- `libs/` (se usado): utilitários/bibliotecas locais

## Como compilar
g++ -std=c++20 -O2 src/main.cpp -Iinclude -o <nome-do-projeto>
./<nome-do-projeto>

## Exemplos de uso
Mostre entradas e saídas esperadas, trechos de execução e comentários.

## Notas de implementação
Explique decisões de design, limitações e próximos passos.

## Licença
MIT — veja `../../LICENSE`.
```

---

## Como contribuir

1. Abra uma **Issue** para discutir a ideia brevemente.  
2. Faça **fork** do repositório e **clone** seu fork:
```
git clone https://github.com/SEU_USUARIO/cpp-starter.git
```
3. Crie uma branch específica:
```
git checkout -b feat/nome-da-funcionalidade
```
4. Faça alterações com commits pequenos e descritivos:
```
git add .
git commit -m "feat: descrição curta do que foi feito"
git push origin feat/nome-da-funcionalidade
```
5. Abra um **Pull Request** explicando **o que** mudou e **por quê**, com instruções de como validar.

---

## Convenções e boas práticas

- Organize o código em `src/` e interfaces públicas em `include/`.
- Nomeie arquivos, funções e classes de forma clara e consistente.
- Comente com foco didático: explique **por que** algo foi feito.
- Inclua exemplos de entrada/saída nos READMEs dos projetos.
- Use `.gitignore` para evitar versionar objetos e arquivos de IDE (`*.o`, `.vscode/`, `.idea/`, etc.).
- Prefira soluções portáveis quando possível.

---

## Licença e isenção

- **Licença:** MIT (veja `LICENSE` na raiz).
- **Isenção de responsabilidade:** o software aqui é fornecido **“no estado em que se encontra”**, **sem qualquer garantia**, explícita ou implícita.

---
