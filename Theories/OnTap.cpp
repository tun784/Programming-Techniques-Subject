#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std;

int factorial(int n){
    return n < 1 ? 1 : n * factorial(n - 1);
}
int fibonacci(int n){
    return n <= 1 ? n : fibonacci(n - 1) + fibonacci(n - 2);
}
int nCk(int n, int k){
    return (n == k || k == 0) ? 1 : factorial(n) / (factorial(k) * factorial(n - k));
}
int nAk(int n, int k){
    return (n == k || k == 0) ? 1 : factorial(n) / factorial(n - k);
}
int GCD_recursion(int a, int b) {
    if (a == 0)
        return b;
    else if (b == 0)
        return a;
    else
        return GCD_recursion(b, a % b);
}
int GCD(int a, int b){ // khử đệ quy
    if (a < 0)
        a *= -1;
    if (b < 0)
        b *= -1;
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    while (a != b) {
        a > b ? a -= b : b -= a;
    }
    return a;
}
int LCM(int a, int b){
    return (a*b) / GCD(a, b);
}
int isPrime(int x){
    if (x < 2)
        return 0;
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
            return 0;
    return 1;
}
int isSquare(int x){
    if (x < 0)
        return 0;
    int root = sqrt(x);
    return root*root == x ? 1 : 0;
}

// Quick Sort
long partition(long Array[], long left, long right) {
    long pivot = Array[right];
    long i = left - 1;

    for (long j = left; j <= right - 1; j++) {
        if (Array[j] < pivot) {
            i++;
            swap(Array[i], Array[j]);
        }
    }

    swap(Array[i + 1], Array[right]);
    return i + 1;
}
void quickSort(long Array[], long left, long right) {
    if (left < right) {
        long pivot = partition(Array, left, right);

        quickSort(Array, left, pivot - 1);
        quickSort(Array, pivot + 1, right);
    }
}
// Tìm kiểm tuyến tính
long LinearSearch(long Array[], long elementsOfArray, long searchKey) {
    for (long i = 0; i < elementsOfArray; i++)
        if (Array[i] == searchKey)
            return i;
    return -1; //Can't find out
}
// Tìm kiếm nhị phân
long BinarySearch(long Array[], long elementsOfArray, long searchKey) {
    long left = 0;
    long right = elementsOfArray - 1;
    long mid = 0;
    while (left <= right) {
        mid = (left + right) / 2;
        if (Array[mid] == searchKey)
            return mid; //Return position of the data
        else if (Array[mid] > searchKey)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1; //Can't find out
}
int main(){
    int a, b;
    cout << "Nhap so a va so b bat ky: ";
    cin >> a >> b;
    cout << "Ket qua giai thua cua " << a << " la: " << factorial(a) << endl;
    cout << "So Fibonacci cua " << a << " la: " << fibonacci(a) << endl;
    // cout << "Ket qua cua to hop chap " << b << " cua " << a << " phan tu la: " << nCk(a, b) << endl;
    // cout << "Ket qua cua chinh hop chap " << b << " cua " << a << " phan tu la: " << nAk(a, b) << endl;
    cout << "Uoc chung lon nhat cua " << a << " va " << b << " la: " << GCD(a, b) << "(khu de quy), " << GCD_recursion(a, b) << "(de quy). "<< endl;
    cout << "Boi chung nho nhat cua " << a << " va " << b << " la: " << LCM(a, b) << "(khu de quy)."<< endl;
    int boolA = isPrime(a);
    int boolB = isPrime(b);
    boolA == 1 ? cout << "So " << a << " la so nguyen to." << endl : cout << "So " << a << " khong phai la so nguyen to." << endl;
    boolB == 1 ? cout << "So " << b << " la so nguyen to." << endl : cout << "So " << b << " khong phai la so nguyen to." << endl;
    return 0;
}