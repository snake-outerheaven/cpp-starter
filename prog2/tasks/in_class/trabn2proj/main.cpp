#include <cstdio>
#include "produto.hpp"

int main(void)
{
	std::string s("pizza");

	Produto prod1(1, s, 57.25);

	prod1.addEstoque(2);

	prod1.exibir();

	return 0;
}
	
