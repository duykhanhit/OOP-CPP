#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string.h>

using namespace std;

class doanhNghiep;

class date{
private:
    int day, month, year;
public:
    void nhap();
    void xuat();
    friend class doanhNghiep;
    friend void sumByYear(doanhNghiep a[], int n);
    friend void editInfor(doanhNghiep a[], int n);
};

class diaChi{
private:
    char dienThoai[12];
    char phuong[30];
    char quan[30];
    char thanhPho[30];
public:
    friend class doanhNghiep;
    friend void displayByCity(doanhNghiep a[], int n);
};

class doanhNghiep{
private:
    int maDN;
    char tenDN[60];
    date ngayTL;
    diaChi dc;
    char giamDoc[30];
    long doanhThu;
public:
    void nhap();
    void xuat();
    friend void displayByCity(doanhNghiep a[], int n);
    friend void sumByYear(doanhNghiep a[], int n);
    friend void editInfor(doanhNghiep a[], int n);
};

// Cac phuong thuc class date
void date::nhap(){
    cout << "Nhap ngay: ";  cin >> day;
    cout << "Nhap thang: "; cin >> month;
    cout << "Nhap nam: ";   cin >> year;
}

void date::xuat(){
    cout << setw(5) << day << "/" << month << "/" << year;
}

// Cac phuong thuc class doanhNghiep

void doanhNghiep::nhap(){
    cout << "Nhap ma doanh nghiep: ";   cin >> maDN;
    cout << "Nhap ten doan nghiep: ";   fflush(stdin);  gets(tenDN);
    cout << "===NHAP THONG TIN NGAY THANH LAP===" << endl;
    ngayTL.nhap();
    cout << "===NHAP THONG TIN DIA CHI===" << endl;
    cout << "Nhap so dien thoai: "; cin >> dc.dienThoai;
    cout << "Nhap ten phuong: ";    fflush(stdin);  gets(dc.phuong);
    cout << "Nhap ten quan: ";      fflush(stdin);  gets(dc.quan);
    cout << "Nhap ten thanh pho: "; fflush(stdin);  gets(dc.thanhPho);
    cout << "Nhap ten giam doc: ";  fflush(stdin);  gets(giamDoc);
    cout << "Nhap doanh thu: ";     cin >> doanhThu;
}

void doanhNghiep::xuat(){
    cout << setw(5) << maDN << setw(10) << tenDN;
    ngayTL.xuat();
    cout << setw(10) << dc.dienThoai << setw(10) << dc.phuong << setw(10) << dc.quan << setw(10) << dc.thanhPho;
    cout << setw(10) << giamDoc << setw(10) << doanhThu <<endl;
}

void displayByCity(doanhNghiep a[], int n) {
    int dem = 0;
    for(int i = 0; i < n; i++) {
        if(strcmp(a[i].dc.thanhPho,"Ha Noi") == 0) {
            dem++;
        }
    }
    if(dem == 0)
        cout << endl << "Khong co doanh nghiep nao o Ha Noi !!!" << endl;
    else {
        cout << endl << "====THONG TIN DOANH NGHIEP O HA NOI====" << endl;
        cout << setw(5) << "maDN" << setw(10) << "tenDN" << setw(10) << "ngayTL" << setw(15) << "dienThoai" << setw(10) << "phuong" << setw(10) << "quan" << setw(10) << "thanhPho";
        cout << setw(10) << "giamDoc" << setw(10) << "doanhThu" <<endl;
        for(int i = 0; i < n; i++) {
            if(strcmp(a[i].dc.thanhPho,"Ha Noi") == 0) {
                a[i].xuat();
                dem++;
            }
        }
    }
}

void sumByYear(doanhNghiep a[], int n){
    long sumDT = 0;
    for(int i = 0; i < n; i++){
        if(a[i].ngayTL.year == 2015)
            sumDT += a[i].doanhThu;
    }
    cout << endl << "Tong doanh thu nhung doanh nghiep TL 2015 la: " << sumDT << endl;
}

void editInfor(doanhNghiep a[], int n){
    int code, dem = 0;
    cout << endl << "Nhap ma doanh nghiep can sua: ";   cin >> code;
    for(int i = 0; i < n; i++){
        if(a[i].maDN == code){
            cout << "===BAN DANG SUA THONG TIN DOANH NGHIEP===" << endl;
            cout << setw(5) << "maDN" << setw(10) << "tenDN" << setw(10) << "ngayTL" << setw(15) << "dienThoai" << setw(10) << "phuong" << setw(10) << "quan" << setw(10) << "thanhPho";
            cout << setw(10) << "giamDoc" << setw(10) << "doanhThu" <<endl;
            a[i].xuat();
            cout << endl << "===NHAP THONG TIN MOI===" << endl;
            a[i].nhap();
            cout << "====THONG TIN CAC DOANH NGHIEP SAU KHI SUA====" << endl;
            cout << setw(5) << "maDN" << setw(10) << "tenDN" << setw(10) << "ngayTL" << setw(15) << "dienThoai" << setw(10) << "phuong" << setw(10) << "quan" << setw(10) << "thanhPho";
            cout << setw(10) << "giamDoc" << setw(10) << "doanhThu" <<endl;
            for(int j = 0; j < n; j++){
                a[j].xuat();
            }
            dem++;
            break;
        }
    }
    if(dem == 0){
        cout << endl << "KHONG TON TAI DOANH NGHIEP CO MA VUA NHAP !!!" << endl;
    }
}

int main()
{
    int n;
    cout << "Nhap so luong doanh nghiep: "; cin >> n;
    doanhNghiep a[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin doanh nghiep thu " << i + 1 << endl;
        a[i].nhap();
    }
    cout << "====THONG TIN CAC DOANH NGHIEP====" << endl;
    cout << setw(5) << "maDN" << setw(10) << "tenDN" << setw(10) << "ngayTL" << setw(15) << "dienThoai" << setw(10) << "phuong" << setw(10) << "quan" << setw(10) << "thanhPho";
    cout << setw(10) << "giamDoc" << setw(10) << "doanhThu" <<endl;
    for(int i = 0; i < n; i++){
        a[i].xuat();
    }
    displayByCity(a,n);
    sumByYear(a,n);
    editInfor(a,n);
    return 0;
}
