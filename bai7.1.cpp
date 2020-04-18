#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>

using namespace std;

class NSX{
private:
    char tenNSX[30];
    char diaChi[30];
public:
    void nhap();
    void xuat();
    friend class HANG;
};

class HANG{
protected:
    char tenHang[30];
    NSX x;
    float donGia;
public:
    void nhap();
    void xuat();
    HANG();
};

class DATE{
private:
    int d, m, y;
public:
    void nhap();
    void xuat();
    friend class TIVI;
};
class TIVI:public HANG{
private:
    float kichThuoc;
    DATE ngayNhap;
public:
    void nhap();
    void xuat();
    TIVI();
};

void NSX::nhap(){
    cout << "Nhap ten NSX: ";   fflush(stdin);  gets(tenNSX);
    cout << "Nhap dia chi NSX: ";   fflush(stdin);  gets(diaChi);
}
void NSX::xuat(){
    cout << setw(15) << tenNSX;
    cout << setw(15) << diaChi;
}

void HANG::nhap(){
    cout << "Nhap ten hang: ";  fflush(stdin);  gets(tenHang);
    cout << "Nhap thong tin NSX: " << endl;
    x.nhap();
    cout << "Nhap don gia: ";   cin >> donGia;
}
void HANG::xuat(){
    cout << setw(10) << tenHang;
    cout << setw(10) << donGia;
    x.xuat();
}

HANG::HANG(){
    strcpy(tenHang,"Tivi");
    donGia = 1000;
    strcpy(x.tenNSX,"Sony");
    strcpy(x.diaChi,"japan");
}

void DATE::nhap(){
    cout << "Nhap ngay: "; cin >> d;
    cout << "Nhap thang: "; cin >> m;
    cout << "Nhap nam: ";   cin >> y;
}
void DATE::xuat(){
    cout << setw(10) << d << "/" << m << "/" << y;
}

void TIVI::nhap(){
    HANG::nhap();
    cout << "Nhap kich thuoc: ";    cin >> kichThuoc;
    cout << "Nhap ngay nhap: ";
    ngayNhap.nhap();
}
void TIVI::xuat(){
    HANG::xuat();
    cout << setw(10) << kichThuoc << " inches";
    ngayNhap.xuat();
}

TIVI::TIVI(){
    HANG();
    kichThuoc = 52;
    ngayNhap.d = 1;
    ngayNhap.m = 1;
    ngayNhap.y = 2020;
}
int main()
{
    TIVI a;
    cout << "=========NHAP THONG TIN TIVI===========" << endl;
    a.nhap();
    cout << "=========THONG TIN TIVI VUA NHAP===========" << endl;
    cout << setw(10) << "tenHang";
    cout << setw(10) << "donGia";
    cout << setw(15) << "tenNSX";
    cout << setw(15) << "diaChi";
    cout << setw(17) << "kichThuoc";
    cout << setw(17) << "ngayNhap" << endl;
    a.xuat();
    return 0;
}
