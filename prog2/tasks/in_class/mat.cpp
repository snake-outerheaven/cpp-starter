
#include <iostream>
#include <string>
#include <vector>

int main(void)
{
    std::vector<std::vector<double>> mat{};

    std::string user_i{};

    std::cout << "Digite o tamanho da matriz: ";
    std::getline(std::cin, user_i);

    int lim = std::stoi(user_i);

    for (int i = 0; i < lim; i++)
    {
        mat.emplace_back();
        // cria uma linha vazia, e depois preenche cada elemento.
        for (int x = 0; x < lim; x++)
        {

            std::cout << "Digite o item [" << i + 1 << "] [" << x + 1 << "] da matriz: ";
            std::string user_input{};
            std::getline(std::cin, user_input);
            mat.back().push_back(std::stod(user_input));
        }
    }

    for (int i = 0; i < lim; i++)
    {
        std::cout << '\n';
        for (int x = 0; x < lim; x++)
            std::cout << '[' << mat[i][x] << "] ";
    }

    std::cout << '\n';

    double sum1{0};

    for (int i = 0; i < lim; i++)
        sum1 += mat[i][i];

    double sum2{0};

    for (int i = 0; i < lim; i++)
        for (int j = 0; j < lim; ++j)
            if ((i + j) == 2 - 1)
                sum2 += mat[i][j];

    double det = sum1 - sum2;

    std::cout << "O determinante da matriz é: " << det << ".\n";

    return 0;
}
