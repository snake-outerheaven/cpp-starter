#include "produto.hpp"
#include "cantina.hpp"

int main(void)
{
    std::string s("pizza");

    Produto prod1(1, s, 57.25);

    prod1.addEstoque(2);

    prod1.exibir();
	
    Cantina cant;

    cant.cadastrarProduto(1, s, 57.25);

    cant.listarProdutos();

    return 0;
}
