#include <stdio.h>
#include <windows.h>
#include "lib/matrixlib.h"

// Функция для подсчета двузначных чисел в строке
int countTwoDigitNumbersInRow(int *row, int cols) {
    int count = 0;
    for (int i = 0; i < cols; i++) {
        if (row[i] >= 10 && row[i] <= 99) {
            count++;
        }
    }
    return count;
}

// Функция для обмена двух строк матрицы
void swapRows(int **matrix, int row1, int row2, int cols) {
    for (int i = 0; i < cols; i++) {
        int temp = matrix[row1][i];
        matrix[row1][i] = matrix[row2][i];
        matrix[row2][i] = temp;
    }
}

// Функция для сортировки строк по количеству двузначных чисел
void sortRowsByTwoDigitNumbers(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows - 1; i++) {
        for (int j = 0; j < rows - i - 1; j++) {
            // Подсчет двузначных чисел в строках j и j+1
            int countJ = countTwoDigitNumbersInRow(matrix[j], cols);
            int countJPlus1 = countTwoDigitNumbersInRow(matrix[j + 1], cols);

            // Поменять строки, если количество двузначных чисел в строке j больше чем в строке j+1
            if (countJ > countJPlus1) {
                // Обмен строк
                swapRows(matrix, j, j + 1, cols);
            }
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int rowsInMatrix = 3, colsInMatrix = 4;

    int** intMatrix = (int**)allocate_matrix(rowsInMatrix, colsInMatrix, sizeof(int));

    input_int_matrix(intMatrix, rowsInMatrix, colsInMatrix);

    printf("\nМатрица до сортировки:\n");
    print_int_matrix(intMatrix,rowsInMatrix, colsInMatrix);

    // Сортировка строк по количеству двузначных чисел
    sortRowsByTwoDigitNumbers(intMatrix, rowsInMatrix, colsInMatrix);

    printf("\nМатрица после сортировки:\n");
    print_int_matrix(intMatrix,rowsInMatrix, colsInMatrix);

    deallocate_matrix(intMatrix, rowsInMatrix);
    return 0;
}
