#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
// Câu 2b
void sapXep(int a[][10], int n){
    for (int j = 0; j < n; j++){
        for (int i = 1; i < n; i++)
            if (a[i][j] < a[i - 1][j])
                swap(a[i][j], a[i - 1][j]);
    }
}
// Câu 4a
int U(int a, int r, int n){
    if (n == 1)
        return 1;
    if (n > 1)
        return U(a, r, n - 1) * r;
}
// Câu 4b, đệ quy
int giaiThua(int n){
    return n == 1 ? 1 : n * giaiThua(n - 1);
}
int S(int n){
    if (n == 1)
        return (-1)*((1*2) / giaiThua(2));
    else
        return pow(-1, n) * (((2*n-1) * (2*n)) / giaiThua(2*n));
}
// Câu 3a
typedef struct QUANGCAO{
    int chieuRong;
    int chieuDai;
    char noiDung[50];
    char mauSac[10];
}QUANGCAO;
// Câu 3b
int giaThanh(QUANGCAO qc){
    return qc.chieuDai * qc.chieuRong * 20;
}
// Câu 3c
int mauSac(QUANGCAO qc[], int n){
    int count = 0;
    for (int i = 0; i < n; i++){
        if (strcmp(qc[i].mauSac, "Xanh") == 0)
            count++;
    }
    return count;
}
// Câu 3d
void dienTich(QUANGCAO qc[], int n){
    int viTri, max = qc[0].chieuDai * qc[0].chieuRong;
    for (int i = 0; i < n; i++){
        if (max < qc[i].chieuDai * qc[i].chieuRong)
            viTri = i;
    }
    cout << qc[viTri].chieuRong << " " << qc[viTri].chieuDai << " " << qc[viTri].noiDung << " " << qc[viTri].mauSac << endl;
}
int main(){
    QUANGCAO qc[3];
    return 0;
}