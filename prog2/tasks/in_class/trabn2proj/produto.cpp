#include "produto.hpp"
#include <iomanip>
#include <iostream>
#include <string>

Produto::Produto(int cod, std::string &nm, double price)
{

    this->cod = cod;
    this->nome = nm;
    this->price = price;
    this->quant = 0;
}

int Produto::getCod(void) const
{
    return this->cod;
}

std::string Produto::getNome(void) const
{
    return this->nome;
}

double Produto::getPreco() const
{
    return this->price;
}

int Produto::getQuant() const
{
    return this->quant;
}

bool Produto::setPreco(double prec)
{
    if (prec > 0.0)
    {
        this->price = prec;
        return true;
    }

    return false;
}

bool Produto::addEstoque(int qtd)
{

    if (qtd >= 0)
    {
        this->quant += qtd;
        return true;
    }

    return false;
}

bool Produto::remEstoque(int qtd)
{

    if (qtd >= 0)
    {
        if ((this->quant - qtd) < 0)
            return false;

        this->quant -= qtd;
        return true;
    }

    return false;
}

void Produto::exibir(void)
{

    std::cout << std::setprecision(2) << std::fixed;

    std::cout << '[' << this->cod << ']' << ' ' << this->nome << ' ' << "| R$ " << this->price << " | " << this->quant
              << " un.\n";
}
