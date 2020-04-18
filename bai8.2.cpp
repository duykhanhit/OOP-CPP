#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

class MonHoc{
private:
    char tenMon[30];
    int soTrinh;
    float diem;
public:
    void nhap();
    void xuat();
    friend class Phieu;
};

class SinhVien{
private:
    char maSV[10];
    char tenSV[30];
    char lop[10];
    char khoa[5];
public:
    void nhap();
    void xuat();
};

class Phieu{
private:
    SinhVien x;
    MonHoc *dsMonHoc;
    int n;
public:
    void nhap();
    void xuat();
    float TBC();
};

void MonHoc::nhap(){
    cout << "Nhap ten mon hoc: ";   fflush(stdin); gets(tenMon);
    cout << "Nhap so trinh: ";  cin >> soTrinh;
    cout << "Nhap diem: ";  cin >> diem;
}
void MonHoc::xuat(){
    cout << setw(10) << tenMon;
    cout << setw(10) << soTrinh;
    cout << setw(10) << diem << endl;
}
void SinhVien::nhap(){
    cout << "Nhap ma sinh vien: ";  fflush(stdin);  gets(maSV);
    cout << "Nhap ten sinh vien: "; fflush(stdin);  gets(tenSV);
    cout << "Nhap lop: ";   fflush(stdin);  gets(lop);
    cout << "Nhap khoa: ";  fflush(stdin);  gets(khoa);
}
void SinhVien::xuat(){
    cout << "Ma sinh vien: " << maSV << "\tTen sinh vien: " << tenSV << endl;
    cout << "Lop: " << lop << "\t\tKhoa: " << khoa << endl;
}
void Phieu::nhap(){
    x.nhap();
    cout << "Nhap so mon hoc: ";   cin >> n;
    dsMonHoc = new MonHoc[n];
    for(int i = 0; i < n; i++){
        cout << "\tNhap thong tin mon hoc thu " << i + 1 << endl;
        dsMonHoc[i].nhap();
    }
}
float Phieu::TBC(){
    float t = 0;
    int s = 0;
    for(int i = 0; i < n; i++){
        t += dsMonHoc[i].diem * dsMonHoc[i].soTrinh;
        s += dsMonHoc[i].soTrinh;
    }
    return t/s;
}
void Phieu::xuat(){
    cout << "=======================================\n";
    cout << "                PHIEU BAO DIEM" << endl;
    x.xuat();
    cout << "Bang diem: " << endl;
    cout << setw(10) << "TenMon" << setw(10) << "SoTrinh" << setw(10) << "Diem" << endl;
    for(int i = 0; i < n; i++){
        dsMonHoc[i].xuat();
    }
    cout << "\t\tDiem trung binh: " << TBC();
}
int main()
{
    Phieu x;
    cout << "Nhap thong tin phieu: " << endl;
    x.nhap();
    x.xuat();
    return 0;
}
