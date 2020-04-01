#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

class BENHNHAN{
protected:
    char hoTen[30];
    char queQuan[30];
    int namSinh;
public:
    void nhap();
    void xuat();
};

void BENHNHAN::nhap(){
    cout << "Nhap ten benh nhan: ";  fflush(stdin);     gets(hoTen);
    cout << "Nhap que quan: ";  fflush(stdin);          gets(queQuan);
    cout << "Nhap nam sinh: ";  cin >> namSinh;
}

void BENHNHAN::xuat(){
    cout << setw(10) << hoTen << setw(10) << queQuan << setw(5) << namSinh;
}

class BENHAN: public BENHNHAN {
private:
    char tenBenhAn[30];
    int vienPhi;
public:
    void nhap();
    void xuat();
    int tinhTuoi();
    friend void displayByMoney(BENHAN *listBenhAn, int n);
};

void BENHAN::nhap(){
    BENHNHAN::nhap();
    cout << "Nhap vien phi: ";  cin >> vienPhi;
}

void BENHAN::xuat(){
    BENHNHAN::xuat();
    cout << setw(5) << vienPhi << endl;
}

int BENHAN::tinhTuoi(){
    return 2020 - BENHNHAN::namSinh;
}

void tieuDe(){
    cout << setw(10) << "hoTen" << setw(10) << "queQuan" << setw(5) << "namSinh" << setw(5) << "vienPhi" << endl;
}

void nhapBenhAn(BENHAN *&listBenhAn, int &n){
    cout << "Nhap so benh an: ";    cin >> n;
    listBenhAn = new BENHAN[n];
    cout << "===NHAP THONG TIN BENH AN===" << endl;
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin ben an thu " << i + 1 << endl;
        listBenhAn[i].nhap();
    }
}

void xuatBenhAn(BENHAN *&listBenhAn, int n){
    tieuDe();
    for(int i = 0; i < n; i++){
        listBenhAn[i].xuat();
    }
}

void sortByAge(BENHAN *listBenhAn, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(listBenhAn[j].tinhTuoi() < listBenhAn[j+1].tinhTuoi()){
                BENHAN temp = listBenhAn[j];
                listBenhAn[j] = listBenhAn[j+1];
                listBenhAn[j+1] = temp;
            }
        }
    }
}

void displayByAge(BENHAN *listBenhAn, int n){
    for(int i = 0; i < n; i++){
        if(listBenhAn[i].tinhTuoi() <= 10){
            listBenhAn[i].xuat();
        }
    }
}

void displayByMoney(BENHAN *listBenhAn, int n){
    BENHAN m = listBenhAn[0];
    for(int i = 0; i < n; i++){
        if(listBenhAn[i].vienPhi > m.vienPhi){
            m = listBenhAn[i];
        }
    }
    cout << "===DANH SACH BENH NHAN CO VIEN PHI CAO NHAT===" << endl;
    tieuDe();
    for(int i = 0; i < n; i++){
        if(listBenhAn[i].vienPhi == m.vienPhi){
            listBenhAn[i].xuat();
        }
    }
}

int main()
{
    int n;
    BENHAN *listBenhAn;
    nhapBenhAn(listBenhAn,n);
    cout << "===DANH SACH BENH AN===" << endl;
    xuatBenhAn(listBenhAn,n);

    sortByAge(listBenhAn,n);
    cout << "===DANH SACH SAP XEP THEO TUOI GIAM DAN===" << endl;
    xuatBenhAn(listBenhAn,n);

    cout << "===DANH SACH BENH NHAN NHO HON 10 TUOI===" << endl;
    tieuDe();
    displayByAge(listBenhAn,n);

    displayByMoney(listBenhAn,n);

    return 0;
}
