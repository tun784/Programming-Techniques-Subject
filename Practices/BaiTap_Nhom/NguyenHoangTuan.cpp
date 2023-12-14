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
    for (int i = 0; i < hang; i++)
        for (int j = 0; j < cot; j++)
            array[i][j] = a + rand() % (b-a + 1);
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
    for (int i = 0; i < hang; ++i) {
        int maxInRow = array[i][0];
        for (int j = 1; j < cot; ++j) {
            if (array[i][j] > maxInRow) {
                maxInRow = array[i][j];
            }
        }

        int maxInCol = array[0][i];
        for (int j = 1; j < hang; ++j) {
            if (array[j][i] > maxInCol) {
                maxInCol = array[j][i];
            }
        }

        int maxInDiagonal1 = array[i][i];
        int maxInDiagonal2 = array[i][cot - i - 1];

        for (int j = 0; j < hang; ++j) {
            if (i != j) {
                if (array[j][i] > maxInDiagonal1) {
                    maxInDiagonal1 = array[j][i];
                }
                if (array[j][cot - i - 1] > maxInDiagonal2) {
                    maxInDiagonal2 = array[j][cot - i - 1];
                }
            }
        }

        int maxQueenElement = std::max(std::max(maxInRow, maxInCol), std::max(maxInDiagonal1, maxInDiagonal2));
        std::cout << maxQueenElement << " ";
    }
}
// Xuất các phần tử là điểm yên ngựa
void diemYenNgua(int array[ROWS][COLS], int hang, int cot) {
    int i, j, k, maxRow, minRow, maxCol, minCol, m, n, a, b;
    for (i = 0; i < hang; i++){
		maxRow = array[i][0];
        m = 0;
		minRow = array[i][0];
        n = 0;
		for (j = 1; j < cot; j++){
			if (maxRow < array[i][j]){
				maxRow = array[i][j];
                m = j;
            }
			if (minRow > array[i][j]){
				minRow = array[i][j];
                n = j;
            }
		}
        maxCol = array[i][n];
        minCol = array[i][m];
        for (k = 0; k < hang; k++){
            if (maxCol < array[k][n])
                maxCol = array[k][n];
            if (minCol > array[k][m])
                minCol = array[k][m];
        }
        if (maxRow == minCol)
            std::cout << maxRow << " ";
        if (minRow == maxCol)
            std::cout << maxCol << " ";
	}
}
// Xuất dòng chỉ chứa số chẵn
void xuatDongChuaSoChan(int array[ROWS][COLS], int hang, int cot) {
    bool sochan = true;
    int i, j;
    for (i = 0; i < hang; i++) {
        for (j = 0; j < cot; j++) {
            if (array[i][j] % 2 != 0){
                sochan = false;
                break;
            }
        }
        if (sochan == true){
            std::cout << "A[i][]: ";
            for (j = 0; j < cot; j++){
                std::cout << array[i][j] << " ";
            }
        }
    }
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
    int hang = 2, cot = 3, a = 10, b = 99;
    // std::cout << "Nhap gioi han duoi cua trinh tao so ngau nhien (a): ";
    // std::cin >> a;
    // std::cout << "Nhap gioi han tren cua trinh tao so ngau nhien (b): ";
    // std::cin >> b;

    int array[ROWS][COLS];
    taoMaTran(array, hang, cot, a, b);

    std::cout << "Tao ma tran ngau nhien: " << std::endl;
    inMaTran(array, hang, cot);
    std::cout << std::endl;

    std::cout << "Cac phan tu hoang hau: ";
    HoangHau(array, hang, cot);
    std::cout << std::endl;
    std::cout << "Cac phan tu diem yen ngua: ";
    diemYenNgua(array, hang, cot);
    std::cout << std::endl;
    std::cout << "Xuat dong chi chua so chan: ";
    xuatDongChuaSoChan(array, hang, cot);
    std::cout << std::endl;

    sapxepMangTangTheoTungDong(array, hang, cot);
    std::cout << "Sap xep mang A tang theo tung dong: " << std::endl;
    inMaTran(array, hang, cot);

    return 0;
}