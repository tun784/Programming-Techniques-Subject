// Nguyễn Hoàng Tuấn - 2001224555
#include <iostream>
#include <cmath>
using namespace std;

int Sn1(int n);
double Sn2(int n);
double Sn3(int n);
double Sn4(int n);
double Sn5(int n);
double Sn6(int n);
double Sn7(int n);

int main(){
	int i, n = 5;
	cout << "Bai 1:" << endl << "Voi n = " << n << " thi: " << endl;
	// 1
	cout << "S(n) = ";
	for (i = 1; i < n; i++)
		cout << i << " + ";
	cout << n << " = " << Sn1(n) << endl << endl;
	// 2
	cout << "S(n) = ";
	for (i=1;i<n;i++)
		cout << "sqrt(5 + ";
	cout << "sqrt(5";
	for (i=1;i<=n;i++)
		cout << ")";
	cout << " = " << Sn2(n) << endl << endl;
	// 3
	cout << "S(n) = ";
	for (i=1;i<n;i++)
		cout << i << "/" << i+1 << " + ";
	cout << n << "/" << n+1;
	cout << " = " << Sn3(n) << endl << endl;
	// 4
	cout << "S(n) = ";
	for (i=1;i<n;i++)
		cout << "1/" << 2*i+1 << " + ";
	cout << "1/" << 2*n+1;
	cout << " = " << Sn4(n) << endl << endl;
	// 5
	cout << "S(n) = ";
	for (i=1;i<n;i++)
		cout << i << "*" << i+1 << " + ";
	cout << n << "*" << n+1;
	cout << " = " << Sn5(n) << endl << endl;

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
    else
        return Sn4(n - 1) + 1.0 / (2 * n + 1);
}
// S(n) = 1*2 + 2*3+ 3*4 + 4*5 + ... + n*(n+1)
double Sn5(int n){
    if (n == 1)
        return 2.0;
    else
        return Sn5(n - 1) + n * (n + 1);
}
// S(n) = (1*2!) / (2 + sqrt(3)) + (2*3!) / (3 + sqrt(4)) + (3*4!) / (4 + sqrt(5)) + ⋯ + (n*(n + 1)!) / ( (n + 1) + sqrt(n + 2) )
double Sn6(int n){

}
// S(n) = (1 + sqrt(1 + 2)) / (2 + sqrt(3!)) + (2 + sqrt(2 + 3)) / (3 + sqrt(4!)) + (3 + sqrt(3 + 4)) / (4 + sqrt(5!)) + ⋯ + (n + sqrt(n + n + 1)) / ( (n + 1) + sqrt((n + 2)!) )
double Sn7(int n){

}