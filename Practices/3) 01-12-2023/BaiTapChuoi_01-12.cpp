#include <iostream>
#include <string>
using namespace std;
bool kySo(string s);
string ProperCase(string &str);
string chuanHoaChuoi(string &chuoi);
int main(){
	string chuoi;
	cout << "Bai 1: Nhap chuoi: ";
	getline(cin, chuoi);
	cout << "Bai 1: ";
	kySo(chuoi) == true ? cout << "Co chua toan ky so" << endl : cout << "Khong co chua toan ky so" << endl;
	cout << "Bai 2: " << ProperCase(chuoi) << endl;
	cout << "Bai 3: " << chuanHoaChuoi(chuoi) << endl;
	system("pause");
	return 0;
}
// Bài 1. Kiểm tra xem chuỗi s có chứa toàn ký số hay không ?
bool kySo(string s){
	int i = 0;
	bool kyso = true;
	while (s[i] != '\0'){
		if (s[i] < 48 || s[i] > 57){
			kyso = false;
			break;
		}
		i++;
	}
	return kyso;
}
// Bài 2. Viết hàm đổi những kí tự đầu tiên của mỗi từ thành chữ in hoa và những từ không phải đầu câu sang chữ thường.
bool coPhaiChuCaiKhong(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Chuyển đổi kí tự thành chữ in hoa
char inHoa(char &c) {
	if (c >= 'a' && c <= 'z') {
		return c - 'a' + 'A';
	}
	return c;
}
char inThuong(char &c) {
	if (c >= 'A' && c <= 'Z') {
		return c - 'A' + 'a';
	}
	return c;
}
string ProperCase(string &str){
	int len = str.length();
	bool tuMoi = true; // Biến kiểm tra xem có phải là từ mới không

	for (int i = 0; i < len; ++i) {
		// Nếu là kí tự chữ cái và là từ mới, chuyển thành chữ in hoa
		if (coPhaiChuCaiKhong(str[i]) && tuMoi) {
			str[i] = inHoa(str[i]);
			tuMoi = false;
		}
		else if (!isalpha(str[i])) {
			// Nếu là kí tự không phải chữ cái, đánh dấu là từ mới
			tuMoi = true;
		}
		else {
			// Nếu là kí tự chữ cái nhưng không phải từ mới, chuyển thành chữ thường
			str[i] = inThuong(str[i]);
		}
	}

	return str;
}
// Bài 3. Viết hàm xóa những khoảng trắng thừa trong chuỗi(hay còn gọi là chuẩn hóa chuỗi).
string chuanHoaChuoi(string &str) {
	ProperCase(str);
	int len = str.length();
	int index = 0; // Vị trí hiện tại trong chuỗi sau khi xóa khoảng trắng
	bool isKhoangCach = false; // Kiểm tra khoảng trắng thừa

	return str;
}
// Bài 4. Viết hàm tìm kiếm tên trong một chuỗi họ tên.Nếu có thì xuất ra là tên chuỗi họ tên, ngược lại thông báo tên không tồn tại.
// Bài 5. Viết hàm cắt chuỗi họ tên thành 2 chuỗi con : họ lót và tên.
// Ví dụ : chuỗi họ tên là : “Nguyễn Văn Anh” cắt ra 2 chuỗi là chuỗi họ lót : “Nguyễn Văn", chuỗi tên là: "Anh".
// Bài 6. Nhập vào một danh sách sinh viên và hiển thị danh sách sinh viên ra màn hình.Áp dụng giải thuật Brute Force, tìm và xuất vị trí các chuỗi P trong T,
//		a) Với T là chuỗi nhập vào từ bàn phím.
//		b) Với T là chuỗi văn bản đọc từ file text.
