#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

class nhanSu;

class date{
private:
    int D, M, Y;
public:
    void nhap();
    void xuat();
    friend class nhanSu;
};

class nhanSu{
private:
    int maNhanSu;
    char hoTen[20];
    date ns;
public:
    void nhap();
    void xuat();
};

// Cac phuong thuc class date
void date::nhap(){
    cout << "Nhap ngay sinh: ";     cin >> D;
    cout << "Nhap thang sinh: ";    cin >> M;
    cout << "Nhap nam sinh: ";      cin >> Y;
}
void date::xuat(){
    cout << setw(10) << D << "/" << M <<  "/" << Y;
}

// Cac phuong thuc class nhanSu

void nhanSu::nhap(){
    cout << "Nhap ma nhan su: ";    cin >> maNhanSu;
    fflush(stdin);
    cout << "Nhap ho ten: ";        gets(hoTen);
    ns.nhap();
}
void nhanSu::xuat(){
    cout << setw(5) << maNhanSu << setw(10) << hoTen;
    ns.xuat();
}
int main()
{
    nhanSu n;
    cout << "===Nhap thong tin nhan su===" << endl;
    n.nhap();
    cout << "===Thong tin nhan su vua nhap===" << endl;
    cout << setw(5) << "maNhanSu" << setw(10) << "hoTen" << setw(10) << "ngaySinh" << endl;
    n.xuat();
    return 0;
}
