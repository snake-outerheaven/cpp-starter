#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Produto {

	private:
		
		int cod;
		std::string nome;
		double price;
		int quant;

	public:

		Produto(int, std::string&, double);

		int getCod(void) const;
		std::string getNome() const;
		double getPreco() const;
		int getQuant(int) const;
		bool setPreco(double);
		bool addEstoque(int);
		bool remEstoque(int);
		void exibir(void);
};

#endif
