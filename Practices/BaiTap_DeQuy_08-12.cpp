#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

#define MAX 100
// Bài tập thực hành trên lớp trang 38/59
// S(n) = 1 + 2 + 3 + ... + n
int Sn1(int n){
	if (n == 1)
		return 1;
	return n + Sn1(n - 1);
}
// S(n) = sqrt(5 + sqrt(5 + sqrt(5 + ...)
double Sn2(int n){
	if (n == 1)
		return sqrt(5);
	return sqrt(5 + Sn2(n - 1));
}
// S(n) = 1/2 + 2/3 + ... + n/(n+1)
double Sn3(int n){
	if (n == 1) {
		return 1 / 2.0;
	}
	return Sn3(n - 1) + n / (n + 1.0);
}
// Bài tập thực hành trên lớp trang 42/59
int khoiTaoMang(int arr[], int size){
	srand(time(0));
	int a = 10, b = 99;
	for (int i = 0; i < size; i++){
			arr[i] = a + rand() % (b - a + 1);
	}
	return 1;
}
void inMang(int arr[], int size){
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
}
// 2a. Tính tổng các phần tử chẵn của a
int sumEven(int arr[], int n, int i) {
	if (i >= n)
		return 0;
	if (arr[i] % 2 == 0) {
		return arr[i] + sumEven(arr, n, i + 1);
	}
	else {
		return sumEven(arr, n, i + 1);
	}
}
int main(){
	// Bài tập thực hành trên lớp trang 38/59
	int i, n = 5;
	cout << "\tBai 1\n\tVoi n = " << n << " thi: " << endl;
	// 1
	cout << "S(n) = ";
	for (i = 1; i < n; i++)
		cout << i << " + ";
	cout << n << " = " << Sn1(n) << endl << endl;
	// 2
	cout << "S(n) = ";
	for (i = 1; i<n; i++)
		cout << "sqrt(5 + ";
	cout << "sqrt(5";
	for (i = 1; i <= n; i++)
		cout << ")";
	cout << " = " << Sn2(n) << endl << endl;
	// 3
	cout << "S(n) = ";
	for (i = 1; i<n; i++)
		cout << i << "/" << i + 1 << " + ";
	cout << n << "/" << n + 1;
	cout << " = " << Sn3(n) << endl << endl;

	// 2a. Tính tổng các phần tử chẵn của a
	int arr[MAX];
	cout << "Nhap so phan tu cua mang: ";
	cin >> n;
	khoiTaoMang(arr, n);
	cout << "Mang sau khi tao ";
	inMang(arr, n);
	cout << endl;

	int tongChan = sumEven(arr, n, 0);
	cout << "2a. Tong cac phan tu chan trong mang la: " << tongChan << endl;
	cout <<

		system("pause");
	return 0;
}