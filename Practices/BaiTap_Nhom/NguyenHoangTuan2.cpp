#include <iostream>
#include <cstdlib>
#include <ctime>

const int SIZE = 100;
// Tạo/xuất ma trận vuông array chứa số nguyên ngẫu nhiên có cấp n>=5
void taoMaTran(int array[SIZE][SIZE], int size) {
    srand(time(0));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            array[i][j] = rand() % 100;  // Số nguyên ngẫu nhiên từ 0 đến 99
        }
    }
}
void inMaTran(int array[SIZE][SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
// Xuất các phần tử trên đường chéo chính
void duongCheoChinh(int array[SIZE][SIZE], int size) {
    for (int i = 0; i < size; i++)
        std::cout << array[i][i] << " ";
}

void duongSongSongDuongCheoChinh(int array[SIZE][SIZE], int size) {
    for (int i = 0; i < size; i++)
        std::cout << array[i][size - i - 1] << " ";
}

int main() {
    int size, i ,j;
    srand(time(0));
    int array[SIZE][SIZE];
    size = 5 + rand() % (7-5 + 1);
    // Tạo và xuất ma trận ngẫu nhiên
    taoMaTran(array, size);
    std::cout << "Tao ma tran ngau nhien:" << std::endl;
    inMaTran(array, size);
    std::cout << std::endl;
    // Xuất các phần tử trên đường chéo chính
    std::cout << "Xuat cac phan tu tren duong cheo chinh: ";
    duongCheoChinh(array, size);
    std::cout << std::endl;
    // Xuất các phần tử thuộc đường chéo song song với đường chéo chính
    std::cout << "Xuat cac phan tu thuoc duong cheo song song voi duong cheo chinh: ";
    duongSongSongDuongCheoChinh(array, size);
    std::cout << std::endl;
    return 0;
}