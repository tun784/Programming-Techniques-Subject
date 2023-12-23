#include <iostream>
#include <cstdlib>
#include <time.h>
#include <math.h>
using namespace std;
// Bài 1
const int MAX_SIZE = 100;
// Hàm tạo ma trận ngẫu nhiên
void taoMaTranNgauNhien(int a[MAX_SIZE][MAX_SIZE], int n) {
    srand(time(0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = rand() % 101 - 50;
        }
    }
}
// Hàm xuất ma trận
void xuatMaTran(int a[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}
// Hàm sắp xếp cột c giảm dần
void sapXepCotGiamDan(int a[MAX_SIZE][MAX_SIZE], int n, int c) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i][c] < a[j][c]) {
                swap(a[i][c], a[j][c]);
            }
        }
    }
}
// Hàm kiểm tra cột có giá trị giảm dần hay không
bool cotGiamDan(int a[MAX_SIZE][MAX_SIZE], int n, int c) {
    for (int i = 0; i < n - 1; ++i) {
        if (a[i][c] < a[i + 1][c]) {
            return false;
        }
    }
    return true;
}
// Hàm liệt kê các cột giảm dần
void lietKeCotGiamDan(int a[MAX_SIZE][MAX_SIZE], int n) {
    cout << "Cac cot chua gia tri giam dan la: ";
    for (int j = 0; j < n; ++j) {
        if (cotGiamDan(a, n, j)) {
            cout << j << " ";
        }
    }
    cout << endl;
}
// Hàm kiểm tra số nguyên tố
bool laSoNguyenTo(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
// Hàm xuất tổng số nguyên tố trong tam giác dưới của đường chéo phụ
void xuatTongSoNguyenTo(int a[MAX_SIZE][MAX_SIZE], int n) {
    int tong = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = n - i - 1; j < n; ++j) {
            if (laSoNguyenTo(a[i][j])) {
                tong += a[i][j];
            }
        }
    }
    cout << "Tong cac so nguyen to trong tam giac duoi cua duong cheo phu la: " << tong << endl;
}
// Hàm chương trình chính
void bai1Menu() {
    int n, luaChon, maTran[MAX_SIZE][MAX_SIZE];
    cout << "Nhap kich thuoc ma tran vuong (n <= " << MAX_SIZE << "): ";
    cin >> n;
    cout << "\n----- MENU -----\n";
    cout << "1. Tao va xuat ma tran\n";
    cout << "2. Sap xep cot giam dan\n";
    cout << "3. Liet ke cac cot giam dan\n";
    cout << "4. Xuat tong so nguyen to\n";
    cout << "0. Thoat\n";
    do {
        cout << endl;
        cout << "**Nhap lua chon: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1:{
                taoMaTranNgauNhien(maTran, n);
                xuatMaTran(maTran, n);
                }break;
            case 2: {
                int cot;
                cout << "Nhap cot can sap xep: ";
                cin >> cot;
                sapXepCotGiamDan(maTran, n, cot);
                xuatMaTran(maTran, n);
                }break;
            case 3: {
                lietKeCotGiamDan(maTran, n);
                }break;
            case 4: {
                xuatTongSoNguyenTo(maTran, n);
                }break;
            case 0:
                cout << "Ket thuc chuong trinh!\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long nhap lai.\n";
                break;
        }
    } while (luaChon != 0);
}

// Bài 2
// Hàm tính S(x, n) theo cách đệ quy
float tinhS_DeQuy(float x, int n) {
    if (n == 0)
        return x;
    return tinhS_DeQuy(x, n - 1) + (float)(pow(x, n)) / (n * (n + 1) / 2);
}
// Hàm tính S(x, n) theo cách khử đệ quy
float tinhS_KhuDeQuy(float x, int n) {
    float s = x;
    for (int i = 1; i <= n; ++i) {
        s += (float)(pow(x, i)) / (i * (i + 1) / 2);
    }
    return s;
}
// Hàm tính tổng các chữ số lẻ của số nguyên dương n theo cách đệ quy
int tongChuSoLe_DeQuy(int n) {
    if (n == 0)
        return 0;
    int digit = n % 10;
    if (digit % 2 != 0)
        return digit + tongChuSoLe_DeQuy(n / 10);
    else
        return tongChuSoLe_DeQuy(n / 10);
}
// Hàm tính tổng các chữ số lẻ của số nguyên dương n theo cách khử đệ quy
int tongChuSoLe_KhuDeQuy(int n) {
    int s = 0;
    while (n > 0) {
        int digit = n % 10;
        if (digit % 2 != 0)
            s += digit;
        n /= 10;
    }
    return s;
}
// Hàm tính A[n] theo đệ quy
int tinhA_DeQuy(int n) {
    if (n == 0)
        return 1;
    int a = 1, b = 2, c;
    for (int i = 2; i <= n; ++i) {
        c = i * a + (i - 1) * b;
        a = b;
        b = c;
    }
    return b;
}
// Hàm chương trình chính
void bai2Menu() {
    int luaChon, n, soN, index;
    float x;
    cout << "\n\t----- MENU -----\n";
    cout << "1. Tinh S(x, n) theo cach de quy\n";
    cout << "2. Tinh S(x, n) theo cach khu de quy\n";
    cout << "3. Tinh tong chu so le cua so nguyen duong n theo cach de quy\n";
    cout << "4. Tinh tong chu so le cua so nguyen duong n theo cach khu de quy\n";
    cout << "5. Tinh A[n] theo de quy\n";
    cout << "0. Thoat\n";
    do {
        cout << "**Nhap lua chon: ";
        cin >> luaChon;
        cout << endl;
        switch (luaChon) {
        case 1: {
            cout << "Nhap gia tri x: ";
            cin >> x;
            cout << "Nhap gia tri n: ";
            cin >> n;
            cout << "S(x, n) = " << tinhS_DeQuy(x, n) << endl;
            }break;
        case 2: {
            cout << "Nhap gia tri x: ";
            cin >> x;
            cout << "Nhap gia tri n: ";
            cin >> n;
            cout << "S(x, n) = " << tinhS_KhuDeQuy(x, n) << endl;
            }break;
        case 3:
            cout << "Nhap so nguyen duong n: ";
            cin >> soN;
            cout << "Tong chu so le theo cach de quy: " << tongChuSoLe_DeQuy(soN) << endl;
            break;
        case 4:
            cout << "Nhap so nguyen duong n: ";
            cin >> soN;
            cout << "Tong chu so le theo cach khu de quy: " << tongChuSoLe_KhuDeQuy(soN) << endl;
            break;
        case 5:
            cout << "Nhap gia tri n: ";
            cin >> index;
            cout << "A[" << index << "] = " << tinhA_DeQuy(index) << endl;
            break;
        case 0:
            cout << "Ket thuc chuong trinh!\n";
            break;
        default:
            cout << "Lua chon khong hop le. Vui long nhap lai.\n";
            break;
        }
    } while (luaChon != 0);
}

int main() {
    int c = 0;
    do {
        cout << "Ban muon chon bai nao (1 hoac 2): ";
        cin >> c;
        while (c < 0 || c > 2) {
            cout << "Yeu cau khong hop le, xin vui long nhap lai: ";
            cin >> c;
        }
        if (c == 1)
            bai1Menu();
        else if (c == 2)
            bai2Menu();
        else
            exit(c);
    } while (true);
    return 0;
}