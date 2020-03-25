#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

class sanPham{
protected:
    int maSP;
    char tenSP[30];
    char ngaySX[15];
    float trongLuong;
    char mauSac[10];
public:
    void nhap();
    void xuat();
    float getTrongLuong(){
        return trongLuong;
    }
};

class hangDienTu: public sanPham{
private:
    int congSuat;
    char dongDien[10];
public:
    void nhap();
    void xuat();
};

void sanPham::nhap(){
    cout << "Nhap ma san pham: ";                   cin >> maSP;
    cout << "Nhap ten san pham: ";  fflush(stdin);  gets(tenSP);
    cout << "Nhap ngay san xuat: "; fflush(stdin);  gets(ngaySX);
    cout << "Nhap trong luong: ";                   cin >> trongLuong;
    cout << "Nhap mau sac: ";       fflush(stdin);  gets(mauSac);
}

void sanPham::xuat(){
    cout << setw(5) << maSP << setw(10) << tenSP << setw(10) << ngaySX << setw(15) << trongLuong << setw(10) << mauSac;
}

void hangDienTu::nhap(){
    sanPham::nhap();
    cout << "Nhap cong suat: ";     cin >> congSuat;
    cout << "Nhap dong dien: ";     fflush(stdin);  gets(dongDien);
}

void hangDienTu::xuat(){
    sanPham::xuat();
    cout << setw(10) << congSuat << setw(10) << dongDien << endl;
}

void title(){
    cout << setw(5) << "maSP" << setw(10) << "tenSP" << setw(10) << "ngaySX" << setw(15) << "trongLuong" << setw(10) << "mauSac";
    cout << setw(10) << "congSuat" << setw(10) << "dongDien" << endl;
}

void inputListItem(hangDienTu *&a, int &n){
    cout << "Nhap so mat hang: ";
    cin >> n;
    a = new hangDienTu[n];
    cout << endl << "=====NHAP THONG TIN CAC MAT HANG=====" << endl;
    for(int i = 0; i < n; i++) {
        cout << "Nhap thong tin mat hang thu "<< i + 1 << endl;
        a[i].nhap();
    }
}

void displayListItem(hangDienTu *&a, int n){
    cout << endl << "=====THONG TIN CAC MAT HANG=====" << endl;
    title();
    for(int i = 0; i < n; i++) {
        a[i].xuat();
    }
}

float minWeight(hangDienTu *&a,int n){
    float mW = a[0].getTrongLuong();
    for(int i = 1; i < n; i++){
        if(a[i].getTrongLuong() < mW){
            mW = a[i].getTrongLuong();
        }
    }
    return mW;
}

void displayByMinWeight(hangDienTu *&a, int n){
    cout << endl << "=====THONG TIN CAC MAT HANG NHE NHAT=====" << endl;
    title();
    for(int i = 0; i < n; i++){
        if(a[i].getTrongLuong() == minWeight(a,n)){
            a[i].xuat();
        }
    }
}
int main() {
    int n;
    hangDienTu *a;
    inputListItem(a,n);
    displayListItem(a,n);
    displayByMinWeight(a,n);
    return 0;
}
