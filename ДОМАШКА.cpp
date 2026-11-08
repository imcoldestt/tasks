#include <iostream>
#include <cctype>
#include <clocale>

void countCharacters(const char str[], int& letters, int& digits, int& spaces, int& others) {
    letters = digits = spaces = others = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i]))
            letters++;
        else if (isdigit(str[i]))
            digits++;
        else if (str[i] == ' ')
            spaces++;
        else
            others++;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    const char str[] = "Hello 123!";

    int letters, digits, spaces, others;
    countCharacters(str, letters, digits, spaces, others);

    std::cout << "Букв: "     << letters << "; "
              << "Цифр: "     << digits  << "; "
              << "Пробелов: " << spaces  << "; "
              << "Других: "   << others  << std::endl;

    return 0;
}
