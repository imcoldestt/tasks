#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

//1
std::string remove_char(const std::string& s, const char target) {
    std::string result = s;
    result.erase(std::remove(result.begin(), result.end(), target), result.end());
    return result;
}

//2
int count_words(const std::string& s) {
    std::istringstream iss(s);
    std::string word;
    int count = 0;
    while (iss >> word) {
        ++count;
    }
    return count;
}

//3
std::string reverse_each_word(const std::string& s) {
    std::istringstream iss(s);
    std::string result, word;
    while (iss >> word) {
        std::reverse(word.begin(), word.end());
        if (!result.empty()) result += ' ';
        result += word;
    }
    return result;
}

int main() {
//1
    std::string s1 = "h-e-l-l-o";
    std::cout << "Задача 1:\n";
    std::cout << "  Исходная строка : \"" << s1 << "\"\n";
    std::cout << "  Убираем '-'     : \"" << remove_char(s1, '-') << "\"\n\n";

//2
    std::string s2 = "  один  два   три  ";
    std::cout << "Задача 2:\n";
    std::cout << "  Исходная строка : \"" << s2 << "\"\n";
    std::cout << "  Количество слов : " << count_words(s2) << "\n\n";

//3
    std::string s3 = "hello world foo";
    std::cout << "Задача 3:\n";
    std::cout << "  Исходная строка : \"" << s3 << "\"\n";
    std::cout << "  Разворот слов   : \"" << reverse_each_word(s3) << "\"\n";

    return 0;
}
