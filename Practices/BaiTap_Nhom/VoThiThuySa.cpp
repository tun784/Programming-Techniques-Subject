//  Bài tập thực hành trên lớp -    Bài 1: Câu 1, 2, 3, 4, 5
//  Bài tập thực hành về nhà -      Bài 4: Câu 4, 5, 6
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define MAXROW 3
#define MAXCOL 3
void input(char s[]) {
    printf("Nhap chuoi: ");
    gets(s);
}
// Bài 1
//1
void isNumber(char s[]) {
    int m = 0;
    for (int i = 0; s[i] != '\0'; i++)
	 {
        if (s[i] < 48 || s[i] >57) 
		{
            m++;
        }
    }
    if (!m) 
	{
        puts("Chuoi toan la chu so");
    }
    else 
	{
        puts("Chuoi khong toan la chu so");
    }
}
//2
void dinhdang(char*s) 
{
    int n = strlen(s);
    int a = 1;
    for (int i = 0; i < n; i++) 
	{
        if (isalpha(s[i])) 
		{
            if (a) 
			{
                s[i] = toupper(s[i]);
                a = 0;
            }
            else 
			{
                s[i] = tolower(s[i]);
            }
        }
        else 
		{
            a = 1;
        }
    }

}
//3
void xoa(char s[90], int vitrixoa)
{
    int n = strlen(s);
    for (int i = vitrixoa; i < n; i++)
        s[i] = s[i + 1];
    s[n - 1] = '\0'; 
}
void xoakt(char* s)
{
    for (int i = 0; i < strlen(s); i++)
        if (s[i] == ' ' && s[i + 1] == ' ')
        {
            xoa(s, i);
            i--;
        }
    if (s[0] == ' ')
        xoa(s, 0);
    if (s[strlen(s) - 1] == ' ')
        xoa(s, strlen(s) - 1);
}
//4
void searchAndPrintName(char s[], char a[])
 {
    char* result = strstr(s, a);
    if (result != NULL) {
        printf("Chuoi ho va ten: %s\n", result);
    }
    else 
	{
        printf("Khong tim thay chuoi ho va ten.\n");
    }
}
//5
void catholotvaten(const char* s, char* a, char* b) 
{
    int i;
    int n = strlen(s);
    int c = -1;
    for (i = n - 1; i >= 0; i--) 
	{
        if (s[i] == ' ') 
		{
            c = i;
            break;
        }
    }

    if (c == -1) {
        strcpy(b, "");
    }
    else {
        strncpy(b, s, c);
        b[c] = '\0';
    }
    strcpy(a, s + c + 1);
}
// Bài 4
//4  
void sap_xep_ma_tran(int a[MAXROW][MAXCOL], int& m, int& n) 
{
	// Khoi tao bien  
	int i, j, min_i, min_j;
	// Duyet qua tat ca cac phan tu .
	for (i = 0; i < n; i++) 
	{
		for (j = 0; j < n; j++)
		 {
			// Tim phan tu nho nhat trong phan tu hien tai  
			min_i = i;
			min_j = j;
			for (int k = i; k < n; k++)
			 {
				for (int l = j; l < n; l++) 
				{
					if (a[k][l] < a[min_i][min_j]) 
					{
						min_i = k;
						min_j = l;
					}
				}
			}
			// sap xep cac phan tu hien tai  
			if (min_i != i || min_j != j) 
			{
				int temp = a[i][j];
				a[i][j] = a[min_i][min_j];
				a[min_i][min_j] = temp;
			}
		}
	}
}
// 5
void di_chuyen_phan_tu(int a[MAXROW][MAXCOL], int& m, int& n)
 {
	// khoi tao cac bien  
	int i, j, temp;
	// Duyet qua tat ca cac dong  
	for (i = 0; i < n; i++) 
	{
		// Duyet qua tat ca cac phan tu trong dong  
		for (j = 0; j < n; j++) 
		{
			// Neu phan tu la chan thi chuyen phan tu do den dong dau 
			if (a[i][j] % 2 == 0) 
			{
				for (int k = i; k > 0; k--)
				 {
					temp = a[k][j];
					a[k][j] = a[k - 1][j];
					a[k - 1][j] = temp;
				}
			}
		}
	}
} 
// 6
bool la_doi_xung(int a[MAXROW][MAXCOL], int m, int n) 
{
	// khoi tao cac bien .
	int i, j;
	// Duyet qua tat ca cac phan tu  
	for (i = 0; i < n; i++) 
	{
		for (j = 0; j < n; j++)
		 {
			// Neu phan tu tai (i,j) khong bang phan tu tai (n-1-i,j), thi ma tran khong doi xung  
			if (a[i][j] != a[n - 1 - i][j])
				return false;
		}
	}
	// Neu tat ca cac phan tu deu doi xung thi ma tran doi xung  
	return true;
}
int main() {
    char s[1000];
    int choice;
    do {
        printf("\n==== MENU ====\n");
        printf("1. Kiem tra chuoi co toan chu so hay khong\n");
        printf("2. Dinh dang chuoi\n");
        printf("3. Xoa khoang trang thua\n");
        printf("4. Tim kiem ho va ten\n");
        printf("5. Tach ho va ten\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        fflush(stdin); 
        switch (choice)
		 {
        case 0:
            printf("Ket thuc chuong trinh.\n");
            break;
        case 1:
            input(s);
            isNumber(s);
            break;
        case 2:
            input(s);
            dinhdang(s);
            printf("Chuoi sau khi duoc dinh dang: %s\n", s);
            break;
        case 3:
            input(s);
            xoakt(s);
            printf("Chuoi sau khi xoa khoang trang thua: %s\n", s);
            break;
        case 4:
		 {
            char name[100];
            input(s);
            printf("Nhap chuoi ho va ten can tim: ");
            fflush(stdin);
            gets(name);
            searchAndPrintName(s, name);
            break;
        }
        case 5: 
		{
            char ho[100];
            char ten[100];
            input(s);
            catholotvaten(s, ten, ho);
            printf("Ho: %s\n", ho);
            printf("Ten: %s\n", ten);
            break;
        }
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
            break;
        }
    } while (choice != 0);

	int a[MAXROW][MAXCOL] = {
	{1, 2, 3},
	{2, 3, 1},
	{3, 1, 2}, };
	bool is_symmetric = la_doi_xung(a, MAXROW, MAXCOL);
	if (is_symmetric)
	    printf("Ma tran doi xung \n");
	else
	    printf("Ma tran khong doi xung \n");

    getch();
    return 0;
}