#include<stdio.h>
#include<math.h>

int main()
{
    long N, n, a, c;
    int tong = 0, max = 0;

    printf("Nhap gia tri N: ");
    scanf("%ld", &N);
    n = N;
    // Tìm chữ số hàng đầu tiên
    a = N;  // Gán a = N để lấy chữ số hàng đầu tiên
    while (a >= 10) {
        a = a / 10;
    }

    // Tính tổng các chữ số
    while (N != 0){
        c = N % 10;
        tong += c;
        N /= 10;
    }

    // Tìm chữ số lớn nhất
    N = n;  // Reset N để tìm chữ số lớn nhất
    while (N != 0){
        c = N % 10;
        if (c > max)
            max = c;
        N /= 10;
    }

    // Đếm số chữ số của N
    int soChuSo = 0;
    N = n;  // Reset N để đếm số lượng chữ số
    while (N != 0) {
        soChuSo++;
        N /= 10;
    }

    printf("\nChu so hang dau tien cua N la: %d", a);
    printf("\nTong cac chu so cua N la: %d", tong);
    printf("\nChu so lon nhat la: %d", max);
    printf("\nSo chu so la: %d", soChuSo);

    return 0;
}