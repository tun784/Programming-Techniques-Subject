// Nguyễn Hoàng Tuấn - 2001224555
#include <iostream>
#include <math.h>
using namespace std;
int a[4][4] = { { 15, 6, 18, 4 },
				{ 5, 4, 7, 2 },
				{ 1, -2, 15, 7 },
				{ 7, -9, 18, 5 } };
int b[4][4] = { { 9, 6, 18, 4 },
				{ 4, 7, 13, 15 },
				{ 1, -2, 5, 7 },
				{ 7, -9, 18, 5 } };
bool isPrime(int num);
void swap(int &a, int &b);

//void merge(int arr[], int l, int m, int r) {
//	int n1 = m - l + 1;
//	int n2 = r - m;
//	int L[n1], R[n2];
//
//	for (int i = 0; i < n1; i++)
//		L[i] = arr[l + i];
//	for (int j = 0; j < n2; j++)
//		R[j] = arr[m + 1 + j];
//
//	int i = 0;
//	int j = 0;
//	int k = l;
//	while (i < n1 && j < n2) {
//		if (L[i] <= R[j]) {
//			arr[k] = L[i];
//			i++;
//		}
//		else {
//			arr[k] = R[j];
//			j++;
//		}
//		k++;
//	}
//
//	while (i < n1) {
//		arr[k] = L[i];
//		i++;
//		k++;
//	}
//
//	while (j < n2) {
//		arr[k] = R[j];
//		j++;
//		k++;
//	}
//}
//
//void mergeSort(int arr[], int l, int r) {
//	if (l < r) {
//		int m = l + (r - l) / 2;
//
//		mergeSort(arr, l, m);
//		mergeSort(arr, m + 1, r);
//
//		merge(arr, l, m, r);
//	}
//}


int main(){
	cout << "Bai 1" << endl;
	int ma = sizeof(a[0]) / sizeof(a[0][0]);
	int i = 0;
	int max = a[0][0];

	for (i = 0; i < ma; i++){
		if (a[i][i] > max){
			max = a[i][i];
		}
	}
	for (i = 0; i < ma; i++){
		if (a[i][i] == max){
			cout << i << " ";
		}
	}
	cout << endl;

	cout << "Bai 2" << endl;
	int mb = sizeof(b[0]) / sizeof(b[0][0]);
	i = 0;
	int j = 0;

	//for (i = 0; i < mb; i++){
	//	for (j = 0; j < mb; j++){
	//		if (isPrime(b[i][j])){
	//			//mergeSort(b, 0, mb - 1);
	//		}
	//	}
	//}
	for (i = 0; i < mb; i++){
		for (j = 0; j < mb; j++){
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}
bool isPrime(int num){
	if (num < 1)
		return false;
	int dem = 0;
	for (int i = 2; i < num; i++){
		if (num%i == 0)
			dem++;
	}
	if (dem > 0)
		return false;
	return true;
}
