#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdio.h>

using namespace std;

class TAISAN{
private:
    char tenTS[30];
    int soLuong;
    char tinhTrang[30];
public:
    void nhap();
    void xuat();
    friend class PHIEU;
};

class PHONG{
private:
    char tenPhong[30];
    char maPhong[10];
    char truongPhong[30];
public:
    void nhap();
    void xuat();
};

class KIEMKE{
private:
    char ngayKiemKe[15];
    char nvKiemKe[30];
    char chucVu[30];
public:
    void nhap();
    void xuat();
};

class PHIEU{
private:
    char maPhieu[10];
    KIEMKE k;
    PHONG p;
    TAISAN *dsTS;
    int n;
public:
    void nhap();
    void xuat();
    int tongSL();
};


void TAISAN::nhap(){
    cout << "Nhap ten tai san: ";   fflush(stdin);  gets(tenTS);
    cout << "Nhap so luong: ";  cin >> soLuong;
    cout << "Nhap tinh trang: ";    fflush(stdin);  gets(tinhTrang);
}
void TAISAN::xuat(){
    cout << setw(10) << tenTS;
    cout << setw(10) << soLuong;
    cout << setw(15) << tinhTrang << endl;
}

void PHONG::nhap(){
    cout << "Nhap ten phong: "; fflush(stdin);  gets(tenPhong);
    cout << "Nhap ma phong: ";  fflush(stdin);  gets(maPhong);
    cout << "Nhap truong phong: ";  fflush(stdin);  gets(truongPhong);
}
void PHONG::xuat(){
    cout << "Kiem ke tai phong: " << tenPhong << "\tMa phong: " << maPhong << endl;
    cout << "Truong phong: " << truongPhong << endl;
}

void KIEMKE::nhap(){
    cout << "Nhap ngay kiem ke: ";  fflush(stdin);  gets(ngayKiemKe);
    cout << "Nhap ten nhan vien kiem ke: "; fflush(stdin);  gets(nvKiemKe);
    cout << "Nhap chuc vu: ";   fflush(stdin);  gets(chucVu);
}
void KIEMKE::xuat(){
    cout << "\t\tNgay kiem ke: " << ngayKiemKe << endl;
    cout << "Nhan vien kiem ke: " << nvKiemKe << "\tChuc vu: " << chucVu << endl;
}

void PHIEU::nhap(){
    cout << "Nhap ma phieu: ";  fflush(stdin);  gets(maPhieu);
    k.nhap();
    p.nhap();
    cout << "Nhap so tai san: ";    cin >> n;
    dsTS = new TAISAN[n];
    for(int i = 0; i < n; i++){
        cout << "\tNhap thong tin tai san thu " << i+1 << endl;
        dsTS[i].nhap();
    }
}
int PHIEU::tongSL(){
	int t = 0;
	for(int i = 0; i < n; i++){
		t += dsTS[i].soLuong;
	}
	return t;
}
void PHIEU::xuat(){
    cout << "Ma phieu: " << maPhieu << "\t";
    k.xuat();
    p.xuat();
    cout << setw(10) << "TenTS" << setw(10) << "SoLuong" << setw(15) << "TinhTrang" << endl;
    for(int i = 0; i < n; i++){
        dsTS[i].xuat();
    }
    cout << "So tai san da kiem ke: " << n << "\tTong so luong: " << tongSL();
}

int main()
{
    PHIEU a;
    cout << "=======NHAP THONG TIN PHIEU=======\n";
    a.nhap();
    cout << "=======THONG TIN PHIEU========" << endl;
    a.xuat();
    return 0;
}
