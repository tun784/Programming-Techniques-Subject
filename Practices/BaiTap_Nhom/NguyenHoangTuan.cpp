//  Bài tập thực hành trên lớp -    Bài 1: Câu 6, 7, 8, 9
//                                  Bài 2: Câu 1, 2, 3
#include <iostream>
#include <cstdlib>
#include <ctime>

const int ROWS = 100;
const int COLS = 100;
// Tạo và xuất ma trận a chứa các phần tử ngẫu nhiên
void initializeMatrix(int a[ROWS][COLS], int row, int cols, int k) {
    srand(time(0));

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < cols; ++j) {
            a[i][j] = rand() % (k + 1);
        }
    }
}
void printMatrix(int a[ROWS][COLS], int row, int cols) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void printQueens(int a[ROWS][COLS], int row, int cols) {
    std::cout << "Queen elements: ";
    for (int i = 0; i < row; ++i) {
        int maxInRow = a[i][0];
        for (int j = 1; j < cols; ++j) {
            if (a[i][j] > maxInRow) {
                maxInRow = a[i][j];
            }
        }
        std::cout << maxInRow << " ";
    }
    std::cout << std::endl;
}

void printKnight(int a[ROWS][COLS], int row, int cols) {
    std::cout << "Knight elements: ";
    for (int j = 0; j < cols; ++j) {
        int minInCol = a[0][j];
        for (int i = 1; i < row; ++i) {
            if (a[i][j] < minInCol) {
                minInCol = a[i][j];
            }
        }
        std::cout << minInCol << " ";
    }
    std::cout << std::endl;
}

void printEvenRow(int a[ROWS][COLS], int row, int cols) {
    std::cout << "Even row elements: ";
    for (int i = 0; i < row; i += 2) {
        for (int j = 0; j < cols; ++j) {
            std::cout << a[i][j] << " ";
        }
    }
    std::cout << std::endl;
}

void sortMatrix(int a[ROWS][COLS], int row, int cols) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < cols - 1; ++j) {
            for (int k = j + 1; k < cols; ++k) {
                if (a[i][j] > a[i][k]) {
                    std::swap(a[i][j], a[i][k]);
                }
            }
        }
    }
}

int main() {
    int row, cols, k;
    std::cout << "Enter number of ROWS (row): ";
    std::cin >> row;
    std::cout << "Enter number of columns (cols): ";
    std::cin >> cols;
    std::cout << "Enter the upper limit for random numbers (k): ";
    std::cin >> k;

    if (row > ROWS || cols > COLS) {
        std::cout << "Exceeds maximum size. Please adjust row and cols." << std::endl;
        return 1;
    }

    int a[ROWS][COLS];
    initializeMatrix(a, row, cols, k);

    std::cout << "Randomly generated matrix:" << std::endl;
    printMatrix(a, row, cols);

    printQueens(a, row, cols);
    printKnight(a, row, cols);
    printEvenRow(a, row, cols);

    sortMatrix(a, row, cols);
    std::cout << "Matrix sorted in each row:" << std::endl;
    printMatrix(a, row, cols);

    return 0;
}