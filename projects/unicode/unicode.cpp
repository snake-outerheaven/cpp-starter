#include <iostream>
#include <locale>
#include <string>

#ifdef _WIN32
#include <windows.h>
void consoleSetup()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
}
#endif

using string = std::string;

int main()
{
#ifdef _WIN32
    consoleSetup();
#endif

    std::locale::global(std::locale(".utf8"));
    std::cout.imbue(std::locale(".utf8"));

    std::cout << u8"Olá, mundo! 你好，世界！ 😀\n";

    string utf8string = u8"\U0001F4CE says: \"Hello, World!\" \U0001F603 \U0001F609";

    std::cout << utf8string << std::endl;

    return 0;
}
