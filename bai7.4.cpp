#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

class Hang{
private:
    char tenHang[30];
    float donGia;
    int soLuong;
public:
    void nhap();
    void xuat();
    float thanhTien();
};

class Phieu{
private:
    char maPhieu[10];
    char ngayLap[10];
    Hang *dsHang;
    int n;
public:
    void nhap();
    void xuat();
    float tongTien();
};

void Hang::nhap(){
    cout << "Nhap ten hang: ";  fflush(stdin);  gets(tenHang);
    cout << "Nhap don gia: ";   cin >> donGia;
    cout << "Nhap so luong: ";  cin >> soLuong;
}
float Hang::thanhTien(){
    return soLuong*donGia;
}
void Hang::xuat(){
    cout << setw(10) << tenHang;
    cout << setw(10) << donGia;
    cout << setw(10) << soLuong;
    cout << setw(10) << thanhTien() << endl;
}

void Phieu::nhap(){
    cout << "Nhap ma phieu: ";  fflush(stdin);  gets(maPhieu);
    cout << "Nhap ngay lap: ";  fflush(stdin);  gets(ngayLap);
    cout << "Nhap so mat hang: ";   cin >> n;
    dsHang = new Hang[n];
    for(int i = 0; i < n; i++){
        cout << "\tNhap thong tin mat hang thu " << i + 1 << endl;
        dsHang[i].nhap();
    }
}
float Phieu::tongTien(){
    float t = 0;
    for(int i = 0; i < n; i++){
        t += dsHang[i].thanhTien();
    }
    return t;
}
void Phieu::xuat(){
    cout << "=======================================\n";
    cout << "                PHIEU MUA HANG" << endl;
    cout << "Ma phieu: " << maPhieu << "\t\tNgay lap: " << ngayLap << endl;
    cout << setw(10) << "TenHang" << setw(10) << "DonGia" << setw(10) << "SoLuong" << setw(10) << "ThanhTien" << endl;
    for(int i = 0; i < n; i++){
        dsHang[i].xuat();
    }
    cout << "\t\tCong thanh tien: " << tongTien();
}
int main()
{
    Phieu x;
    cout << "Nhap thong tin phieu: " << endl;
    x.nhap();
    x.xuat();
    return 0;
}
