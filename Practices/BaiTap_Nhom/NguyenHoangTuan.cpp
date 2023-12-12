//  Bài tập thực hành trên lớp -    Bài 1: Câu 6, 7, 8, 9
//                                  Bài 2: Câu 1, 2, 3
#include <iostream>
#include <cstdlib>
#include <ctime>

const int ROWS = 100;
const int COLS = 100;
// Tạo và xuất ma trận Array chứa các phần tử ngẫu nhiên
void taoMaTran(int array[ROWS][COLS], int hang, int cot, int a, int b) {
    srand(time(0));
    for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            array[i][j] = a + rand() % (b-a + 1);
        }
    }
}
void inMaTran(int array[ROWS][COLS], int hang, int cot) {
    for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
// Xuất các phần tử hoàng hậu
void HoangHau(int array[ROWS][COLS], int hang, int cot) {
    int maxInRow;
    std::cout << "Queen elements: ";
    for (int i = 0; i < hang; i++) {
        maxInRow = array[i][0];
        for (int j = 1; j < cot; j++) {
            if (array[i][j] > maxInRow) {
                maxInRow = array[i][j];
            }
        }
        std::cout << maxInRow << " ";
    }
    std::cout << std::endl;
}
// Xuất các phần tử là điểm yên ngựa
void diemYenNgua(int array[ROWS][COLS], int hang, int cot) {
    int minInCol;
    std::cout << "Knight elements: ";
    for (int j = 0; j < cot; j++) {
        minInCol = array[0][j];
        for (int i = 1; i < hang; i++) {
            if (array[i][j] < minInCol) {
                minInCol = array[i][j];
            }
        }
        std::cout << minInCol << " ";
    }
    std::cout << std::endl;
}
// Xuất dòng chỉ chứa số chẵn
void xuatDongChuaSoChan(int array[ROWS][COLS], int hang, int cot) {
    std::cout << "Even hang elements: ";
    for (int i = 0; i < hang; i += 2) {
        for (int j = 0; j < cot; j++) {
            std::cout << array[i][j] << " ";
        }
    }
    std::cout << std::endl;
}
// Sắp xếp mảng A tăng theo từng dòng
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void sapxepMangTangTheoTungDong(int array[ROWS][COLS], int hang, int cot) {
    for (int i = 0; i < hang; i++)
        for (int j = 0; j < cot - 1; j++)
            for (int k = j + 1; k < cot; ++k)
                if (array[i][j] > array[i][k])
                    swap(array[i][j], array[i][k]);
}

int main() {
    int hang, cot, a, b;
    std::cout << "Enter number of hang (rows < 100): ";
    std::cin >> hang;
    std::cout << "Enter number of columns (columns < 100): ";
    std::cin >> cot;
    std::cout << "Enter the lower limit for random numbers (a): ";
    std::cin >> a;
    std::cout << "Enter the upper limit for random numbers (b): ";
    std::cin >> b;

    if (hang > ROWS || cot > COLS) {
        std::cout << "Exceeds maximum size. Please adjust hang and cot." << std::endl;
        return 1;
    }

    int array[ROWS][COLS];
    taoMaTran(array, hang, cot, a, b);

    std::cout << "Randomly generated matrix:" << std::endl;
    inMaTran(array, hang, cot);

    HoangHau(array, hang, cot);
    diemYenNgua(array, hang, cot);
    xuatDongChuaSoChan(array, hang, cot);

    sapxepMangTangTheoTungDong(array, hang, cot);
    std::cout << "Matrix sorted in each hang:" << std::endl;
    inMaTran(array, hang, cot);

    return 0;
}