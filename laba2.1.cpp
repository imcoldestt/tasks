#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

//ЗАДАЧА 1: Статическая матрица 6х4 
void task1() {
    std::cout << "=== Задача 1 ===\n";
    const int ROWS = 6;
    const int COLS = 4;
    int matrix[ROWS][COLS];

    // Заполнение матрицы случайными числами
    std::cout << "Исходная матрица 6x4:\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            matrix[i][j] = rand() % 6; 
            std::cout << std::setw(4) << matrix[i][j];
        }
        std::cout << "\n";
    }

    int count_cols = 0;
    std::cout << "Номера столбцов без нулевых элементов (нумерация с 1): ";
    
    // Поиск столбцов без нулей
    for (int j = 0; j < COLS; ++j) {
        bool has_zero = false;
        for (int i = 0; i < ROWS; ++i) {
            if (matrix[i][j] == 0) {
                has_zero = true;
                break;
            }
        }
        
        if (!has_zero) {
            std::cout << (j + 1) << " ";
            count_cols++;
        }
    }
    
    std::cout << "\nКоличество таких столбцов: " << count_cols << "\n\n";
}

// --- ЗАДАЧА 2: Динамическая прямоугольная матрица ---
void task2() {
    std::cout << "=== Задача 2 ===\n";
    int rows, cols;
    std::cout << "Введите количество строк: ";
    std::cin >> rows;
    std::cout << "Введите количество столбцов: ";
    std::cin >> cols;

    // Выделение памяти
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    // Заполнение случайными числами (от -5 до 5) и вывод
    std::cout << "Исходная матрица:\n";
    int* neg_counts = new int[rows]; 
    
    for (int i = 0; i < rows; ++i) {
        neg_counts[i] = 0;
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = (rand() % 11) - 5;
            std::cout << std::setw(4) << matrix[i][j];
            if (matrix[i][j] < 0) {
                neg_counts[i]++;
            }
        }
        std::cout << " | Отрицательных: " << neg_counts[i] << "\n";
    }

    // Стабильная сортировка (пузырьком) по убыванию количества отрицательных элементов
    for (int i = 0; i < rows - 1; ++i) {
        for (int j = 0; j < rows - i - 1; ++j) {
            if (neg_counts[j] < neg_counts[j + 1]) {
                // Обмен счётчиков
                int temp_count = neg_counts[j];
                neg_counts[j] = neg_counts[j + 1];
                neg_counts[j + 1] = temp_count;
                
                // Обмен указателей на строки матрицы
                int* temp_row = matrix[j];
                matrix[j] = matrix[j + 1];
                matrix[j + 1] = temp_row;
            }
        }
    }

    // Вывод отсортированной матрицы
    std::cout << "\nМатрица после сортировки строк:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << std::setw(4) << matrix[i][j];
        }
        std::cout << " | Отрицательных: " << neg_counts[i] << "\n";
    }

    // Освобождение памяти
    delete[] neg_counts;
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    // Инициализация генератора случайных чисел
    srand(static_cast<unsigned int>(time(0))); 

    task1();
    task2();

    return 0;
}
