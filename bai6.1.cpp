#include <iostream>

using namespace std;

class vecto{
private:
    float x, y;
public:
    void nhap();
    void xuat();
    friend void tong(vecto a, vecto b);
    friend void hieu(vecto a, vecto b);
};

void vecto::nhap(){
    cout << "Nhap toa do x: ";  cin >> x;
    cout << "Nhap toa do y: ";  cin >> y;
}

void vecto::xuat(){
    cout << "(" << x << "," << y << ")";
}

void tong(vecto a, vecto b){
    vecto t;
    t.x = a.x + b.x;
    t.y = a.y + b.y;
    a.xuat();
    cout << " + ";
    b.xuat();
    cout << " = ";
    t.xuat();
}

void hieu(vecto a, vecto b){
    vecto t;
    t.x = a.x - b.x;
    t.y = a.y - b.y;
    a.xuat();
    cout << " - ";
    b.xuat();
    cout << " = ";
    t.xuat();
}

int main()
{
    vecto a, b;
    cout << "Nhap toa do vector 1:" << endl;
    a.nhap();
    cout << "Nhap toa do vector 2:" << endl;
    b.nhap();
    tong(a,b);
    cout << endl;
    hieu(a,b);
    return 0;
}
