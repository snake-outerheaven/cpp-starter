#include <string>
#include <vector>
#include "produto.hpp"
#include "cantina.hpp"

int Cantina::isearch(int id)
{

    int i{0};
    for (auto prod : this->prods)
    {
        if (prod.getCod() == id)
            return i;

        i++;
    }

    return -1;
}

Cantina::Cantina()
{
    this->caixa = 0;
}

bool Cantina::cadastrarProduto(int cod, std::string &nm, double pr)
{

    if (this->prods.at(this->isearch(cod)).getCod() == cod || nm.empty()
		    || cod <= 0 || pr <= 0.0)
        return false;

    Produto prod(cod, nm, pr);
    prods.insert(prod);

    return false;
}

void Cantina::listarProdutos() const {

	for(auto prod : this->prods)
		prod.exibir();
}
