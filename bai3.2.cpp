#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

class hang;

class nsx{
private:
    int maNSX;
    char tenNSX[20];
    char dcNSX[20];
public:
    void nhap();
    void xuat();
    friend class hang;
};

class hang{
private:
    int maHang;
    char tenHang[20];
    nsx x;
public:
    void nhap();
    void xuat();
};

// Cac phuong thuc class nsx
void nsx::nhap(){
    cout << "Nhap ma NSX: ";        cin >> maNSX;
    fflush(stdin);
    cout << "Nhap ten NSX: ";       gets(tenNSX);
    fflush(stdin);
    cout << "Nhap dia chi NSX: ";   gets(dcNSX);
}
void nsx::xuat(){
    cout << setw(10) << maNSX << setw(10) << tenNSX << setw(10) << dcNSX;
}

// Cac phuong thuc class hang

void hang::nhap(){
    cout << "Nhap ma hang: ";   cin >> maHang;
    fflush(stdin);
    cout << "Nhap ten hang: ";  gets(tenHang);
    x.nhap();
}
void hang::xuat(){
    cout << setw(5) << maHang << setw(10) << tenHang;
    x.xuat();
}

int main()
{
    hang a;
    cout << "===NHAP THONG TIN MAT HANG===" << endl;
    a.nhap();
    cout << "===THONG TIN MAT HANG VUA NHAP===" << endl;
    cout << setw(5) << "maHang" << setw(10) << "tenHang" << setw(10) << "maNSX" << setw(10) << "tenNSX" << setw(10) << "dcNSX" << endl;
    a.xuat();
    return 0;
}
