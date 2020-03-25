#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

class phieu;

class hang{
private:
    int maHang;
    char tenHang[20];
    int donGia;
public:
    void nhap();
    void xuat();
    friend class phieu;
};

class phieu{
private:
    int maPhieu;
    hang x[100];
    int n;
public:
    void nhap();
    void xuat();
};

// Cac phuong thuc class hang

void hang::nhap(){
    cout << "Nhap ma hang: ";   cin >> maHang;
    fflush(stdin);
    cout << "Nhap ten hang: ";  gets(tenHang);
    cout << "Nhap don gia: ";   cin >> donGia;
}
void hang::xuat(){
    cout << setw(5) << maHang << setw(10) << tenHang << setw(10) << donGia << endl;
}

// Cac phuong thuc class phieu

void phieu::nhap(){
    cout << "Nhap ma phieu: ";              cin >> maPhieu;
    cout << "Nhap so luong mat hang: ";     cin >> n;
    cout << "===NHAP THONG TIN CAC MAT HANG===" << endl;
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin mat hang thu " << i + 1 << endl;
        x[i].nhap();
    }
}
void phieu::xuat(){
    cout << "===THONG TIN PHIEU HANG===" << endl;
    cout << "Ma phieu: " << maPhieu << endl;
    cout << setw(5) << "maHang" << setw(10) << "tenHang" << setw(10) << "donGia" << endl;
    for(int i = 0; i < n; i++){
        x[i].xuat();
    }
}
int main()
{
    phieu a;
    a.nhap();
    a.xuat();
    return 0;
}
