#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

class hang;

class date {
private:
    int D,M,Y;
public:
    friend class hang;
};

class hang {
private:
    int maHang;
    char tenHang[20];
    date ngaySX;
public:
    void nhap();
    void xuat();
};

// Cac phuong thuc cua class hang

void hang::nhap(){
    cout << "Nhap ma hang: ";           cin >> maHang;
    fflush(stdin);
    cout << "Nhap ten hang: ";          gets(tenHang);
    cout << "Nhap ngay san xuat: ";     cin >> ngaySX.D;
    cout << "Nhap thang san xuat: ";    cin >> ngaySX.M;
    cout << "Nhap nam san xuat: ";      cin >> ngaySX.Y;
}

void hang::xuat(){
    if(ngaySX.Y == 2017)
    cout << setw(5) << maHang << setw(10) << tenHang << setw(15) << ngaySX.D << "/" << ngaySX.M << "/" << ngaySX.Y << endl;
}

int main() {
    int n;
    cout << "Nhap so mat hang: ";   cin >> n;
    hang a[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin mat hang thu " << i + 1 << endl;
        a[i].nhap();
    }
    cout << endl << "===========THONG TIN CAC MAT HANG============" << endl;
    cout << setw(5) << "maHang" << setw(10) << "tenHang" << setw(15) << "ngaySX" << endl;
    for(int i = 0; i < n; i++){
        a[i].xuat();
    }
    return 0;
}
