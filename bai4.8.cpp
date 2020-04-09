#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string.h>
#include <malloc.h>

using namespace std;

class NhanVien;
class Date{
private:
    int day,month,year;
public:
    friend class NhanVien;
};
class PhongBan{
private:
    int maPb;
    char tenPb[50];
    char truongPhong[10];
    int soNv;
public:
    friend class NhanVien;
    friend void ShowTaiChinh(NhanVien *a,int n);
};
class NhanVien{
private:
    int maNv;
    char hoDem[25];
    char ten[10];
    Date ngaySinh;
    PhongBan phong;
public:
    void nhap();
    void xuat();
    friend void ShowTaiChinh(NhanVien *a,int n);
    friend void SortByName(NhanVien *a,int n);
    friend void InsertNewNV(NhanVien *a,int &n,int k,NhanVien x);
    friend void DeleteCode123(NhanVien *a,int &n);
};

void NhanVien::nhap(){
    cout<<"\nNhap ma nv: ";     cin>>maNv;
    cout<<"Nhap ho dem: ";      fflush(stdin);gets(hoDem);
    cout<<"Nhap ten: ";         fflush(stdin);gets(ten);
    cout<<"Nhap ngay sinh: \n";
    cout<<"Nhap ngay: ";        cin>>ngaySinh.day;
    cout<<"Nhap thang: ";       cin>>ngaySinh.month;
    cout<<"Nhap nam: ";         cin>>ngaySinh.year;
    cout<<"Nhap thong tin phong ban: \n";
    cout<<"Nhap ma phong ban: ";cin>>phong.maPb;
    cout<<"Nhap ten pb: ";      fflush(stdin);gets(phong.tenPb);
    cout<<"Nhap ten truong phong: ";fflush(stdin);gets(phong.truongPhong);
    cout<<"Nhap so nhan vien cua phong: "; cin >> phong.soNv;
}
void NhanVien::xuat(){
    cout<<setw(15)<<maNv;
    cout<<setw(15)<<hoDem;
    cout<<setw(15)<<ten;
    cout<<setw(15)<<ngaySinh.day<<"/"<<ngaySinh.month<<"/"<<ngaySinh.year;
    cout<<setw(15)<<phong.maPb;
    cout<<setw(20)<<phong.tenPb;
    cout<<setw(15)<<phong.truongPhong;
    cout<<setw(15)<<phong.soNv << endl;
}
void title(){
    cout<<setw(15)<<"maNv";
    cout<<setw(15)<<"hoDem";
    cout<<setw(15)<<"ten";
    cout<<setw(15)<<"NgaySinh";
    cout<<setw(15)<<"MaPb";
    cout<<setw(20)<<"TenPb";
    cout<<setw(15)<<"TruongPhong";
    cout<<setw(15)<<"SoNv" << endl;
}
void ShowTaiChinh(NhanVien *a,int n){
    int dem=0;
    for(int i=0;i<n;i++){
        if(stricmp(a[i].phong.tenPb,"Tai chinh")==0){
            dem++;
        }
    }
    if(dem!=0){
            title();
    for(int i=0;i<n;i++){
        if(stricmp(a[i].phong.tenPb,"Tai chinh")==0){
            a[i].xuat();
            }
        }
    }
    else{cout<<"Khong co nhan vien nao phong tai chinh !!\n\n";}
}

void SortByName(NhanVien *a, int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i -1; j++)
        {
            if(stricmp(a[j].ten, a[j+1].ten) > 0)
            {
                NhanVien temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void InsertNewNV(NhanVien *a,int &n,int k,NhanVien x){
    cout << "Nhap thong tin nhan vien muon them: " << endl;
    x.nhap();
    cout << "Nhap vi tri muon them: ";  cin >> k;
    n++;
    a = (NhanVien*)realloc(a,n*sizeof(NhanVien));
    for(int i = n - 1; i > k; i--){
        a[i] = a[i-1];
    }
    a[k] = x;
}

void DeleteCode123(NhanVien *a,int &n){
    int i = 0;
    for(int j = 0; j < n; j++){
        if(a[j].maNv == 123){
            for(int k = j; k < n - 1; k++){
                a[k] = a[k+1];
            }
            n--;
            j--;
            a = (NhanVien*)realloc(a,n*sizeof(NhanVien));
        }
    }
}

void nhap(NhanVien *&a, int &n){
    cout << "Nhap so nhan vien: ";
    cin >> n;
    a = new NhanVien[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin nhan vien thu " << i + 1 << endl;
        a[i].nhap();
    }
}

void xuat(NhanVien *&a, int n){
    title();
    for(int i = 0; i < n; i++){
        a[i].xuat();
    }
}


int main()
{
    int n, k;
    NhanVien *a, x;

    nhap(a,n);
    xuat(a,n);
    cout << "===DANH SACH NHAN VIEN PHONG TAI CHINH===" << endl;
    ShowTaiChinh(a,n);
    cout << "===DANH SACH SAP XEP THEO TEN===" << endl;
    SortByName(a,n);
    xuat(a,n);
    InsertNewNV(a,n,k,x);
    cout << "===DANH SACH SAU KHI THEM===" << endl;
    xuat(a,n);
    cout << "===DANH SACH SAU KHI XOA===" << endl;
    DeleteCode123(a,n);
    xuat(a,n);

    return 0;
}
