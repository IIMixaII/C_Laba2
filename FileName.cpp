#include <iostream>
#include <fstream>
#include <string>
#include <set>
using namespace std;

void printNthLine(const std::string& filename, int n) {
    std::ifstream file(filename);
    std::string line;
    int lineNumber = 0;

    while (std::getline(file, line)) {
        lineNumber++;
        if (lineNumber == n) {
            std::cout << "Строка " << n << ": " << line << std::endl;
            break; // Прерываем цикл после нахождения нужной строки
        }
    }

    file.close();
}

void findSubstringInFile(const std::string& filename, const std::string& substring) {
    std::ifstream file(filename);
    std::string line;
    int lineNumber = 0;
    int c = 0;
    while (std::getline(file, line)) {
        lineNumber++;
        size_t position = line.find(substring);
        if (position != std::string::npos) {
            std::cout << "Найдено совпадение в строке " << lineNumber << ", позиция " << position+1 << std::endl;
            c++;
        }
    }
    if (c <= 0)
    {
        cout << "Совпадений нет";
    }
    file.close();

}
int countUniqueLines(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    std::set<std::string> uniqueLines; // Используем множество для хранения уникальных строк

    while (std::getline(file, line)) {
        uniqueLines.insert(line); // Добавляем строку в множество
    }

    file.close();

    return uniqueLines.size(); // Возвращаем количество уникальных строк
}
int main() {
    setlocale(LC_ALL, "rus");
    int n = 5;
    std::string filename = "test.txt"; 
    std::string substring;
    printNthLine(filename, n);
    std::cout << "Введите подстроку для поиска: ";
    std::getline(std::cin, substring);

    findSubstringInFile(filename, substring);
    int uniqueCount = countUniqueLines(filename);
    std::cout << "Количество уникальных строк в файле: " << uniqueCount << std::endl;
    return 0;
}