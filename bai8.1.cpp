#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string.h>

using namespace std;

class NhaCC{
protected:
    char maNCC[10];
    char tenNCC[20];
    char diaChi[15];
    friend class Phieu;
};

class Hang{
protected:
    char tenHang[30];
    float donGia;
    int soLuong;
public:
    void nhap();
    void xuat();
    float thanhTien(){
        return donGia*soLuong;
    }
};

void Hang::nhap(){
    cout << "Nhap ten hang: ";  fflush(stdin);  gets(tenHang);
    cout << "Nhap don gia: ";   cin >> donGia;
    cout << "Nhap so luong: ";  cin >> soLuong;
}
void Hang::xuat(){
    cout << setw(15) << tenHang << setw(10) << donGia << setw(10) << soLuong << setw(15) << thanhTien() << endl;
}

class Phieu{
private:
    char maPhieu[15];
    char ngayLap[15];
    NhaCC ncc;
    Hang hang[100];
    int n;
public:
    void nhap();
    void xuat();
    float tinhTong(){
        float total = 0;
        for(int i = 0; i < n; i++){
            total += hang[i].thanhTien();
        }
        return total;
    }
};

void Phieu::nhap(){
    cout << "Nhap ma phieu: ";  fflush(stdin); gets(maPhieu);
    cout << "Nhap ngay lap: ";  fflush(stdin);  gets(ngayLap);
    cout << "Nhap ma nha cung cap: ";   fflush(stdin);  gets(ncc.maNCC);
    cout << "Nhap ten nha cung cap: ";  fflush(stdin);  gets(ncc.tenNCC);
    cout << "Nhap dia chi nha cung cap: ";  fflush(stdin);  gets(ncc.diaChi);
    cout << "Nhap so mat hang: "; cin >> n;
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin mat hang thu " << i+1 << endl;
            hang[i].nhap();
    }
}

void Phieu::xuat(){
    cout << "             PHIEU NHAP HANG" << endl;
    cout << "Ma phieu: " << maPhieu;
    cout << "\t\tNgay lap: " << ngayLap << endl;
    cout << "Ma NCC: " << ncc.maNCC << "\t\tTen NCC: " << ncc.tenNCC << endl;
    cout << "Dia chi: " << ncc.diaChi << endl;
    cout << setw(15) << "TenHang" << setw(10) << "DonGia" << setw(10) << "SoLuong" << setw(15) << "ThanhTien" << endl;
    for(int i = 0; i < n; i++){
        hang[i].xuat();
    }
    cout << "\t\t\t\tCong thanh tien: " << tinhTong();

}

int main()
{
    Phieu x;
    x.nhap();
    x.xuat();
    return 0;
}

