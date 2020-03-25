#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

class person{
protected:
    char hoTen[30];
    char ngaySinh[30];
    char queQuan[30];
};

class kySu: public person{
private:
    char nganh[30];
    int namTN;
public:
    void nhap();
    void xuat();
    friend void displayByMaxYear(kySu *&a, int n);
};

void kySu::nhap(){
    cout << "Nhap ten ky su: "; fflush(stdin);  gets(hoTen);
    cout << "Nhap ngay sinh: "; fflush(stdin);  gets(ngaySinh);
    cout << "Nhap que quan: ";  fflush(stdin);  gets(queQuan);
    cout << "Nhap nganh: ";     fflush(stdin);  gets(nganh);
    cout << "Nhap nam tot nghiep: ";    cin >> namTN;
}

void kySu::xuat(){
    cout << setw(10) << hoTen << setw(15) << ngaySinh << setw(10) << queQuan << setw(8) << nganh << setw(10) << namTN << endl;
}

void title(){
    cout << setw(10) << "hoTen" << setw(15) << "ngaySinh" << setw(10) << "queQuan" << setw(8) << "nganh" << setw(10) << "namTN" << endl;
}

void inputList(kySu *&a, int &n){
    cout << "Nhap so ky su: ";
    cin >> n;
    a = new kySu[n];
    cout << endl << "=====NHAP THONG TIN CAC KY SU=====" << endl;
    for(int i = 0; i < n; i++) {
        cout << "Nhap thong tin ky su thu "<< i + 1 << endl;
        a[i].nhap();
    }
}

void displayList(kySu *&a, int n){
    cout << endl << "=====THONG TIN CAC KY SU=====" << endl;
    title();
    for(int i = 0; i < n; i++) {
        a[i].xuat();
    }
}

void displayByMaxYear(kySu *&a, int n) {
    float mY = a[0].namTN;
    for(int i = 1; i < n; i++) {
        if(a[i].namTN > mY) {
            mY = a[i].namTN;
        }
    }
    cout << endl << "=====THONG TIN CAC KY SU TOT NGHIEP GAN NHAT=====" << endl;
    title();
    for(int i = 0; i < n; i++) {
        if(a[i].namTN == mY) {
            a[i].xuat();
        }
    }
}

int main()
{
    int n;
    kySu *a;
    inputList(a,n);
    displayList(a,n);
    displayByMaxYear(a,n);
    return 0;
}
