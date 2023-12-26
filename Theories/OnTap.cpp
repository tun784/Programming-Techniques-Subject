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
int main(){
    int a, b;
    cout << "Nhap so a va so b bat ky: ";
    cin >> a >> b;
    cout << "Ket qua giai thua cua " << a << " la: " << factorial(a) << endl;
    cout << "So Fibonacci cua " << a << " la: " << fibonacci(a) << endl;
    cout << "Ket qua cua " << a << " chap " << b << " la: " << nCk(a, b);
    return 0;
}