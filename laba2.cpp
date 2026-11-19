#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

const int ROWS = 6;
const int COLS = 4;

void fillMatrix(int* p, int n) {
    std::cout << "Введите " << n << " чисел: ";
    for (int* q = p; q < p + n; q++)
        std::cin >> *q;
}

void fillMatrix(int* p, int n, const char* fileName) {
    std::ifstream fin(fileName);
    for (int* q = p; q < p + n; q++)
        fin >> *q;
}

void fillMatrix(int* p, int n, int left, int right) {
    if (left > right) {
        int tmp = left;
        left = right;
        right = tmp;
    }
    for (int* q = p; q < p + n; q++)
        *q = left + rand() % (right - left + 1);
}

void printMatrix(const int* p) {
    std::cout << "Матрица:\n";
    for (const int* q = p; q < p + ROWS * COLS; q++) {
        std::cout << *q << " ";
        if ((q - p + 1) % COLS == 0)
            std::cout << "\n";
    }
}

bool hasZeroInCol(const int* p, int col) {
    for (int i = 0; i < ROWS; i++)
        if (*(p + i * COLS + col) == 0) return true;
    return false;
}

void findColsWithoutZeros(const int* p) {
    int count = 0;
    std::cout << "Столбцы без нулей: ";
    for (int j = 0; j < COLS; j++)
        if (!hasZeroInCol(p, j)) {
            std::cout << j + 1 << " ";
            count++;
        }
    std::cout << "\n";
    std::cout << "Количество: " << count << "\n";
}

void chooseAndFill(int* p, int n) {
    int choice;
    std::cout << "Как заполнить? 1 - клавиатура, 2 - файл, 3 - случайно: ";
    std::cin >> choice;
    if (choice == 1) fillMatrix(p, n);
    if (choice == 2) {
        char name[100];
        std::cout << "Имя файла: ";
        std::cin >> name;
        fillMatrix(p, n, name);
    }
    if (choice == 3) {
        int left, right;
        std::cout << "Левая граница: "; std::cin >> left;
        std::cout << "Правая граница: "; std::cin >> right;
        fillMatrix(p, n, left, right);
    }
}

void task1() {
    int a[ROWS][COLS];
    int* p = &a[0][0];

    chooseAndFill(p, ROWS * COLS);

    printMatrix(p);
    findColsWithoutZeros(p);
}

int** createMatrix(int n, int m) {
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++)
        matrix[i] = new int[m];
    return matrix;
}

void freeMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;
}

void fillDynFromKeyboard(int** matrix, int n, int m) {
    std::cout << "Введите " << n * m << " чисел: ";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cin >> matrix[i][j];
}

void fillDynFromFile(int** matrix, int n, int m) {
    char name[100];
    std::cout << "Имя файла: ";
    std::cin >> name;
    std::ifstream fin(name);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fin >> matrix[i][j];
}

void fillDynRandom(int** matrix, int n, int m) {
    int left, right;
    std::cout << "Левая граница: "; std::cin >> left;
    std::cout << "Правая граница: "; std::cin >> right;
    if (left > right) {
        int tmp = left;
        left = right;
        right = tmp;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            matrix[i][j] = left + rand() % (right - left + 1);
}

void fillDynamic(int** matrix, int n, int m) {
    int choice;
    std::cout << "Как заполнить? 1 - клавиатура, 2 - файл, 3 - случайно: ";
    std::cin >> choice;
    if (choice == 1) fillDynFromKeyboard(matrix, n, m);
    if (choice == 2) fillDynFromFile(matrix, n, m);
    if (choice == 3) fillDynRandom(matrix, n, m);
}

void printDynamic(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << "\n";
    }
}

int countNeg(int* row, int m) {
    int count = 0;
    for (int* q = row; q < row + m; q++)
        if (*q < 0) count++;
    return count;
}

void swapRows(int** first, int** second) {
    int* temp = *first;
    *first = *second;
    *second = temp;
}

void sortRows(int** matrix, int n, int m) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (countNeg(matrix[j], m) < countNeg(matrix[j + 1], m))
                swapRows(&matrix[j], &matrix[j + 1]);
}

void task2() {
    int n, m;
    std::cout << "Сколько строк: "; 
    std::cin >> n;
    std::cout << "Сколько столбцов: "; 
    std::cin >> m;

    int** matrix = createMatrix(n, m);
    fillDynamic(matrix, n, m);

    std::cout << "Матрица:\n";
    printDynamic(matrix, n, m);

    sortRows(matrix, n, m);

    std::cout << "После сортировки:\n";
    printDynamic(matrix, n, m);

    freeMatrix(matrix, n);
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    srand(time(0));
    int menu = 0;

    while (menu != 3) {
        std::cout << "\n";
        std::cout << "1 - статическая матрица\n";
        std::cout << "2 - динамическая матрица\n";
        std::cout << "3 - выход\n";
        std::cin >> menu;
        if (menu == 1) task1();
        if (menu == 2) task2();
    }
    return 0;
}
