#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

class vehicle{
protected:
    char nhanHieu[30];
    int namSX;
    char hang[30];
public:
    void nhap();
    void xuat();
};

class oTo: public vehicle{
private:
    int soChoNgoi;
    int dungTich;
public:
    void nhap();
    void xuat();
};

class moTo: public vehicle{
private:
    int phanKhoi;
public:
    void nhap();
    void xuat();
};

void vehicle::nhap(){
    cout << "Nhap nhan hieu: "; fflush(stdin);  gets(nhanHieu);
    cout << "Nhap nam san xuat: ";              cin >> namSX;
    cout << "Nhap hang xe: ";   fflush(stdin);  gets(hang);
}

void vehicle::xuat(){
    cout << setw(10) << nhanHieu << setw(10) << namSX << setw(10) << hang;
}

void oTo::nhap(){
    vehicle::nhap();
    cout << "Nhap so cho ngoi: ";   cin >> soChoNgoi;
    cout << "Nhap dung tich: ";     cin >> dungTich;
}

void oTo::xuat(){
    vehicle::xuat();
    cout << setw(10) << soChoNgoi << setw(10) << dungTich << endl;
}

void moTo::nhap(){
    vehicle::nhap();
    cout << "Nhap phan khoi: "; cin >> phanKhoi;
}

void moTo::xuat(){
    vehicle::xuat();
    cout << setw(10) << phanKhoi << endl;
}

int main()
{
    oTo a;
    moTo b;
    cout << endl << "====NHAP THONG TIN O TO====" << endl;
    a.nhap();
    cout << endl << "====NHAP THONG TIN MO TO====" << endl;
    b.nhap();
    cout << endl << "====THONG TIN O TO====" << endl;
    cout << setw(10) << "nhanHieu" << setw(10) << "namSX" << setw(10) << "hang";
    cout << setw(10) << "soChoNgoi" << setw(10) << "dungTich" << endl;
    a.xuat();
    cout << endl << "====THONG TIN MO TO====" << endl;
    cout << setw(10) << "nhanHieu" << setw(10) << "namSX" << setw(10) << "hang";
    cout << setw(10) << "phanKhoi" << endl;
    b.xuat();

    return 0;
}
