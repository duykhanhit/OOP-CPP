#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string.h>

using namespace std;

class XeHoi{
private:
    char nhanHieu[30];
    char hangSanXuat[30];
    char kieuDang[30];
    char mauSon[30];
    int namSX;
    char xuatXu[30];
    long giaBan;
public:
    void nhap();
    void xuat();
    friend void displayByBrand(XeHoi *car, int n);
    friend void sortByPrice(XeHoi *car, int n);
};

void XeHoi::nhap(){
    cout << "Nhap nhan hieu: "; fflush(stdin);    gets(nhanHieu);
    cout << "Nhap hang san xuat: "; fflush(stdin);  gets(hangSanXuat);
    cout << "Nhap kieu dang: "; fflush(stdin);  gets(kieuDang);
    cout << "Nhap mau son: ";   fflush(stdin);  gets(mauSon);
    cout << "Nhap nam san xuat: "; cin >> namSX;
    cout << "Nhap xuat xu: ";    fflush(stdin);  gets(xuatXu);
    cout << "Nhap gia ban: ";   cin >> giaBan;
}

void XeHoi::xuat(){
    cout << setw(10) << nhanHieu << setw(15) << hangSanXuat << setw(10) << kieuDang << setw(10) << mauSon << setw(10) << namSX << setw(10) << xuatXu << setw(10) << giaBan << endl;
}

void displayByBrand(XeHoi *car, int n){
    for(int i = 0; i < n; i++){
        if(stricmp(car[i].nhanHieu,"toyota") == 0){
            car[i].xuat();
        }
    }
}

void sortByPrice(XeHoi *car, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i -1; j++){
            if(car[j].giaBan > car[j+1].giaBan){
                XeHoi temp = car[j];
                car[j] = car[j+1];
                car[j+1] = temp;
            }
        }
    }
}

void nhap(XeHoi *&car, int &n){
    cout << "Nhap so luong xe hoi: ";   cin >> n;
    car = new XeHoi[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin xe thu " << i + 1 << endl;
        car[i].nhap();
    }
}

void xuat(XeHoi *car, int n){
    for(int i = 0; i < n; i++){
        car[i].xuat();
    }
}

void title(){
    cout << setw(10) << "nhanHieu" << setw(15) << "hangSanXuat" << setw(10) << "kieuDang" << setw(10) << "mauSon" << setw(10) << "namSX" << setw(10) << "xuatXu" << setw(10) << "giaBan" << endl;
}

int main()
{
    int n;
    XeHoi *car;
    nhap(car,n);
    cout << "===DANH SACH SAU KHI NHAP===" << endl;
    title();
    xuat(car,n);
    cout << "===DANH SACH XE TOYOTA===" << endl;
    title();
    displayByBrand(car,n);
    sortByPrice(car,n);
    cout << "===DANH SACH SAU KHI SAP XEP===" << endl;
    title();
    xuat(car,n);

    return 0;
}
