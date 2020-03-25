#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string.h>

using namespace std;

class nhanSu;

class date{
private:
    int ngay, thang, nam;
public:
    void nhap();
    void xuat();
    friend class nhanSu;
};

class nhanSu{
private:
    char hoTen[20];
    date ngaySinh;
    int soCMND;
public:
    void nhap();
    void xuat();
    friend void sortByName(nhanSu a[], int n);
};

// Cac phuong thuc cua class date
void date::nhap(){
    cout << "Nhap ngay sinh: ";     cin >> ngay;
    cout << "Nhap thang sinh: ";    cin >> thang;
    cout << "Nhap nam sinh: ";      cin >> nam;
}

void date::xuat(){
    cout << setw(15) << ngay << "/" << thang << "/" << nam;
}

// Cac phuong thuc class nhanSu

void nhanSu::nhap(){
    fflush(stdin);
    cout << "Nhap ho ten: ";    gets(hoTen);
    ngaySinh.nhap();
    cout << "Nhap so CMND: ";   cin >> soCMND;
}

void nhanSu::xuat(){
    cout << setw(10) << hoTen;
    ngaySinh.xuat();
    cout << setw(15) << soCMND << endl;
}

// Ham sap xep theo ten

void sortByName(nhanSu a[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(strcmp(a[i].hoTen, a[j].hoTen) > 0){
                nhanSu temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
int main()
{
    int n;
    cout << "Nhap so nhan su: ";    cin >> n;
    nhanSu a[n];
    for(int i = 0;i < n; i++){
        cout << "Nhap thong tin nhan su thu " << i+1 << endl;
        a[i].nhap();
    }
    sortByName(a,n);
    cout << endl << "==============THONG TIN NHAN SU==============" << endl;
    cout << setw(10) << "hoTen" << setw(20) << "ngaySinh" << setw(15) << "soCMND" << endl;
    for(int i = 0; i < n; i++){
        a[i].xuat();
    }
    return 0;
}
