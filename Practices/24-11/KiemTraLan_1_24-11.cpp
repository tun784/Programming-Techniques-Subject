// Nguyễn Hoàng Tuấn - 2001224555 - tiết 7-11 thứ 6
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

typedef struct CHUYENBAY{
	string maChuyenBay;
	string noiDi;
	string noiDen;
	int thoiGianBay;
	string maPhiCong;
}CHUYENBAY;
CHUYENBAY dscb[10];
int soLuong = 0;
string fileopen = "text.txt";
void doc(CHUYENBAY dscb[], int &soLuong, string fileopen){
	ifstream f(fileopen.c_str());
	if (!f){
		cout << "Khong mo duoc.\n" << endl;
		return;
	}
	int i;
	for (i = 0; f >> dscb[i].maChuyenBay; i++){
		f >> dscb[i].noiDi >> dscb[i].noiDen >> dscb[i].thoiGianBay >> dscb[i].maPhiCong;
		soLuong++;
	}
	cout << "Co " << soLuong << " chuyen bay." << endl;
	f.close();
}
void xuat(CHUYENBAY dscb[], int sl){
	for (int i = 0; i < sl; i++){
		cout << dscb[i].maChuyenBay << " " << dscb[i].noiDi << " " << dscb[i].noiDen << " " << dscb[i].thoiGianBay << " " << dscb[i].maPhiCong << endl;
	}
	cout << endl;
}
int demSoChuyenBay(CHUYENBAY dscb[], int soLuong, string mpc){
	int ketqua = 0;
	for (int i = 0; i < soLuong; i++){
		if (dscb[i].maPhiCong == mpc){
			ketqua++;
		}
	}
	return ketqua;
}
string noiDenHotNhat(CHUYENBAY dscb[], int soLuong){
	string ketqua;
	int maxCount = 0;
	int count;
	for (int i = 0; i < soLuong; i++){
		count = 0;
		for (int j = 0; j < soLuong; j++){
			if (dscb[i].noiDen == dscb[j].noiDen){
				count++;
			}
		}
		if (count > maxCount){
			maxCount = count;
			ketqua = dscb[i].noiDen;
		}
	}
	return ketqua;
}
void lietKe(CHUYENBAY dscb[], int soLuong){
	for (int i = 0; i < soLuong; i++){
		if (i == 0 || dscb[i].maPhiCong != dscb[i - 1].maPhiCong)
			cout << "Ma phi cong: " << dscb[i].maPhiCong << ", so chuyen bay: " << demSoChuyenBay(dscb, soLuong, dscb[i].maPhiCong) << endl;
		cout << dscb[i].maChuyenBay << ", " << dscb[i].noiDi << ", " << dscb[i].noiDen << ", " << dscb[i].thoiGianBay << endl;
		if (i + 1 == soLuong || dscb[i].maPhiCong != dscb[i + 1].maPhiCong)
			cout << endl;
	}
}
int main(){
	doc(dscb, soLuong, fileopen);
	xuat(dscb, soLuong);

	string maphicong;
	cout << "Hay nhap vao Ma phi cong bat ky: ";
	cin >> maphicong;
	int scb = demSoChuyenBay(dscb, soLuong, maphicong);
	if (!scb)
		cout << "Phi cong co ma so " << maphicong << " khong ton tai." << endl << endl;
	else
		cout << "Phi cong co ma so " << maphicong << " da thuc hien " << scb << " chuyen bay." << endl << endl;

	cout << noiDenHotNhat(dscb, soLuong) << " co nhieu chuyen bay bay den do nhat." << endl << endl;

	lietKe(dscb, soLuong);

	cout << endl;

	system("pause");
	return 0;
}

