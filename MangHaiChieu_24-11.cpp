// Nguyễn Hoàng Tuấn - 2001224555
#include <iostream>
#include <ctime>
#include <math.h>
using namespace std;

#define MAX 100
#define MAX_ROW 10
#define MAX_COL 10
int khoiTaoMang(int Arr[][MAX], int m, int n);
int xuatMang(int Arr[][MAX], int m, int n);
int xuatCacCotSoLe(int Arr[][MAX], int m, int n);
int timMaxPhanTuBien(int Arr[][MAX], int m, int n);
int xuatTongTungDong(int Arr[][MAX], int m, int n);
int phanTuLonNhatTungCot(int Arr[][MAX], int m, int n);
int duongBien(int Arr[][MAX], int m, int n);
int phanTuCucDai(int Arr[][MAX], int m, int n);

int main(){
	int m = MAX_ROW, n = MAX_COL, Arr[MAX][MAX];
	//cout << "Nhap so dong: "; cin >> m;
	//cout << "Nhap so cot: "; cin >> n;
	cout << "Bai 3(page 26/59):" << endl;
	khoiTaoMang(Arr, m, n);
	cout << "Xuat mang" << endl;
	xuatMang(Arr, m, n);

	cout << "Cau 1: Xuat cac cot chi chua so le." << endl;
	xuatCacCotSoLe(Arr, m, n);
	cout << "\nCau 2: Tim phan tu lon nhat trong cac phan tu tren bien cua ma tran." << endl;
	cout << timMaxPhanTuBien(Arr, m, n) << endl;

	cout << "\nCau 3: Trong ma tran co bao nhieu phan tu co chu so 2 xuat hien trong cac chu so cua no." << endl;


	cout << "\nCau 4: Xuat cac phan tu thuoc cac duong bien tren, duoi, trai, phai" << endl;


	cout << "\nCau 5: Xuat cac phan tu cuc dai" << endl;


	system("pause");
	return 0;
}

// Xuất các cột chỉ chứa số lẻ
int xuatCacCotSoLe(int Arr[][MAX], int m, int n){
	int i, j;
	bool isOdd = false;
	for (j = 0; j < n; j++){
		for (int i = 0; i < m; i++)
			if (Arr[i][j] % 2 != 0)
				isOdd = true;
			if (isOdd){
				cout << Arr[i][j] << " ";
			}
	}
	cout << endl;
	return 1;
}
// Tìm phần tử lớn nhất trong các phần tử trên biên của ma trận.
int timMaxPhanTuBien(int Arr[][MAX], int m, int n){
	int i = 0, j = 0, max = Arr[0][0];
	// Tìm trên dòng đầu tiên
	for (j = 0; j < n; j++)
		if (Arr[i][j] > max)
			max = Arr[i][j];
	// tìm trên các cột biên của các dòng dưới
	for (i = 1; i < m - 1; i++){
		for (j = 0; j < n; j++)
			if (j == 0 || j == n - 1)
				if (Arr[i][j] > max)
					max = Arr[i][j];
	}
	i = m - 1;
	for (j = 0; j < n; j++){
		if (Arr[i][j] > max)
			max = Arr[i][j];
	}
	return max;
}
// Trong ma trận có bao nhiêu phần tử có chữ số 2 xuất hiện trong các chữ số của nó.


// Hàm khởi tạo mảng
int khoiTaoMang(int Arr[][MAX], int m, int n){
	srand(time(0));
	int a = 10, b = 99;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++)
			Arr[i][j] = a + rand() % (b - a + 1);
	}
	return 1;
}
// Hàm xuất mảng
int xuatMang(int Arr[][MAX], int m, int n){
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++)
			cout << " " << Arr[i][j];
		cout << endl;
	}
	return 1;
}
// Hàm tính và xuất tổng giá trị từng dòng
int xuatTongTungDong(int Arr[][MAX], int m, int n){
	int sum = 0;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cout << " " << Arr[i][j];
			sum += Arr[i][j];
		}
		cout << " => SUM A[" << i << "][]= " << sum << endl;
		sum = 0;
	}
	return 1;
}
// Hàm xuất phần tử lớn nhất trên từng cột
int phanTuLonNhatTungCot(int Arr[][MAX], int m, int n){
	// Phần xử lý yêu cầu
	int i, j, max;
	int *max_array = new int[n];
	for (j = 0; j < n; j++){
		max = Arr[0][j];
		for (i = 0; i < m; i++){
			if (Arr[i][j] > max)
				max = Arr[i][j];
		}
		max_array[j] = max;
	}
	// Phần xuất ra màn hình
	int x, y;
	for (x = 0; x < m; x++){
		for (y = 0; y < n; y++)
			cout << " " << Arr[x][y];
		cout << endl;
	}
	for (y = 0; y < n; y++){
		cout << " ||";
	}
	cout << endl;
	for (y = 0; y < n; y++){
		cout << " " << max_array[y];
	}
	cout << endl;
	return 1;
}
// Hàm xuất các phần tử thuộc các đường biên trên, dưới, trái, phải
int duongBien(int Arr[][MAX], int m, int n){
	int i = 0, j = 0;
	// In dòng đầu tiên
	for (j = 0; j < n; j++)
		cout << " " << Arr[i][j];
	cout << endl;
	// In các cột biên của các dòng dưới
	for (i = 1; i < m - 1; i++){
		for (j = 0; j < n; j++){
			if (j == 0 || j == n - 1)
				cout << " " << Arr[i][j];
			else{
				cout << "   ";
			}
		}
		cout << endl;
	}
	// In dòng cuối cùng
	i = m - 1;
	for (j = 0; j < n; j++){
		cout << " " << Arr[i][j];
	}
	cout << endl;
	return 1;
}
// Hàm xuất các phần tử cực đại
int phanTuCucDai(int Arr[][MAX], int m, int n){
	int i = 0, j = 0;
	for (i = 0; i < m; i++){
		for (j = 0; j < n; j++){
			// Phần xử lý yêu cầu
			cout << " " << Arr[i][j];
		}
		cout << endl;
	}

	return 1;
}