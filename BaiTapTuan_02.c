#include <stdio.h>

// Khai báo các nguyên mẫu hàm
void nhapMang(int a[], int n);
void xuatMang(int a[], int n);
int timMax(int a[], int n);
int timMin(int a[], int n);
int demChan(int a[], int n);
int demLe(int a[], int n);
int timKiemTuyenTinh(int a[], int n, int x);
int timKiemNhiPhan(int a[], int n, int x);
int demPhanTuX(int a[], int n, int x);
int demLonHonX(int a[], int n, int x);
int tinhTong(int a[], int n);
int kiemTraNguyenTo(int num);
int kiemTraHoanThien(int num);
void xuatSoNTvaHoanThien(int a[], int n);
void xuatViTriMaxMin(int a[], int n);
void sapXepTangDan(int a[], int n);
void ghepDay(int b[], int m, int c[], int n, int a[]);
void swap(int* a, int* b);
void interchangeSortAsc(int a[], int n);
void interchangeSortDesc(int a[], int n);

int main() {
    int choice, n, m, x;
    int a[100], b[50], c[50];
    printf("Nhap mang a:\n");
    printf("Nhap so phan tu cua mang: ");
    scanf_s("%d", &n);

    nhapMang(a, n);

    do {
        printf("\nMenu:\n");
        printf("1. Xuat mang\n");
        printf("2. Tim max/min\n");
        printf("3. Dem so phan tu chan/le\n");
        printf("4. Tim kiem phan tu x\n");
        printf("5. Dem phan tu x\n");
        printf("6. Dem phan tu lon hon x\n");
        printf("7. Tinh tong cac phan tu\n");
        printf("8. Xuat so nguyen to va so hoan thien\n");
        printf("9. Xuat vi tri cua max/min\n");
        printf("10. Sap xep mang tang dan\n");
        printf("11. Ghep day b va c thanh a tang dan\n");
        printf("12. Sap xep tang dan theo PP interchange sort\n");
        printf("13. Sap xep giam dan theo PP interchange sort\n");
        printf("0. Thoat\n");

        printf("Nhap lua chon cua ban: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("Mang a: ");
            xuatMang(a, n);
            break;
        case 2:
            printf("Max cua mang: %d\n", timMax(a, n));
            printf("Min cua mang: %d\n", timMin(a, n));
            break;
        case 3:
            printf("So phan tu chan trong mang: %d\n", demChan(a, n));
            printf("So phan tu le trong mang: %d\n", demLe(a, n));
            break;
        case 4:
            printf("Nhap gia tri x can tim: ");
            scanf_s("%d", &x);
            if (timKiemTuyenTinh(a, n, x) != -1) {
                printf("Tim thay phan tu %d tai vi tri %d\n", x, timKiemTuyenTinh(a, n, x));
            }
            else {
                printf("Khong tim thay phan tu %d trong mang\n", x);
            }
            if (timKiemNhiPhan(a, n, x) != -1) {
                printf("Tim thay phan tu %d tai vi tri %d (su dung tim kiem nhi phan)\n", x, timKiemNhiPhan(a, n, x));
            }
            else {
                printf("Khong tim thay phan tu %d trong mang (su dung tim kiem nhi phan)\n", x);
            }
            break;
        case 5:
            printf("Nhap gia tri x can dem: ");
            scanf_s("%d", &x);
            printf("So lan xuat hien cua phan tu %d trong mang: %d\n", x, demPhanTuX(a, n, x));
            break;
        case 6:
            printf("Nhap gia tri x can so sanh: ");
            scanf_s("%d", &x);
            printf("So phan tu lon hon %d trong mang: %d\n", x, demLonHonX(a, n, x));
            break;
        case 7:
            printf("Tong cac phan tu trong mang: %d\n", tinhTong(a, n));
            break;
        case 8:
            xuatSoNTvaHoanThien(a, n);
            break;
        case 9:
            xuatViTriMaxMin(a, n);
            break;
        case 10:
            sapXepTangDan(a, n);
            printf("Mang sau khi sap xep tang dan: ");
            xuatMang(a, n);
            break;
        case 11:
            printf("Nhap so phan tu cua mang b: ");
            scanf_s("%d", &m);
            printf("Nhap mang b:\n");
            nhapMang(b, m);
            printf("Nhap so phan tu cua mang c: ");
            scanf_s("%d", &m);
            printf("Nhap mang c:\n");
            nhapMang(c, m);
            ghepDay(b, m, c, n, a);
            printf("Mang sau khi ghep va sap xep tang dan: ");
            xuatMang(a, n + m);
            break;
        case 12:
            interchangeSortAsc(a, n);
            printf("Mang sau khi sap xep tang dan: ");
            xuatMang(a, n);
            break;
        case 13:
            interchangeSortDesc(a, n);
            printf("Mang sau khi sap xep giam dan: ");
            xuatMang(a, n);
            break;
        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Moi nhap lai.\n");
        }
    } while (choice != 0);

    return 0;
}

