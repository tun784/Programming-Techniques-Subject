//  Buổi 4
//  Bài tập thực hành về nhà -      Bài 4: Câu 4, 5, 6
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>
#define ROWS 3
#define COLS 3
#define SIZE 1000
void input(char s[]) {
    printf("Nhap chuoi: ");
    fgets(s, SIZE, stdin);
}
void initMatrix(int array[ROWS][COLS], int m, int n) {
    int a = 10, b = 99;
    srand(time(0));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            array[i][j] = a + rand() % (b-a + 1);
}
void printMatrix(int a[ROWS][COLS], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
// Bài 4
// Câu 4  
void sap_xep_ma_tran(int a[][COLS], int m, int n) {
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
					if (a[k][l] < a[min_i][min_j]) {
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
// Câu 5
void di_chuyen_phan_tu(int a[][COLS], int m, int n) {
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
				for (int k = i; k > 0; k--){
					temp = a[k][j];
					a[k][j] = a[k - 1][j];
					a[k - 1][j] = temp;
				}
			}
		}
	}
} 
// Câu 6
int la_doi_xung(int a[][COLS], int m, int n) {
	// khoi tao cac bien .
	int i, j;
	// Duyet qua tat ca cac phan tu  
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++){
			// Neu phan tu tai (i,j) khong bang phan tu tai (n-1-i,j), thi ma tran khong doi xung  
			if (a[i][j] != a[j][i])
				return 0;
		}
	}
	// Neu tat ca cac phan tu deu doi xung thi ma tran doi xung  
	return 1;
}
int main() {
    printf("Bai 4:\n");
    int is_symmetric; // Biến này thay thế cho kiểu dữ liệu bool
	int a[ROWS][COLS] = {
        {56, 72, 64},
        {72, 25, 37},
        {64, 37, 56},
    };
    printMatrix(a, ROWS, COLS);
	is_symmetric = la_doi_xung(a, ROWS, COLS);
    sap_xep_ma_tran(a, ROWS, COLS);
    printf("Sap xep mang sao cho cac phan tu tren cac duong cheo chinh va cac duong cheo song song voi duong cheo chinh tang dan.\n");
    printMatrix(a, ROWS, COLS);
    di_chuyen_phan_tu(a, ROWS, COLS);
    printf("Di chuyen cac phan tu trong ma tran sao cho cac phan tu chan nam o cac dong dau mang, cac phan tu le nam o cac dong cuoi mang.\n");
    printMatrix(a, ROWS, COLS);
	if (is_symmetric)
	    printf("Ma tran doi xung qua duong cheo chinh.\n");
	else
	    printf("Ma tran khong doi xung qua duong cheo chinh.\n");
    
    int b[ROWS][COLS];
    initMatrix(b, ROWS, COLS);
    printMatrix(b, ROWS, COLS);
	is_symmetric = la_doi_xung(b, ROWS, COLS);
    sap_xep_ma_tran(b, ROWS, COLS);
    printf("Sap xep mang sao cho cac phan tu tren cac duong cheo chinh va cac duong cheo song song voi duong cheo chinh tang dan.\n");
    printMatrix(b, ROWS, COLS);
    di_chuyen_phan_tu(b, ROWS, COLS);
    printf("Di chuyen cac phan tu trong ma tran sao cho cac phan tu chan nam o cac dong dau mang, cac phan tu le nam o cac dong cuoi mang.\n");
    printMatrix(b, ROWS, COLS);
	if (is_symmetric)
	    printf("Ma tran doi xung qua duong cheo chinh.\n");
	else
	    printf("Ma tran khong doi xung qua duong cheo chinh.\n");

    getch();
    return 0;
}