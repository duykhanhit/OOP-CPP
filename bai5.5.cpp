#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

class MayGiat{
private:
    string tenMayGiat;
    string tenHang;
    string loai;
    int khoiLuongGiat;
public:
    void xuat();
    MayGiat(string tenMayGiat, string tenHang, string loai, int khoiLuongGiat);
};

MayGiat::MayGiat(string tenMayGiat, string tenHang, string loai, int khoiLuongGiat){
    {
        this->tenMayGiat = tenMayGiat;
        this->tenHang = tenHang;
        this->loai = loai;
        this->khoiLuongGiat = khoiLuongGiat;
    }
}
void MayGiat::xuat(){
    cout << "=====THONG TIN MAY GIAT======" << endl;
    cout << "Ten may giat: " << tenMayGiat << endl;
    cout << "Ten hang: " << tenHang << endl;
    cout << "Loai: " << loai << endl;
    cout << "Khoi luong giat: " << khoiLuongGiat << " kg" << endl;
}

class TuLanh{
private:
    string tenTu;
    string tenHang;
    int dungTich;
    int namSX;
public:
    void xuat();
    TuLanh(string tenTu, string tenHang, int dungTich, int namSX);
};
TuLanh::TuLanh(string tenTu, string tenHang, int dungTich, int namSX){
    this->tenTu = tenTu;
    this->tenHang = tenHang;
    this->dungTich = dungTich;
    this->namSX = namSX;
}
void TuLanh::xuat(){
    cout << "=====THONG TIN TU LANH======" << endl;
    cout << "Ten mtu lanh: " << tenTu << endl;
    cout << "Ten hang: " << tenHang << endl;
    cout << "Dung tich: " << dungTich << " lit" << endl;
    cout << "Nam san xuat: " << namSX << endl;
}


class ThucPham{
protected:
    char tenTP[30];
    int giaCa;
public:
    void nhap();
    void xuat();
};

void ThucPham::nhap(){
    cout << "Nhap ten: "; fflush(stdin);  gets(tenTP);
    cout << "Nhap gia: ";   cin >> giaCa;
}

void ThucPham::xuat(){
    cout << setw(10) << tenTP;
    cout << setw(10) << giaCa;
}

class TPHOP: public ThucPham{
private:
    int soHop;
public:
    void nhap();
    void xuat();
};

void TPHOP::nhap(){
    ThucPham::nhap();
    cout << "Nhap so hop: ";    cin >> soHop;
}

void TPHOP::xuat(){
    ThucPham::xuat();
    cout << setw(10) << soHop << endl;
}

class TPKHOP: public ThucPham{
private:
    int khoiLuong;
public:
    void nhap();
    void xuat();
};

void TPKHOP::nhap(){
    ThucPham::nhap();
    cout << "Nhap khoi luong: ";    cin >> khoiLuong;
}
void TPKHOP::xuat(){
    ThucPham::xuat();
    cout << setw(15) <<khoiLuong;
}

void title1(){
    cout << setw(10) << "tenTP";
    cout << setw(10) << "giaCa";
    cout << setw(10) << "soHop" << endl;
}
void title2(){
    cout << setw(10) << "tenTP";
    cout << setw(10) << "giaCa";
    cout << setw(15) << "KhoiLuong" << endl;
}


int main()
{
    TPHOP x;
    TPKHOP y;
    MayGiat a = MayGiat("May giat 1","Samsung","cua tren",8);
    a.xuat();
    TuLanh b = TuLanh("Tu lanh 1","Panasonic",200,2020);
    b.xuat();
    cout << "=====NHAP THONG TIN THUC PHAM CO HOP=====" << endl;
    x.nhap();
    cout << "=====NHAP THONG TIN THUC PHAM KO HOP=====" << endl;
    y.nhap();
    cout << "=====THONG TIN THUC PHAM CO HOP=====" << endl;
    title1();
    x.xuat();
    cout << "=====THONG TIN THUC PHAM CO HOP=====" << endl;
    title2();
    y.xuat();
    return 0;
}
