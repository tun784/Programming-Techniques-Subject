#include <stdio.h>
#include <stdlib.h>
#define file_input "Input.txt"
#define MAX 100
int main(){
    // 1. Viết chương trình nhập 2 số thực bất kỳ a, b. Tạo 2 con trỏ pa và pb trỏ đến a, b. Xuất giá trị các con trỏ trên.
    int a = 0, b = 1;
    int *pa = &a, *pb = &b;

    printf("Gia tri cua cac con tro tren la: %d va %d\n",pa, pb);

    // 2. Tạo mảng 1 chiều a chứa n phần tử.
    // a) Tìm max của a, xuất ra max và địa chỉ của max thông qua con trỏ mảng.
    int sizeOfArray;
    int array[MAX];
    int *max, *min; // Địa chỉ của phần tử max và min
    FILE *file = fopen(file_input, "r");
    if (!file){
        printf("Khong the mo duoc tep tin.\n");
        return 0;
    }
    fscanf(file, "%d", &sizeOfArray);
    if (sizeOfArray < 1){
        printf("Kich thuoc mang khong hop le.\n");
        return 0;
    }
    for (int i = 0; i < sizeOfArray; i++)
        fscanf(file, "%d", &array[i]);
    max = &array[0];
    for (int i = 0; i < sizeOfArray; i++)
        if (array[i] > *max)
            max = &array[i];

    printf("Gia tri toi da cua mang la %d va co dia chi la %d\n",*max, max);
    
    // b) Xuất địa chỉ của phần tử max và min
    min = &array[0];
    for (int i = 0; i < sizeOfArray; i++)
        if (array[i] < *min)
            min = &array[i];

    printf("Dia chi phan tu max la %d va dia chi phan tu min la %d\n", max, min);
    fclose(file);
    return 0;
}