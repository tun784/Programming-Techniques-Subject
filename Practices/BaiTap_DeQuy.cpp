// Nguyễn Hoàng Tuấn - 2001224555
#include <iostream>
#include <math.h>
using namespace std;

int Sn1(int n);
double Sn2(int n);
double Sn3(int n);
double Sn4(int n);

int main(){
	int n = 5;
	cout << "Bai 1:" << endl;
	cout << "S(n) = 1 + 2 + 3 + ... + n" << endl;
	cout << "Voi n = " << n << " thi Sn(n)= " << Sn1(n) << endl << endl;

	cout << "S(n) = sqrt(5 + sqrt(5 + sqrt(5 + ...)" << endl;
	cout << "Voi n = " << n << " thi Sn(n)= " << Sn2(n) << endl << endl;

	cout << "S(n) = 1/2 + 2/3 + ... + n/(n+1)" << endl;
	cout << "Voi n = " << n << " thi Sn(n)= " << Sn3(n) << endl << endl;

	cout << "S(n) = 1 + 1/3 + 1/5 + ... + 1/(2n+1)" << endl;
	cout << "Voi n = " << n << " thi Sn(n)= " << Sn4(n) << endl << endl;

	system("pause");
	return 0;
}
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
// S(n) = 1 + 1/3 + 1/5 + ... + 1/(2n+1)
double Sn4(int n){
	if (n == 0)
		return 1.0;
	double m = 1.0 / (2 * n + 1);
	return m + Sn4(n - 1);
}