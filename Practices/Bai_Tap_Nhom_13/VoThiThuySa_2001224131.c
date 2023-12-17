//  Buổi 4
//  Bài tập thực hành trên lớp -    Bài 1: Câu 1, 2, 3, 4, 5
//  Bài tập thực hành về nhà -      Bài 4: Câu 4, 5, 6
//  Buổi 6
//  Bài tập thực hành trên lớp -    Bài 1, bài 2, bài 3, bài 4, bài 5
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
// Buổi 4 - Bài 1 - Bài tập thực hành trên lớp
// Câu 1
void randomMatrix(int A[][100], int n, int m){
	srand(time(NULL));
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			A[i][j] = rand() % 10;
		}
	}
}
void outputMatrix(int A[][100], int n, int m){
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++)
			printf("%d ", A[i][j]);
		printf("\n");
	}
}

// Câu 2
int tong_tung_dong(int A[][100], int m, int n){
	int sum = 0;
	for (int i=0; i < m; i++){
		for (int j = 0; j < n; j++)
			sum += A[i][j];
		return printf("Tong tung dong %d la: %d\n", i+1, sum);
	}
}
// Câu 3
void Max_cot(int A[][100], int m, int n){
	int max;
	for (int j = 0; j < n; j++){
		max = A[0][j];
		for (int i = 0; i < m; i++)
			if (A[i][j]>max)
				max = A[i][j];
		printf("\nGia tri lon nhat cot %d la: %d\n", j, max);
	}
}
// Câu 4
void Output_pt_duong_bien(int A[][100], int m, int n){
	// biên trên
	for (int j = 0; j < n; j++){
		printf("%d\t", A[0][j]);
	}
	printf("\n");
	// biên giữa
	for (int i = 0; i<m; i++){
		printf("%d\n", A[i][0]);
		for (int j = 1; j < n - 1; j++)
			printf("\t");
		printf("%d", A[i][n - 1]);
	}
	// biên dưới
	if (n>1){
		for (int j = 0; j < n; j++){
			printf("%d\t", A[n-1][j]);
		}
		printf("\n");
	}
}
void Output_cucdai(int A[][100], int m, int n){
	for (int i=0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (A[i][j]>A[i - 1][j] && A[i][j]>A[i + 1][j] && A[i][j]>A[i][j - 1] && A[i][j] > A[i][j + 1]){
				printf("Phan tu cuc dai: A[%d][%d] = %d\n", i, j, A[i][j]);
			}
		}
	}

}
// Bài 4
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
int coDoiXungKhong(int a[][COLS], int m, int n) {
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

// Buổi 6 - Bài 1 - Bài tập thực hành trên lớp
void input(char s[]) {
    printf("Nhap chuoi: ");
    fgets(s, SIZE, stdin);
    fflush(stdin);
}
// Câu 1
void isNumber(char s[]) {
    int m = 0;
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] < 48 || s[i] >57)
            m++;
    if (!m)
        puts("Chuoi toan la chu so");
    else
        puts("Chuoi khong toan la chu so");
}
// Câu 2
void dinhdang(char *s) 
{
    int n = strlen(s);
    int a = 1;
    for (int i = 0; i < n; i++) {
        if (isalpha(s[i])) {
            if (a) {
                s[i] = toupper(s[i]);
                a = 0;
            }
            else
                s[i] = tolower(s[i]);
        }
        else
            a = 1;
    }

}
// Câu 3
void xoa(char s[], int vitrixoa) {
    int n = strlen(s);
    for (int i = vitrixoa; i < n; i++)
        s[i] = s[i + 1];
    s[n - 1] = '\0'; 
}
void chuanHoaChuoi(char* s) {
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
// Câu 4
void timTen(char s[], char a[]) {
    char* result = strstr(s, a);
    if (result != NULL)
        printf("Chuoi ho va ten: %s\n", result);
    else
        printf("Khong tim thay chuoi ho va ten.\n");
}
// Câu 5
void catHoLot_va_Ten(const char* s, char* a, char* b) {
    int i;
    int n = strlen(s);
    int c = -1;
    for (i = n - 1; i >= 0; i--) {
        if (s[i] == ' ') {
            c = i;
            break;
        }
    }

    if (c == -1)
        strcpy(b, "");
    else {
        strncpy(b, s, c);
        b[c] = '\0';
    }
    strcpy(a, s + c + 1);
}
int main() {
    printf("Buoi 4\nBai 1:\n");
    int Array[100][100], m, n, choice;
	printf("Nhap so hang: ");
	scanf("%d", &m);
	printf("Nhap so cot: ");
	scanf("%d", &n);
    printf("\t===== MENU =====\n");
    printf("1. Nhap ma tran ngau nhien va xuat ra man hinf\n");
    printf("2. Tinh tong tung dong\n");
    printf("3. Xuat gia tri lon nhat tung cot\n");
    printf("4. Xuat cac phan tu tren bien\n");
    printf("5. Xuat cac phan tu cuc dai\n");
    printf("0. Thoat\n");
    printf("================\n");
    do {
		printf("Nhap lua chon cua ban: ");
		scanf("%d", &choice);

		switch (choice) {
		case 0:
			printf("Ket thuc chuong trinh.\n");
		case 1:{
			randomMatrix(Array, m, n);
			printf("Nhap ma tran thanh cong!\n");
			printf("Ma tran:\n");
			outputMatrix(Array, m, n);
		}break;
		case 2:{
			tong_tung_dong(Array, m, n);
		}break;
		case 3:{
			Max_cot(Array, m, n);
		}break;
		case 4:{
			Output_pt_duong_bien(Array, m, n);
		}break;
		case 5:{
			Output_cucdai(Array, m, n);
		}break;
		default:
			printf("Lua chon khong hop le. Vui long thu lai!\n");
			break;
		}
	} while (choice != 0);

    printf("Bai 4:\n");
    int doiXung; // Biến này thay thế cho kiểu dữ liệu bool trong C++
	int a[ROWS][COLS] = {
        {56, 72, 64},
        {72, 25, 37},
        {64, 37, 56},
    };
    printMatrix(a, ROWS, COLS);
	doiXung = coDoiXungKhong(a, ROWS, COLS);
    sap_xep_ma_tran(a, ROWS, COLS);
    printf("Sap xep mang sao cho cac phan tu tren cac duong cheo chinh va cac duong cheo song song voi duong cheo chinh tang dan.\n");
    printMatrix(a, ROWS, COLS);
    di_chuyen_phan_tu(a, ROWS, COLS);
    printf("Di chuyen cac phan tu trong ma tran sao cho cac phan tu chan nam o cac dong dau mang, cac phan tu le nam o cac dong cuoi mang.\n");
    printMatrix(a, ROWS, COLS);
	if (doiXung)
	    printf("Ma tran doi xung qua duong cheo chinh.\n");
	else
	    printf("Ma tran khong doi xung qua duong cheo chinh.\n");
    
    int b[ROWS][COLS]; // Thêm 1 ma trận khác làm ví dụ
    initMatrix(b, ROWS, COLS);
    printMatrix(b, ROWS, COLS);
	doiXung = coDoiXungKhong(b, ROWS, COLS);
    sap_xep_ma_tran(b, ROWS, COLS);
    printf("Sap xep mang sao cho cac phan tu tren cac duong cheo chinh va cac duong cheo song song voi duong cheo chinh tang dan.\n");
    printMatrix(b, ROWS, COLS);
    di_chuyen_phan_tu(b, ROWS, COLS);
    printf("Di chuyen cac phan tu trong ma tran sao cho cac phan tu chan nam o cac dong dau mang, cac phan tu le nam o cac dong cuoi mang.\n");
    printMatrix(b, ROWS, COLS);
	if (doiXung)
	    printf("Ma tran doi xung qua duong cheo chinh.\n");
	else
	    printf("Ma tran khong doi xung qua duong cheo chinh.\n");

	char s[SIZE];
    int choice;
    printf("Buoi 6:\nBai 1 (Bai tap thuc hanh tren lop):\n");
    printf("\t==== MENU ====\n");
    printf("1. Kiem tra chuoi co toan chu so hay khong?\n");
    printf("2. Dinh dang chuoi\n");
    printf("3. Xoa khoang trang thua\n");
    printf("4. Tim kiem ho va ten\n");
    printf("5. Tach ho va ten\n");
    printf("0. Thoat chuong trinh\n");
    input(s);

    do {
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
        case 0:
            printf("Ket thuc chuong trinh.\n");
            break;
        case 1:{
            isNumber(s);
        }break;
        case 2:{
            dinhdang(s);
            printf("Chuoi sau khi duoc dinh dang: %s\n", s);
        }break;
        case 3:{
            chuanHoaChuoi(s);
            printf("Chuoi sau khi xoa khoang trang thua: %s\n", s);
        }break;
        case 4:{
            char name[100];
            printf("Nhap chuoi ho va ten can tim: ");
            fflush(stdin);
            fgets(name, SIZE, stdin);
            timTen(s, name);
        }break;
        case 5:{
            char ho[100];
            char ten[100];
            catHoLot_va_Ten(s, ten, ho);
            printf("Ho: %s\n", ho);
            printf("Ten: %s\n", ten);
        }break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
            break;
        }
    } while (choice != 0);
    getch();
    return 0;
}