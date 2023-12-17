//  Buổi 4
//  Bài tập thực hành trên lớp -    Bài 1: Câu 1, 2, 3, 4, 5, 6, 7, 8, 9
//                                  Bài 2: Câu 1, 2, 3
//  Bài tập thực hành về nhà -      Bài 3: Câu 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
// Bài 1
#define ROWS 100
#define COLS 100
#define SIZE 100
// 1. Tạo và xuất ma trận Array chứa các phần tử ngẫu nhiên
void taoMaTran(int array[ROWS][COLS], int hang, int cot, int a, int b) {
    srand(time(0));
    for (int i = 0; i < hang; i++)
        for (int j = 0; j < cot; j++)
            array[i][j] = a + rand() % (b-a + 1);
}
void inMaTran(int array[ROWS][COLS], int hang, int cot) {
    for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}
// 2. Tính và xuất tổng giá trị từng dòng
void tinhVaXuatTongDong(int array[ROWS][COLS], int hang, int cot) {
    cout << "Tong gia tri tung dong:" << endl;
    for (int i = 0; i < hang; i++) {
        int tong = 0;
        for (int j = 0; j < cot; j++) {
            tong += array[i][j];
        }
        cout << "Dong " << i + 1 << ": " << tong << endl;
    }
}
// 3. Xuất phần tử lớn nhất trên từng cột
void xuatPhanTuLonNhatTrenCot(int array[ROWS][COLS], int hang, int cot) {
    cout << "Phan tu lon nhat tren tung cot:" << endl;
    for (int j = 0; j < cot; j++) {
        int max = array[0][j];
        for (int i = 1; i < hang; i++) {
            if (array[i][j] > max) {
                max = array[i][j];
            }
        }
        cout << "Cot " << j + 1 << ": " << max << endl;
    }
}
// 4. Xuất các phần tử thuộc các đường biên trên, dưới, trái và phải
void xuatPhanTuDuongBien(int array[ROWS][COLS], int hang, int cot) {
    cout << "Cac phan tu thuoc cac duong bien tren, duoi, trai va phai:" << endl;
    for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            if (i == 0 || i == hang - 1 || j == 0 || j == cot - 1) {
                cout << array[i][j] << " ";
            } else {
                cout << "  ";
            }
        }
    }
    cout << endl;
}
// 5. Xuất các phần tử cực đại
void xuatPhanTuCucDai(int array[ROWS][COLS], int hang, int cot) {
    cout << "Cac phan tu cuc dai:" << endl;
    for (int i = 1; i < hang - 1; i++) {
        for (int j = 1; j < cot - 1; j++) {
            int current = array[i][j];
            if (current >= array[i - 1][j] && current >= array[i + 1][j] &&
                current >= array[i][j - 1] && current >= array[i][j + 1]) {
                cout << current << " ";
            } else {
                cout << "  ";
            }
        }
    }
    cout << endl;
}
// 6. Xuất các phần tử hoàng hậu
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
        cout << maxQueenElement << " ";
    }
}
// 7. Xuất các phần tử là điểm yên ngựa
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
            cout << maxRow << " ";
        if (minRow == maxCol)
            cout << maxCol << " ";
	}
}
// 8. Xuất dòng chỉ chứa số chẵn
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
            cout << "A[i][]: ";
            for (j = 0; j < cot; j++){
                cout << array[i][j] << " ";
            }
        }
    }
}
// 9. Sắp xếp mảng A tăng theo từng dòng
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
// Bài 3
// 1. Hàm khởi tạo và xuất mảng 2 chiều chứa số nguyên ngẫu nhiên
void TaoVaXuatMaTran(int array[ROWS][COLS], int hang, int cot) {
    srand(time(0));

    cout << "Ma tran ngau nhien:\n";
    for (int i = 0; i < hang; ++i) {
        for (int j = 0; j < cot; ++j) {
            array[i][j] = rand() % 101; // Lấy số ngẫu nhiên từ 0 đến 100
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

// 2. Hàm xuất các cột chỉ chứa số lẻ
void XuatCotLe(int array[ROWS][COLS], int hang, int cot) {
    cout << "Cac cot chi chua so le:\n";
    for (int j = 0; j < cot; ++j) {
        bool coSoLe = false;
        for (int i = 0; i < hang; ++i) {
            if (array[i][j] % 2 != 0) {
                coSoLe = true;
                break;
            }
        }
        if (coSoLe) {
            for (int i = 0; i < hang; ++i) {
                cout << array[i][j] << " ";
            }
            cout << endl;
        }
    }
}

// 3. Hàm tìm phần tử lớn nhất trên biên của ma trận
int TimPhanTuLonNhatBien(int array[ROWS][COLS], int hang, int cot) {
    int maxBien = array[0][0];
    for (int i = 0; i < hang; ++i)
        for (int j = 0; j < cot; ++j)
            if (i == 0 || i == hang - 1 || j == 0 || j == cot - 1)
                if (array[i][j] > maxBien)
                    maxBien = array[i][j];
    return maxBien;
}

// 4. Hàm đếm số lượng chữ số 2 xuất hiện trong ma trận
int DemChuSoHai(int array[ROWS][COLS], int hang, int cot) {
    int so, dem = 0;
    for (int i = 0; i < hang; ++i)
        for (int j = 0; j < cot; ++j)
            so = abs(array[i][j]);
            while (so > 0)
                if (so % 10 == 2)
                    dem++;
                so /= 10;
    return dem;
}

// 5. Hàm xuất các phần tử cực tiểu của ma trận
void XuatCucTieu(int array[ROWS][COLS], int hang, int cot) {
    cout << "Cac phan tu cuc tieu cua ma tran:\n";
    for (int i = 0; i < hang; ++i) {
        for (int j = 0; j < cot; ++j) {
            bool cucTieu = true;
            if (i > 0 && array[i][j] >= array[i - 1][j])
                cucTieu = false;
            if (i < hang - 1 && array[i][j] >= array[i + 1][j])
                cucTieu = false;
            if (j > 0 && array[i][j] >= array[i][j - 1])
                cucTieu = false;
            if (j < cot - 1 && array[i][j] >= array[i][j + 1])
                cucTieu = false;
            if (cucTieu)
                cout << array[i][j] << " ";
        }
    }
    cout << endl;
}

// 6. Hàm sắp xếp ma trận theo yêu cầu
void SapXepMaTran(int array[ROWS][COLS], int hang, int cot, bool tangDdan) {
    for (int i = 0; i < hang; ++i)
        for (int j = 0; j < cot - 1; ++j)
            for (int k = j + 1; k < cot; ++k)
                if ((i % 2 == 1 && tangDdan) || (i % 2 == 0 && !tangDdan)) {
                    if (array[i][j] > array[i][k]) {
                        swap(array[i][j], array[i][k]);
                    }
                } else
                    if (array[i][j] < array[i][k])
                        swap(array[i][j], array[i][k]);
}

// 7. Hàm kiểm tra giá trị có giảm dần theo cột và dòng (ziczac)
bool KiemTraZicZac(int array[ROWS][COLS], int hang, int cot) {
    for (int i = 0; i < hang - 1; ++i) {
        for (int j = 0; j < cot - 1; ++j) {
            if (i % 2 == 0) {
                if (array[i][j] < array[i][j + 1] || array[i][j] < array[i + 1][j]) {
                    return false;
                }
            } else {
                if (array[i][j] > array[i][j + 1] || array[i][j] > array[i + 1][j]) {
                    return false;
                }
            }
        }
    }
    return true;
}

// 8. Hàm liệt kê chỉ số các dòng chứa toàn giá trị chẵn
void LietKeDongChan(int array[ROWS][COLS], int hang, int cot) {
    cout << "Cac dong chua toan gia tri chan:\n";
    for (int i = 0; i < hang; ++i) {
        bool toanChan = true;
        for (int j = 0; j < cot; ++j) {
            if (array[i][j] % 2 != 0) {
                toanChan = false;
                break;
            }
        }
        if (toanChan) {
            cout << "Dong " << i + 1 << endl;
        }
    }
}

// 9. Hàm liệt kê các dòng chứa giá trị giảm dần
void LietKeDongGiamDan(int array[ROWS][COLS], int hang, int cot) {
    cout << "Cac dong chua gia tri giam dan:\n";
    for (int i = 0; i < hang; ++i) {
        bool giamDan = true;
        for (int j = 0; j < cot - 1; ++j) {
            if (array[i][j] < array[i][j + 1]) {
                giamDan = false;
                break;
            }
        }
        if (giamDan) {
            cout << "Dong " << i + 1 << endl;
        }
    }
}

// 10. Hàm tìm giá trị xuất hiện nhiều nhất trong ma trận
int TimGiaTriXuatHienNhieuNhat(int array[ROWS][COLS], int hang, int cot) {
    int maxCount = 0;
    int maxValue = array[0][0];

    for (int i = 0; i < hang; ++i) {
        for (int j = 0; j < cot; ++j) {
            int count = 0;

            for (int k = 0; k < hang; ++k) {
                for (int l = 0; l < cot; ++l) {
                    if (array[i][j] == array[k][l]) {
                        count++;
                    }
                }
            }

            if (count > maxCount) {
                maxCount = count;
                maxValue = array[i][j];
            }
        }
    }

    return maxValue;
}

// 11. Hàm tìm chữ số xuất hiện nhiều nhất trong ma trận
int TimChuSoXuatHienNhieuNhat(int array[ROWS][COLS], int hang, int cot) {
    int chuSo[10] = {0};

    for (int i = 0; i < hang; ++i) {
        for (int j = 0; j < cot; ++j) {
            int so = abs(array[i][j]);

            while (so > 0) {
                chuSo[so % 10]++;
                so /= 10;
            }
        }
    }

    int maxCount = 0;
    int maxChuSo = 0;

    for (int i = 0; i < 10; ++i) {
        if (chuSo[i] > maxCount) {
            maxCount = chuSo[i];
            maxChuSo = i;
        }
    }

    return maxChuSo;
}

// Bài 2
// Tạo/Xuất ma trận vuông array chứa số nguyên ngẫu nhiên có cấp n>=5
void taoMaTranVuong(int array[SIZE][SIZE], int size) {
    srand(time(0));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            array[i][j] = rand() % 100;  // Số nguyên ngẫu nhiên từ 0 đến 99
        }
    }
}
void inMaTranVuong(int array[SIZE][SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}
// Xuất các phần tử trên đường chéo chính
void duongCheoChinh(int array[SIZE][SIZE], int size) {
    for (int i = 0; i < size; i++)
        cout << array[i][i] << " ";
}
// Xuất các phần tử thuộc đường chéo song song đường chéo chính
void duongSongSongDuongCheoChinh(int array[SIZE][SIZE], int size) {
    for (int i = 0; i < size; i++)
        cout << array[i][size - i - 1] << " ";
}

int main() {
    // Bài 1
    int hang = 2, cot = 3, a = 10, b = 99;
    cout << "Nhap gioi han duoi cua trinh tao so ngau nhien (a): ";
    cin >> a;
    cout << "Nhap gioi han tren cua trinh tao so ngau nhien (b): ";
    cin >> b;
    while (hang <= 0 || cot <= 0 || hang > ROWS || cot > COLS) {
        cout << "Nhap kich thuoc ma tran khong hop le. Vui long nhap lai:\n";
        cout << "Nhap gioi han duoi cua trinh tao so ngau nhien (a): ";
        cin >> a;
        cout << "Nhap gioi han tren cua trinh tao so ngau nhien (b): ";
        cin >> b;
    }
    int array[ROWS][COLS];
    taoMaTran(array, hang, cot, a, b);
    cout << "Tao va xuat ma tran Array chua cac phan tu ngau nhien: " << endl;
    inMaTran(array, hang, cot);
    cout << endl;
    cout << "Cac phan tu hoang hau: ";
    HoangHau(array, hang, cot);
    cout << endl;
    cout << "Cac phan tu diem yen ngua: ";
    diemYenNgua(array, hang, cot);
    cout << endl;
    cout << "Xuat dong chi chua so chan: ";
    xuatDongChuaSoChan(array, hang, cot);
    cout << endl;
    sapxepMangTangTheoTungDong(array, hang, cot);
    cout << "Sap xep mang A tang theo tung dong: " << endl;
    inMaTran(array, hang, cot);
    cout << "Tinh va xuat tong gia tri tung dong" << endl;
    tinhVaXuatTongDong(array, hang, cot);
    cout << "Xuat phan tu lon nhat tren tung cot" << endl;
    xuatPhanTuLonNhatTrenCot(array, hang, cot);
    cout << "Xuat cac phan tu thuoc cac duong bien tren, duoi, trai va phai" << endl;
    xuatPhanTuDuongBien(array, hang, cot);
    cout << "Xuat cac phan tu cuc dai" << endl;
    xuatPhanTuCucDai(array, hang, cot);
    // Bài 3 (tiếp tục các hàm xử lý trên mảng 2 chiều A (bài 1))
    int maxBien = TimPhanTuLonNhatBien(array, hang, cot);
    cout << "Phan tu lon nhat tren bien cua ma tran: " << maxBien << endl;

    int soLuongChuSo2 = DemChuSoHai(array, hang, cot);
    cout << "So luong chu so 2 xuat hien trong ma tran: " << soLuongChuSo2 << endl;

    XuatCucTieu(array, hang, cot);

    SapXepMaTran(array, hang, cot, true);
    cout << "Ma tran sau khi sap xep:\n";
    for (int i = 0; i < hang; ++i) {
        for (int j = 0; j < cot; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    SapXepMaTran(array, hang, cot, false);
    cout << "Ma tran sau khi sap xep:\n";
    for (int i = 0; i < hang; ++i) {
        for (int j = 0; j < cot; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    if (KiemTraZicZac(array, hang, cot)) {
        cout << "Ma tran co gia tri gi giam dan theo cot va dong (ziczac).\n";
    } else {
        cout << "Ma tran khong co gia tri gi giam dan theo cot va dong (ziczac).\n";
    }

    LietKeDongChan(array, hang, cot);
    LietKeDongGiamDan(array, hang, cot);

    int giaTriXuatHienNhieuNhat = TimGiaTriXuatHienNhieuNhat(array, hang, cot);
    cout << "Gia tri xuat hien nhieu nhat trong ma tran: " << giaTriXuatHienNhieuNhat << endl;

    int chuSoXuatHienNhieuNhat = TimChuSoXuatHienNhieuNhat(array, hang, cot);
    cout << "Chu so xuat hien nhieu nhat trong ma tran: " << chuSoXuatHienNhieuNhat << endl;
    // Bài 2
    cout << endl;
    int size, i ,j;
    srand(time(0));
    int arr[SIZE][SIZE];
    size = 5 + rand() % (7-5 + 1);
    // Tạo và xuất ma trận ngẫu nhiên
    taoMaTranVuong(arr, size);
    cout << "Tao ma tran vuong ngau nhien:" << endl;
    inMaTranVuong(arr, size);
    cout << endl;
    // Xuất các phần tử trên đường chéo chính
    cout << "Xuat cac phan tu tren duong cheo chinh: ";
    duongCheoChinh(arr, size);
    cout << endl;
    // Xuất các phần tử thuộc đường chéo song song với đường chéo chính
    cout << "Xuat cac phan tu thuoc duong cheo song song voi duong cheo chinh: ";
    duongSongSongDuongCheoChinh(arr, size);
    cout << endl;
    return 0;
}