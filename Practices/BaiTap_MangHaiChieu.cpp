// Nguyễn Hoàng Tuấn - 2001224555
#include <iostream>
#include <ctime>
using namespace std;

#define MAX 100
int khoiTaoMang(int Arr[][MAX], int m, int n);
int xuatMang(int Arr[][MAX], int m, int n);
int xuatTongTungDong(int Arr[][MAX], int m, int n);
int phanTuLonNhatTungCot(int Arr[][MAX], int m, int n);
int duongBien(int Arr[][MAX], int m, int n);
int phanTuCucDai(int Arr[][MAX], int m, int n);

int main(){
	int m = 10, n = 10, Arr[MAX][MAX];
	//cout << "Nhap so dong: "; cin >> m;
	//cout << "Nhap so cot: "; cin >> n;
	cout << "Bai 1:" << endl;
	cout << "Cau 1: Xuat mang" << endl;
	khoiTaoMang(Arr, m, n);
	xuatMang(Arr, m, n);

	cout << "\nCau 2: Tinh va xuat tong gia tri tung dong" << endl;
	xuatTongTungDong(Arr, m, n);

	cout << "\nCau 3: Xuat phan tu lon nhat tren tung cot" << endl;
	phanTuLonNhatTungCot(Arr, m, n);
	
	cout << "\nCau 4: Xuat cac phan tu thuoc cac duong bien tren, duoi, trai, phai" << endl;
	duongBien(Arr, m, n);

	cout << "\nCau 5: Xuat cac phan tu cuc dai" << endl;
	phanTuCucDai(Arr, m, n);

	system("pause");
	return 0;
}

// Hàm khởi tạo mảng
int khoiTaoMang(int Arr[][MAX], int m, int n){
	srand(time(0));
	int a = 10, b = 99;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			Arr[i][j] = a + rand() % (b - a + 1);
		}
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
			if (j == 0 || j == n-1)
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