#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>

using namespace std;

class ptBac2{
private:
    float a, b, c;
public:
    void nhap();
    void xuat();
    void giai();
    ptBac2();
    ptBac2(float a, float b, float c);
};

ptBac2::ptBac2(){
    a = b = c = 0;
}

ptBac2::ptBac2(float a, float b, float c){
    this -> a = a;
    this -> b = b;
    this -> c = c;
}

void ptBac2::nhap(){
    cout << "a = ";     cin >> a;
    cout << "b = ";     cin >> b;
    cout << "c = ";     cin >> c;
}

void ptBac2::xuat(){
    cout << "Phuong trinh cua ban la: " << a << "x^2";
    if(b >= 0){
        cout << "+" << b << "x";
    }else{
        cout << b << "x";
    }
    if(c >= 0){
        cout << "+" << c << " = 0" << endl;
    }else{
        cout << c << " = 0" << endl;
    }
}

void ptBac2::giai(){
    if(a == 0){
        if(b == 0){
            if(c == 0){
                cout << "Phuong trinh co vo so nghiem." << endl;
            }else{
                cout << "Khong phai phuong trinh bac 2. (PT vo nghiem)" << endl;
            }
        }else{
            cout << "Phuong trinh bac nhat co nghiem la :\n\tx = " << -c/b << endl;
        }
    }else{
        float delta = b*b - 4*a*c;
        if(delta < 0){
            cout << "Phuong trinh vo nghiem." << endl;
        }else if(delta == 0){
            cout << "Phuong trinh co nghiem kep:\n\t x1 = x2 = " << -b/(2*a) << endl;
        }else{
            cout << "Phuong trinh co 2 nghiem phan biet: " << endl;
            cout << "\tx1 = " << (-b+sqrt(delta))/(2*a) << endl << "\tx2 = " << (-b-sqrt(delta))/(2*a) << endl;
        }
    }
}

int main()
{
    ptBac2 p = ptBac2(4,9,1);
    p.xuat();
    p.giai();
    ptBac2 q;
    cout << "===Nhap thong tin phuong trinh===" << endl;
    q.nhap();
    q.xuat();
    q.giai();
    return 0;
}
