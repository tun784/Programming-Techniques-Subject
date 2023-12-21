#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
using namespace std;
const int ROWS = 4;
const int COLS = 3;
void inMaTran(int array[][COLS], int hang, int cot) {
	for (int i = 0; i < hang; i++) {
		for (int j = 0; j < cot; j++) {
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}
void cau1(int a[][COLS], int hang, int cot){
	int q = 0, i = 0, j = 0, k;
	bool ketqua = true;
	for (j = 0; j < cot; j++) {
		q = a[1][j] - a[0][j];
		ketqua = true;
		for (i = 1; i < hang; i++) {
			k = a[i][j] - a[i - 1][j];
			if (q != k){
				ketqua = false;
				break;
			}
		}
		if (ketqua)
			cout << "cot " << j << " ";
	}
	cout << endl;
}
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}
int par(int a[], int l, int r){
	int p = a[r];
	int i = l - 1;

	for (int j = l; j < r; j++){
		if (a[j] <= p){
			i++;
			swap(a[i], a[j]);
		}
	}

	swap(a[i + 1], a[r]);
	return i + 1;
}
void quickSort(int a[], int l, int r){
	if (l < r){
		int pivot = par(a, l, r);
		quickSort(a, l, pivot - 1);
		quickSort(a, pivot + 1, r);
	}
}
void cau2(int a[][COLS], int n){
	int i = 0, max = a[0][0];
	for (i = 0; i < n; i++)
	if (max < a[i][i])
		max = a[i][i];
	for (i = 0; i < n; i++)
	if (max == a[i][i])
		quickSort(a[i], 0, n - 1);
}
void cau3(string &str, int n){
	if (n >= str.length())
		str = "";
	else
		str.erase(str.end() - n, str.end());
}
bool isPrime(int num){
	if (num <= 1)
		return false;
	int dem = 0;
	for (int i = 2; i <= num / 2; i++)
	if (num%i == 0)
		return false;
	return true;
}
bool coChuSoHangChucLaMot(int n){
	if (n < 10)
		return false;
	int h = (n / 10) % 10;
	return h == 1;
}
bool demSNTcochusomot(int a[], int n){
	if (n == 0)
		return 0;
	int snt_hientai = isPrime(a[n - 1]) ? 1 : 0;
	int snt_conlai = demSNTcochusomot(a, n - 1);
	return snt_hientai + snt_conlai;
}

typedef struct LUANVAN{
	string MaLuanVan;
	string ChuyenNganh;
	string GVHD;
	int TinhTrang;
};
void flushFile(ifstream& f) {
	char c;
	while (f.get(c) && c != '\n' && c != ifstream::traits_type::eof());
}
void docFile(LUANVAN a[], int& n, char file_input[]) {
	ifstream file;
	file.open(file_input);
	if (!file)
	{
		cout << "Khong mo duoc." << endl;
		system("pause");
	}
	file >> n;
	for (int i = 0; i < n; i++){
		file >> a[i].ChuyenNganh;
		file >> a[i].GVHD;
		file >> a[i].MaLuanVan;
		file >> a[i].TinhTrang;
	}
	file.close();
}
void in(LUANVAN a[], int n){
	for (int i = 0; i < n; i++){
		cout << a[i].ChuyenNganh << endl;
		cout << a[i].GVHD << endl;
		cout << a[i].MaLuanVan << endl;
		cout << a[i].TinhTrang << endl;
	}
}
int main(){
	cout << "Cau 1:" << endl;
	int a[ROWS][COLS] = {
		{ 4, 8, 6 },
		{ 9, 4, 7 },
		{ 14, 2, 8 },
		{ 19, 8, 9 } };
	cout << "Ma tran:" << endl;
	inMaTran(a, ROWS, COLS);
	cau1(a, ROWS, COLS);

	int b[COLS][COLS] = {
		{ 9, 8, 8 },
		{ 6, 9, 4 },
		{ 3, 2, 1 } };
	cout << "Cau 2:" << endl;
	cau2(b, COLS);
	inMaTran(b, COLS, COLS);

	cout << "Cau 3:" << endl;
	string c = "Truong lang em be be, nam lan giua rung cay";
	cout << c << endl;
	int n;
	cout << "Nhap n= ";
	cin >> n;
	cau3(c, n);
	cout << c << endl;

	cout << "Cau 4:" << endl;
	int mang[5] = { 11, 23, 47, 52, 19 };
	cout << "So luong so nguyen to co chua so 1 hang chuc la: " << demSNTcochusomot(mang, 5) << endl;

	cout << "Cau 6:" << endl;
	LUANVAN lv[6];
	int size = 0;
	char file_input[] = "text.txt";
	docFile(lv, size, file_input);
	in(lv, size);
	system("pause");
	return 0;
}