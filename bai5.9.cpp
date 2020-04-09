#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>

using namespace std;
class SanPham{
	protected:
		char tenSanPham[15];
		int namSanXuat;
		long giaThanh;
	public:
		void nhap();
		void xuat();
};
class HoaDon:public SanPham{
	private:
		int soLuongBan;
		long giaBan;
	public:
		void nhap();
		void xuat();
		long long tinhThanhTien();
		long thue();
		long lai();
};
void title(){
	cout<<setw(3)<<"STT"	;
	cout<<setw(15)<<"TenSP";
	cout<<setw(10)<<"GiaThanh";
	cout<<setw(7)<<"SoLuongBan";
	cout<<setw(10)<<"GiaBan";
	cout<<setw(12)<<"ThanhTien";
	cout<<setw(10)<<"Thue";
	cout<<setw(10)<<"Lai"<<endl;
}
void SanPham::nhap(){
	cout<<"\n Nhap ten san pham: ";fflush(stdin);gets(tenSanPham);
	cout<<"\n Nhap nam san xuat: ";cin>>namSanXuat;
	cout<<"\n Nhap gia thanh: ";cin>>giaThanh;
}
void SanPham::xuat(){
	cout<<setw(15)<<tenSanPham;
	cout<<setw(10)<<giaThanh;
}
void HoaDon::nhap(){
	SanPham::nhap();
	cout<<"\n Nhap so luong ban: ";cin>>soLuongBan;
	cout<<"\n Nhap gia ban: ";cin>>giaBan;
}
long long HoaDon::tinhThanhTien(){
	return soLuongBan*giaBan;
}
long HoaDon::thue(){
	return tinhThanhTien()*0.1;
}
long HoaDon::lai(){
	return (giaBan - giaThanh)*soLuongBan;
}
void HoaDon::xuat(){
	SanPham::xuat();
	cout<<setw(7)<<soLuongBan;
	cout<<setw(10)<<giaBan;
	cout<<setw(12)<<tinhThanhTien();
	cout<<setw(10)<<tinhThanhTien()*0.1;
	cout<<setw(10)<<(giaBan - giaThanh)*soLuongBan<<endl;
}
void nhapDanhSach(HoaDon *&list, int n){
	list = new HoaDon[n];
	cout<<"\n \tNhap danh sach gom "<<n<<" hoa don\n";
	for(int i=0;i<n;i++){
		cout<<"nhap thong tin hoa don thu "<<i+1<<": \n";
		list[i].nhap();
	}
}
void hienThiDanhSach(HoaDon *list, int n){
	title();
	for(int i=0;i<n;i++){
		cout<<setw(3)<<i+1<<".";
		list[i].xuat();
	}
}
void sapXep(HoaDon *list, int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if (list[i].lai()<list[j].lai()){
				HoaDon temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}
	}
}
long long tongTien(HoaDon *list, int n){
	long long sum = 0;
	for(int i=0;i<n;i++){
		sum +=list[i].tinhThanhTien();
	}
	return sum;
}
void thueMax(HoaDon *list, int n){
	title();
	long max = list[0].thue();
	for(int i=1;i<n;i++){
		if (list[i].thue()>max){
			max = list[i].thue();
		}
	}
	int count = 0;
	for(int i=0;i<n;i++){
		if (list[i].thue() == max){
			count++;
			cout<<setw(3)<<count<<".";
			list[i].xuat();
		}
	}
}
int main(){
	int n;
	HoaDon *list;
	cout<<"\n Nhap so luong Hoa Don: ";
	cin>>n;
	nhapDanhSach(list,n);
	system("cls");
	sapXep(list,n);
	cout<<"====================DANH SACH HOA DON-=======================\n";
	hienThiDanhSach(list,n);
	cout<<"\n\tTong tien cua cac hoa don: "<<setprecision(10)<<fixed<<tongTien(list,n);
	cout<<"===============DANH SACH HOA DON CO THUE CAO NHAT===============\n";
	thueMax(list,n);
	return 0;
}
