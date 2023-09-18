#include <iostream>
#include <cstring>
using namespace std;
#pragma once
void chuanHoaChuoi(string& s){
    string temp = s;
    strncpy(temp, s); //copy s vào biến tạm
    int n = s.length(); //độ dài chuỗi s
    int dau = 0;
    while (temp[dau] = ' ')
        dau++;
    //Xác định vị trí cuối xuất hiện kí tự khác khoảng trắng
    int cuoi = n;
    while (temp[cuoi] == ' ')
        cuoi--;
    // Xoá khoảng trắng dư thừa giữa các từ trong chuỗi
    int j = 0; //chỉ số hiện tại của chuỗi S new
    while (dau <= cuoi){
        while (temp[dau] != ' '){
            s[j] = temp[dau];
            j++;
            dau++;
        }
        while (temp[dau] == ' ' && temp[dau + 1] == ' '){
            dau++;
        }
        s[j] = temp[dau];
        j++;
        dau++;
    }
    s[j-1] = '\0';
    s = temp;
}

void chuanhoachuoi_NQD(string s, int size){
    bool out = true;
    if (s[0] = ' '){
        for (int i = 0; i < size; i++){
            s[i] = s[i + 1];
            out = false;
            size--;
        }
    }
    if (s[size - 1] == ' '){
        s[size - 1] = '\0';
        out = false;
        size--;
    }
    for (int i = 0; i < size; i++){
        if (s[i] != ' ' && s[i+1 == ' ']){
            if (s[i+2] == ' '){
                s[i+2] = '\0';
                for (int j = i + 2; j < size; j++)
                    s[j] = s[j+1];
                out = false;
                size--;
            }
        }
    }

    if (out){
        cout << s;
        return;
    }
    chuanhoachuoi_NQD(s, size);
}