void nhapMang(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("Nhap phan tu a[%d]: ", i);
        scanf_s("%d", &a[i]);
    }
}
// Bài 1
void xuatMang(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int timMax(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

int timMin(int a[], int n) {
    int min = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

int demChan(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

int demLe(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 != 0) {
            count++;
        }
    }
    return count;
}

int timKiemTuyenTinh(int a[], int n, int x) {
    for (int i = 0; i < n; ++i) {
        if (a[i] == x) {
            return i; // Trả về vị trí x nếu tìm thấy
        }
    }
    return -1; // Trả về -1 nếu không tìm thấy
}

int timKiemNhiPhan(int a[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x) {
            return mid; // Trả về vị trí x nếu tìm thấy
        }
        if (a[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1; // Trả về -1 nếu không tìm thấy
}

int demPhanTuX(int a[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == x) {
            count++;
        }
    }
    return count;
}

int demLonHonX(int a[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > x) {
            count++;
        }
    }
    return count;
}

int tinhTong(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }
    return sum;
}

int kiemTraNguyenTo(int num) {
    if (num <= 1) {
        return 0; 
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return 0; 
        }
    }
    return 1; // Là số nguyên tố
}

int kiemTraHoanThien(int num) {
    int sum = 0;
    for (int i = 1; i <= num / 2; ++i) {
        if (num % i == 0) {
            sum += i;
        }
    }
    if (sum == num) {
        return 1; // Là số hoàn thiện
    }
    return 0; // Không phải số hoàn thiện
}

void xuatSoNTvaHoanThien(int a[], int n) {
    printf("Cac so nguyen to trong mang: ");
    for (int i = 0; i < n; ++i) {
        if (kiemTraNguyenTo(a[i])) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");

    printf("Cac so hoan thien trong mang: ");
    for (int i = 0; i < n; ++i) {
        if (kiemTraHoanThien(a[i])) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

void xuatViTriMaxMin(int a[], int n) {
    int max = timMax(a, n);
    int min = timMin(a, n);

    printf("Gia tri max: %d, vi tri: ", max);
    for (int i = 0; i < n; ++i) {
        if (a[i] == max) {
            printf("%d ", i);
        }
    }
    printf("\n");

    printf("Gia tri min: %d, vi tri: ", min);
    for (int i = 0; i < n; ++i) {
        if (a[i] == min) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void sapXepTangDan(int a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void ghepDay(int b[], int m, int c[], int n, int a[]) {
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (b[i] < c[j]) {
            a[k++] = b[i++];
        }
        else {
            a[k++] = c[j++];
        }
    }
    while (i < m) {
        a[k++] = b[i++];
    }
    while (j < n) {
        a[k++] = c[j++];
    }
}

// Bài 2
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm sắp xếp tăng dần theo interchange sort
void interchangeSortAsc(int a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] > a[j]) {
                swap(&a[i], &a[j]);
            }
        }
    }
}

// Hàm sắp xếp giảm dần theo interchange sort
void interchangeSortDesc(int a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] < a[j]) {
                swap(&a[i], &a[j]);
            }
        }
    }
}