#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std;
int GiaiThua(int n){
    return n < 1 ? 1 : n * GiaiThua(n - 1);
}
int main(){
    int so;
    cout << "Nhap so bat ky: ";
    cin >> so;
    cout << "Ket qua giai thua cua " << so << " la: " << GiaiThua(so) << endl;
    return 0;
}