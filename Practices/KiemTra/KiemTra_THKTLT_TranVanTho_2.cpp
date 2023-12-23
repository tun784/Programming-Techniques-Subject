#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

const int MAX_SIZE = 100;
// Hàm tạo ma trận với giá trị ngẫu nhiên trong đoạn [-63, 63]
void taoMaTranNgauNhien(int a[MAX_SIZE][MAX_SIZE], int n) {
    srand(time(0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % 127 - 63;
        }
    }
}
// Hàm xuất ma trận
void xuatMaTran(int a[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}
// Hàm sắp xếp đường chéo phụ giảm dần
void sapXepCheoPhuGiamDan(int a[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][n - i - 1] < a[j][n - j - 1]) {
                swap(a[i][n - i - 1], a[j][n - j - 1]);
            }
        }
    }
}

// Hàm kiểm tra dòng có giá trị giảm dần hay không
bool dongGiamDan(int a[MAX_SIZE][MAX_SIZE], int n, int row) {
    for (int j = 0; j < n - 1; j++) {
        if (a[row][j] < a[row][j + 1]) {
            return false;
        }
    }
    return true;
}
// Hàm liệt kê chỉ số các dòng giảm dần
void lietKeDongGiamDan(int a[MAX_SIZE][MAX_SIZE], int n) {
    bool coDongGiamDan = false;

    cout << "Chi so cac dong chua gia tri giam dan la: ";
    for (int i = 0; i < n; ++i) {
        if (dongGiamDan(a, n, i)) {
            cout << i << " ";
            coDongGiamDan = true;
        }
    }

    if (!coDongGiamDan) {
        cout << "Khong co dong nao gia tri giam dan.";
    }

    cout << endl;
}
// Hàm kiểm tra số chính phương
bool laSoChinhPhuong(int num) {
    int sqrtNum = sqrt(num);
    return sqrtNum * sqrtNum == num;
}
// Hàm xuất tổng số chính phương trong tam giác trên của đường chéo phụ
void xuatTongSoChinhPhuong(int a[MAX_SIZE][MAX_SIZE], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (laSoChinhPhuong(a[i][j])) {
                tong += a[i][j];
            }
        }
    }
    cout << "Tong cac so chinh phuong trong tam giac tren cua duong cheo phu la: " << tong << endl;
}
// Hàm chương trình chính
void bai1Menu() {
    int n;
    cout << "Nhap kich thuoc ma tran vuong (n <= " << MAX_SIZE << "): ";
    cin >> n;

    int maTran[MAX_SIZE][MAX_SIZE];
    cout << "\n----- MENU -----\n";
    cout << "1. Tao va xuat ma tran\n";
    cout << "2. Sap xep gia tri cua cac phan tu tren duong cheo phu giam dan\n";
    cout << "3. Liet ke chi so cac dong chua gia tri giam dan\n";
    cout << "4. Xuat ra tong gia tri cac phan tu la so chinh phuong trong tam giac tren cua duong cheo phu.\n";
    cout << "0. Thoat\n";

    int luaChon;
    do {
        cout << "Nhap lua chon: ";
        cin >> luaChon;

        switch (luaChon) {
        case 1: {
            taoMaTranNgauNhien(maTran, n);
            cout << "Ma tran vua tao:\n";
            xuatMaTran(maTran, n);
        }break;
        case 2: {
            sapXepCheoPhuGiamDan(maTran, n);
            cout << "Ma tran sau khi sap xep cheo phu giam dan:\n";
            xuatMaTran(maTran, n);
        }break;
        case 3:
            lietKeDongGiamDan(maTran, n);
            break;
        case 4:
            xuatTongSoChinhPhuong(maTran, n);
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

// Hàm tính S(x, n) theo cách đệ quy
float tinhS_DeQuy(float x, int n) {
    if (n == 0) {
        return x;
    }
    int f = 1;
    for (int i = 1; i <= n; i++) {
        f *= i;
    }
    return tinhS_DeQuy(x, n - 1) + (float)(pow(x, n)) / f;
}
// Hàm tính S(x, n) theo cách khử đệ quy
float tinhS_KhuDeQuy(float x, int n) {
    float s = x;
    int f = 1;
    for (int i = 1; i <= n; i++) {
        f *= i;
        s += (float)(pow(x, i)) / f;
    }
    return s;
}
// Hàm tính tổng các chữ số chẵn của số nguyên dương n theo cách đệ quy
int tongChuSoChan_DeQuy(int n) {
    if (n == 0) {
        return 0;
    }
    int d = n % 10;
    if (d % 2 == 0) {
        return d + tongChuSoChan_DeQuy(n / 10);
    }
    else {
        return tongChuSoChan_DeQuy(n / 10);
    }
}
// Hàm tính tổng các chữ số chẵn của số nguyên dương n theo cách khử đệ quy
int tongChuSoChan_KhuDeQuy(int n) {
    int s = 0;
    while (n > 0) {
        int d = n % 10;
        if (d % 2 == 0) {
            s += d;
        }
        n /= 10;
    }
    return s;
}
// Hàm tính A[n] theo đệ quy
int tinhA_DeQuy(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    int a = 1, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = i * a + (i - 1) * b;
        a = b;
        b = c;
    }
    return b;
}
// Hàm chương trình chính
void bai2Menu() {
    int luaChon, soN, index, n;
    float x;
    cout << "\n----- MENU -----\n";
    cout << "1. Tinh S(x, n) theo cach de quy\n";
    cout << "2. Tinh S(x, n) theo cach khu de quy\n";
    cout << "3. Tinh tong chu so chan cua so nguyen duong n theo cach de quy\n";
    cout << "4. Tinh tong chu so chan cua so nguyen duong n theo cach khu de quy\n";
    cout << "5. Tinh A[n] theo de quy\n";
    cout << "0. Thoat\n";
    do {
        cout << "Nhap lua chon: ";
        cin >> luaChon;

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
        case 3: {
            cout << "Nhap so nguyen duong n: ";
            cin >> soN;
            cout << "Tong chu so chan theo cach de quy: " << tongChuSoChan_DeQuy(soN) << endl;
        }break;
        case 4: {
            cout << "Nhap so nguyen duong n: ";
            cin >> soN;
            cout << "Tong chu so chan theo cach khu de quy: " << tongChuSoChan_KhuDeQuy(soN) << endl;
        }break;
        case 5: {
            cout << "Nhap gia tri n: ";
            cin >> index;
            cout << "A[" << index << "] = " << tinhA_DeQuy(index) << endl;
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