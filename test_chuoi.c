#include <stdio.h>
#include <string.h>

int main ()
{
    // Tìm vị trí đầu tiên của 1 ký tự trong 1 chuỗi và từ vị trí đó cắt ra tới cuối chuỗi.
    const char str1[] = "https://vietjack.com/lap-trinh-c/index.jsp";
    const char ch = '.';
    char *ret;
    ret = strchr(str1, ch);
    printf("Chuoi dang sau dau [%c] la: \n|%s|\n", ch, ret);
    // Tìm vị trí đầu tiên của 1 chuỗi khác trong 1 chuỗi này và từ vị trí đó cắt ra tới cuối chuỗi này.
    char str2[100] = "Day la mot vi du ve ham strstr() trong c, vi du...";
    char *sub;
    sub = strstr(str2, "vi");
    printf("\nChuoi con la: %s\n", sub);
    // Nối chuỗi
    char  ch1 [10] = { 'H' ,  'e' ,  'l' ,  'l' ,  'o' ,  '\0' };
    char  ch2 [10] = { 'C' ,  '\0' };
    strcat(ch1, ch2);
    printf("Gia tri cua chuoi dau tien la: %s va %s", ch1, ch2);
    
    return(0);
}