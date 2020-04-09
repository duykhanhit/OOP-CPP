#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

class CanBo{
protected:
    int maCB;
    int maDV;
    int namSinh;
    long luongCB;
    float heSoLuong;
    int phuCapAnca;
    int baoHiem;
public:
    void nhap();
    void xuat();
    long tinhLuong();
};

void CanBo::nhap(){
    cout << "Nhap ma: "; cin >> maCB;
    cout << "Nhap ma don vi: "; cin >> maDV;
    cout << "Nhap nam sinh: ";  cin >> namSinh;
    cout << "Nhap luong co ban: ";  cin >> luongCB;
    cout << "Nhap he so luong: ";   cin >> heSoLuong;
    cout << "Nhap phu cap an ca: "; cin >> phuCapAnca;
    cout << "Nhap bao hiem: ";      cin >> baoHiem;
}

void CanBo::xuat(){
    cout << setw(10) << maCB;
    cout << setw(10) << maDV;
    cout << setw(10) << namSinh;
    cout << setw(10) << luongCB;
    cout << setw(10) << heSoLuong;
    cout << setw(15) << phuCapAnca;
    cout << setw(10) << baoHiem;
    cout << setw(10) << tinhLuong() << endl;
}

long CanBo::tinhLuong(){
    return heSoLuong*luongCB + phuCapAnca - baoHiem;
}

class GiangVien: public CanBo{
private:
    int phuCapDungLop;
    int phuCapDocHai;
    int docHai;
public:
    void nhap();
    long tinhLuong();
    friend void displayBySalary(GiangVien *x, CanBo *y, int n, int m);
};

void GiangVien::nhap(){
    CanBo::nhap();
    cout << "Co doc hai hay khong (1.Co/2.Ko): "; cin >> docHai;
}

long GiangVien::tinhLuong(){
    if(docHai == 2){
        phuCapDungLop *= 0.25*luongCB;
        return heSoLuong*luongCB + phuCapAnca + phuCapDungLop - baoHiem;
    }
    if(docHai == 1){
        phuCapDocHai = 0.1*luongCB;
        phuCapDungLop = 0.25*luongCB;
        return heSoLuong*luongCB + phuCapAnca + phuCapDungLop + phuCapDocHai - baoHiem;
    }
}

void nhapCB(CanBo *&x, int &n){
    cout << "======NHAP THONG TIN CAN BO=======" << endl;
    cout << "Nhap so can bo: "; cin >> n;
    x = new CanBo[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin can bo thu " << i+1 << endl;
        x[i].nhap();
    }
}

void nhapGV(GiangVien *&x, int &n){
    cout << "======NHAP THONG TIN GIANG VIEN=======" << endl;
    cout << "Nhap so giang vien: "; cin >> n;
    x = new GiangVien[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin giang vien thu " << i+1 << endl;
        x[i].nhap();
    }
}

void xuatCB(CanBo *x, int n){
    for(int i = 0; i < n; i++){
        x[i].xuat();
    }
}

void xuatGV(GiangVien *x, int n){
    for(int i = 0; i < n; i++){
        x[i].xuat();
    }
}

void title(){
    cout << setw(10) << "maCB";
    cout << setw(10) << "maDV";
    cout << setw(10) << "namSinh";
    cout << setw(10) << "luongCB";
    cout << setw(10) << "heSoLuong";
    cout << setw(15) << "phuCapAnca";
    cout << setw(10) << "baoHiem";
    cout << setw(10) << "tongLuong" << endl;
}

void displayBySalary(GiangVien *x, CanBo *y, int n, int m){
    cout << "===DANH SACH CAN BO PHAI DONG THUE===" << endl;
    title();
    for(int i = 0; i < m; i++){
        if(y[i].tinhLuong() > 5000000){
            y[i].xuat();
        }
    }

    cout << "===DANH SACH GIANG VIEN PHAI DONG THUE===" << endl;
    title();
    for(int i = 0; i < n; i++){
        if(x[i].tinhLuong() > 5000000){
            x[i].xuat();
        }
    }
}


int main()
{
    int n, m;
    CanBo *y;
    GiangVien *x;
    nhapCB(y,m);
    nhapGV(x,n);
    displayBySalary(x,y,n,m);
    return 0;
}
