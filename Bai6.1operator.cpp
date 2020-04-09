#include <iostream>

using namespace std;

class vecto{
private:
    float x, y;
public:
    void nhap();
    void xuat();
    vecto operator+(vecto a);
//    vecto operator-(vecto a);
};

void vecto::nhap(){
    cout << "Nhap toa do x: ";  cin >> x;
    cout << "Nhap toa do y: ";  cin >> y;
}

void vecto::xuat(){
    cout << "(" << x << "," << y << ")";
}

vecto vecto::operator+(vecto a){
    vecto t;
    t.x = x + a.x;
    t.y = y + a.y;
    return t;
}

//vecto operator-(vecto a, vecto b){
//    vecto h;
//    h.x = a.x - b.x;
//    h.y = a.y - b.y;
//    return h;
//}

int main()
{
    vecto a, b;
    cout << "Nhap toa do vector 1:" << endl;
    a.nhap();
    cout << "Nhap toa do vector 2:" << endl;
    b.nhap();
    cout << "Tong = ";
    (a+b).xuat();
    cout << endl << "Hieu = ";
//    (a-b).xuat();
    return 0;
}
