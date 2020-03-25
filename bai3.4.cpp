#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

class phongMay;

class quanLy {
private:
    int maQL;
    char hoTen[20];
public:
    void nhap();
    void xuat();
    friend class phongMay;
};

class may {
private:
    int maMay;
    char kieuMay[20];
    char tinhTrang[20];
public:
    void nhap();
    void xuat();
    friend class phongMay;
};

class phongMay {
private:
    int maPhong;
    char tenPhong[20];
    int dienTich;
    quanLy x;
    may y[100];
    int n;
public:
    void nhap();
    void xuat();
};

// Cac phuong thuc cua class quanLy
void quanLy::nhap(){
    cout << "Nhap ma quan ly: ";    cin >> maQL;
    fflush(stdin);
    cout << "Nhap ho ten: ";        gets(hoTen);
}

void quanLy::xuat(){
    cout << setw(5) << maQL;
    cout << setw(10) << hoTen;
}

// Cac phuong thuc cua class may
void may::nhap(){
    cout << "Nhap ma may: ";        cin >> maMay;
    fflush(stdin);
    cout << "Nhap kieu may: ";      gets(kieuMay);
    fflush(stdin);
    cout << "Nhap tinh trang: ";    gets(tinhTrang);
}

void may::xuat(){
    cout << setw(10) << maMay;
    cout << setw(10) << kieuMay;
    cout << setw(10) << tinhTrang << endl;
}

// Cac phuong thuc cua class phongMay
void phongMay::nhap(){
    cout << "Nhap ma phong: ";  cin >> maPhong;
    cout << "Nhap ten phong: "; cin >> tenPhong;
    cout << "Nhap dien tich: "; cin >> dienTich;
    cout << "===Nhap thong tin nguoi quan ly===" <<endl;
    x.nhap();
    cout << "Nhap so may co trong phong: "; cin >> n;
    cout << "===Nhap thong tin may===" << endl;
    for(int i = 0; i < n; i++){
        cout << "Thong tin may thu " << i + 1 << endl;
        y[i].nhap();
    }
}

void phongMay::xuat(){
    cout << setw(5) << maPhong;
    cout << setw(10) << tenPhong;
    cout << setw(10) << dienTich;
    cout <<  endl << "===Thong tin nguoi quan ly===" << endl;
    cout << setw(5) << "maQL";
    cout << setw(10) << "hoTen" << endl;
    x.xuat();
    cout << endl << "===Thong tin cac may tinh trong phong===" << endl;
    cout << setw(10) << "maMay";
    cout << setw(10) << "kieuMay";
    cout << setw(10) << "tinhTrang" << endl;
    for(int i = 0; i < n; i++){
        y[i].xuat();
    }
}


int main() {
    phongMay a;
    cout << "=============NHHAP THONG TIN=================" << endl;
    a.nhap();
    cout << endl << "============THONG TIN VUA NHAP LA=============" << endl;
    cout << setw(5) << "maPhong";
    cout << setw(10) << "tenPhong";
    cout << setw(10) << "dienTich" << endl;
    a.xuat();
    return 0;
}
