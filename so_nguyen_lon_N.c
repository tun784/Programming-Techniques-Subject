#include<stdio.h>
#include<math.h>

int main()
{
    long N;
    int a, c;
    int tong = 0;
    int max = 0;

    printf("Nhap gia tri N: ");
    scanf("%ld", &N);  // Sửa lỗi: Sử dụng %ld để đọc long

    // Tìm chữ số hàng đầu tiên
    a = N;  // Sửa lỗi: gán a = N để lấy chữ số hàng đầu tiên
    while (a >= 10)
    {
        a = a / 10;
    }

    // Tính tổng các chữ số
    while (N != 0)
    {
        c = N % 10;
        tong += c;
        N /= 10;
    }

    // Tìm chữ số lớn nhất
    N = N;  // Sửa lỗi: Reset N để tìm chữ số lớn nhất
    while (N != 0)
    {
        c = N % 10;
        if (c > max)
        {
            max = c;
        }
        N /= 10;
    }

    // Đếm số chữ số của N
    int scs = 0;
    N = N;  // Sửa lỗi: Reset N để đếm số chữ số
    while (N != 0)
    {
        scs++;
        N /= 10;
    }

    printf("\nChu so hang dau tien cua N la: %d", a);
    printf("\nTong cac chu so cua N la: %d", tong);
    printf("\nChu so lon nhat la: %d", max);
    printf("\nSo chu so la: %d", scs);

    return 0;
}