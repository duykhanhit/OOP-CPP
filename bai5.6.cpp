#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

class SanPham{
protected:
    int maSP;
    char tenSP[30];
    char ngaySX[30];
    float trongLuong;
    char mauSac[10];
public:
    void nhap();
    void xuat();
};

void SanPham::nhap(){
    cout << "Nhap ma SP: ";     cin >> maSP;
    cout << "Nhap ten SP: ";    fflush(stdin);  gets(tenSP);
    cout << "Nhap ngay san xuat: ";     fflush(stdin);  gets(ngaySX);
    cout << "Nhap trong luong: ";   cin >> trongLuong;
    cout << "Nhap mau sac: ";   fflush(stdin);  gets(mauSac);
}

void SanPham::xuat(){
    cout << setw(10) << maSP;
    cout << setw(10) << tenSP;
    cout << setw(15) << trongLuong;
    cout << setw(10) << mauSac;
}

class HangDienTu: public SanPham{
private:
    int congSuat;
    int dongDien;
public:
    void nhap();
    void xuat();
    friend void displayByMinWeight(HangDienTu *a, int n);
};

void HangDienTu::nhap(){
    SanPham::nhap();
    cout << "Nhap cong suat: "; cin >> congSuat;
    cout << "Nhap dong dien(1/2) :";    cin >> dongDien;
}

void HangDienTu::xuat(){
    SanPham::xuat();
    cout << setw(10) << congSuat;
    cout << setw(15) << dongDien << " chieu" << endl;
}

void nhapHangDienTu(HangDienTu *&a, int &n){
    cout << "Nhap so mat hang: "; cin >> n;
    a = new HangDienTu[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin mat hang thu " << i + 1 << endl;
        a[i].nhap();
    }
}
void title(){
    cout << setw(10) << "maSP";
    cout << setw(10) << "tenSP";
    cout << setw(15) << "trongLuong";
    cout << setw(10) << "mauSac";
    cout << setw(10) << "congSuat";
    cout << setw(15) << "dongDien" << endl;
}

void inHangDienTu(HangDienTu *a, int n){
    for(int i = 0; i < n; i++){
        a[i].xuat();
    }
}
void displayByMinWeight(HangDienTu *a, int n){
    float m = a[0].trongLuong;
    for(int i = 1; i < n; i++){
        if(a[i].trongLuong < m){
            m = a[i].trongLuong;
        }
    }
    title();
    for(int i = 0; i < n; i++){
        if(a[i].trongLuong == m){
            a[i].xuat();
        }
    }
}
int main()
{
    HangDienTu *a;
    int n;
    nhapHangDienTu(a,n);
    cout << "=====DANH SACH HANG DIEN TU=====" << endl;
    title();
    inHangDienTu(a,n);
    cout << "=====DANH SACH HANG DIEN TU CO KHOI LUONG THAP NHAT=====" << endl;
    displayByMinWeight(a,n);
    return 0;
}
