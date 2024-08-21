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
            std::cout << "������ " << n << ": " << line << std::endl;
            break; // ��������� ���� ����� ���������� ������ ������
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
            std::cout << "������� ���������� � ������ " << lineNumber << ", ������� " << position+1 << std::endl;
            c++;
        }
    }
    if (c <= 0)
    {
        cout << "���������� ���";
    }
    file.close();

}
int countUniqueLines(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    std::set<std::string> uniqueLines; // ���������� ��������� ��� �������� ���������� �����

    while (std::getline(file, line)) {
        uniqueLines.insert(line); // ��������� ������ � ���������
    }

    file.close();

    return uniqueLines.size(); // ���������� ���������� ���������� �����
}
int main() {
    setlocale(LC_ALL, "rus");
    int n = 5;
    std::string filename = "test.txt"; 
    std::string substring;
    printNthLine(filename, n);
    std::cout << "������� ��������� ��� ������: ";
    std::getline(std::cin, substring);

    findSubstringInFile(filename, substring);
    int uniqueCount = countUniqueLines(filename);
    std::cout << "���������� ���������� ����� � �����: " << uniqueCount << std::endl;
    return 0;
}