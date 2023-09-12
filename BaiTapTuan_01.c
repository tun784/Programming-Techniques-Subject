// Các thành viên trong nhóm chúng em gồm:
// 1. Cao Nhật Linh - 2001215911
// 2. Trần Thị Trúc - 2001216252
// 3. Nguyễn Hoàng Tuấn - 2001224555
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//#pragma warning(disable: 4996)
#define file_input "Input.txt"
#define MAX 100

int main(){
    // 1. Viết chương trình nhập 2 số thực bất kỳ a, b. Tạo 2 con trỏ pa và pb trỏ đến a, b. Xuất giá trị các con trỏ trên.
    int a = 0, b = 1;
    int *pa = &a, *pb = &b;

    printf("Gia tri cua cac con tro tren la: %d va %d\n",pa, pb);

    // 2. Tạo mảng 1 chiều a chứa n phần tử.
    // a) Tìm max của a, xuất ra max và địa chỉ của max thông qua con trỏ mảng.
    // b) Xuất địa chỉ của phần tử max và min
    
    // a)
    int sizeOfArray; // Biến để lưu kích thước mảng
    int array[MAX]; // Mảng số nguyên có giới hạn là MAX
    int *max, *min; // Địa chỉ của phần tử max và min
    FILE *file = fopen(file_input, "r");
    if (!file){
        printf("Khong the mo duoc tep tin.\n"); // Kiểm tra xem có mở được tệp hay không
        return 0;
    }
    fscanf(file, "%d", &sizeOfArray);
    if (sizeOfArray < 1){
        printf("Kich thuoc mang khong hop le.\n"); // Bắt lỗi kích thước mạng có hợp lệ không
        return 0;
    }
    for (int i = 0; i < sizeOfArray; i++)
        fscanf(file, "%d", &array[i]);
    fclose(file); // Ghi từng dữ liệu trong tệp tin vào từng phần tử trong mảng
    
    max = &array[0];
    for (int i = 0; i < sizeOfArray; i++)
        if (array[i] > *max)
            max = &array[i]; // Gán max = phần tử đầu, và duyệt từng phần tử trong mảng
                            // Phần tử nào lớn hơn max thì gán giá trị đó vào max
    printf("Gia tri toi da cua mang la %d va co dia chi la %d\n",*max, max);

    min = &array[0];
    for (int i = 0; i < sizeOfArray; i++)
        if (array[i] < *min)
            min = &array[i]; // Gán min = phần tử đầu, và duyệt từng phần tử trong mảng
                            // Phần tử nào nhỏ hơn min thì gán giá trị đó vào min
    printf("Dia chi phan tu max (co gia tri la %d): [%d] va dia chi phan tu min (co gia tri la %d): [%d]\n", *max, max, *min, min);

    // 3. Viết chương trình nhập vào chuỗi st. Xuất giá trị từng ký tự của st thông qua con trỏ trỏ đến chuỗi.
    int limit;
    char st[MAX];
    printf("Nhap mot chuoi bat ky: ");
    fgets(st, sizeof(st), stdin); // Đọc cả dòng text, bao gồm cả dấu cách
    size_t length = strlen(st);
    if (length > 0 && st[length - 1] == '\n') // Kiểm tra xem chuỗi có bất cứ thứ gì bên trong
        st[length - 1] = '\0'; // Xoá dấu xuống dòng của chuỗi
    limit = strlen(st); // Kiểm tra độ dài chuỗi
    printf("Do dai cua chuoi la %d\n", limit);

    char *c;
    printf("Tung ky tu trong chuoi %s la:", st);
    for (int i = 0 ; i < limit; i++){
        c = &st[i]; // Con trỏ trỏ đến chuỗi và duyệt từng ký tự của chuỗi đó
        printf(" %c", *c);
    }
    
    return 0;
}