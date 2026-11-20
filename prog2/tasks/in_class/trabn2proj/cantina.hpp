#ifndef CANTINA_H
#define CANTINA_H
#include "produto.hpp"
#include <string>
#include <vector>

class Cantina
{

  private:
    std::vector<Produto> prods;
    double caixa;

    int isearch(int);

  public:
    Cantina();

    bool cadastrarProduto(int, std::string &, double);
    bool repor(int, int);
    bool vender(int, int);
    double alterarPreco(int, double);
    void listarProdutos() const;
    double getCaixa() const;
};

#endif
