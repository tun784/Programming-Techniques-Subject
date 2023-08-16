#include <iostream>
#pragma warning (disable: 4996)

int main() {
    int number_a, number_b;
    std::cout << "Nhap hai so nguyen bat ky: ";

    if (!(std::cin >> number_a >> number_b)) {
        std::cout << "Nhap khong hop le." << std::endl;
        return 1;
    }
    
    try {
        if (number_b != 0) {
            float ketqua = (float) number_a / number_b;
            std::cout << "Ket qua cua " << number_a << "/" << number_b << " = " << ketqua << std::endl;
        }
        else
            throw(number_b);
    }

    catch (int num){
        std::cout << "Ban khong duoc nhap so " << num << std::endl;
    }
    return 0;
}