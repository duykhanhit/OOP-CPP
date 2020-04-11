#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

class SinhVien{
protected:
    char hoTen[30];
    int soBaoDanh;
public:
    void nhap();
    void xuat();
};

void SinhVien::nhap(){
    cout << "Nhap ho ten sinh vien: ";  fflush(stdin);  gets(hoTen);
    cout << "So bao danh: ";    cin >> soBaoDanh;
}

void SinhVien::xuat(){
    cout << setw(15) << hoTen;
    cout << setw(10) << soBaoDanh;
}

class DiemThi:public SinhVien{
protected:
    float kq1, kq2;
public:
    void nhap();
    void xuat();
};

void DiemThi::nhap(){
    SinhVien::nhap();
    cout << "Nhap ket qua 1: ";     cin >> kq1;
    cout << "Nhap ket qua 2: ";     cin >> kq2;
}

void DiemThi::xuat(){
    SinhVien::xuat();
    cout << setw(5) << kq1;
    cout << setw(5) << kq2;
}

class KetQua:public DiemThi{
public:
    float tinhTong();
};

float KetQua::tinhTong(){
    return DiemThi::kq1 + DiemThi::kq2;
}

void nhap(KetQua *&a, int &n){
    cout << "Nhap so sinh vien: ";  cin >> n;
    a = new KetQua[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
        a[i].nhap();
    }
}

void xuat(KetQua *a, int n){
    for(int i = 0; i < n; i++){
        a[i].xuat();
        cout << setw(10) << a[i].tinhTong() << endl;
    }
}

void title(){
    cout << setw(15) << "hoTen";
    cout << setw(10) << "soBaoDanh";
    cout << setw(5) << "kq1";
    cout << setw(5) << "kq2";
    cout << setw(10) << "tong" << endl;
}

int main()
{
    KetQua *a;
    int n;
    nhap(a,n);
    cout << "======DANH SACH KET QUA THI=====" << endl;
    title();
    xuat(a,n);
    return 0;
}
