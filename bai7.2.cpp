#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string.h>

using namespace std;

class Person{
protected:
    char name[30];
    char birth[10];
    char address[30];
public:
    void input();
    void output();
    Person(){
        strcpy(name,"Khanh");
        strcpy(birth,"22/06");
        strcpy(address,"Hai Phong");
    };
};

class School{
private:
    char name[30];
    char date[30];
    friend class Faculty;
    friend class Student;
};

class Faculty{
private:
    char name[30];
    char date[10];
    School x;
public:
    void input();
    void output();
    friend class Student;
};

class Student:public Person{
private:
    Faculty y;
    char Class[10];
    float score;
public:
    void input();
    void output();
    Student():Person(){
        strcpy(y.name,"Cam Ngoan");
        strcpy(y.date,"01/01");
        strcpy(y.x.name,"HaUI");
        strcpy(y.x.date,"01/01");
        strcpy(Class,"CNTT3");
        score = 10;
    };
};

void Person::input(){
    cout << "Nhap ten: ";   fflush(stdin);  gets(name);
    cout << "Nhap sinh nhat: "; fflush(stdin);  gets(birth);
    cout << "Nhap dia chi: ";   fflush(stdin);  gets(address);
}
void Person::output(){
    cout << setw(15) << name;
    cout << setw(10) << birth;
    cout << setw(15) << address;
}

void Faculty::input(){
    cout << "Nhap ten giang vien: ";    fflush(stdin);  gets(name);
    cout << "Nhap ngay: ";  fflush(stdin);  gets(date);
    cout << "Nhap ten truong: ";    fflush(stdin);  gets(x.name);
    cout << "Nhap ngay thanh lap: ";  fflush(stdin);  gets(x.date);
}
void Faculty::output(){
    cout << setw(15) << name;
    cout << setw(12) << date;
    cout << setw(15) << x.name;
    cout << setw(12) << x.date;
}

void Student::input(){
    Person::input();
    y.input();
    cout << "Nhap lop: ";   fflush(stdin);  gets(Class);
    cout << "Nhap diem: ";  cin >> score;
}
void Student::output(){
    Person::output();
    y.output();
    cout << setw(10) << Class;
    cout << setw(10) << score << endl;
}

void title(){
    cout << setw(15) << "nameStd";
    cout << setw(10) << "birthStd";
    cout << setw(15) << "address";
    cout << setw(15) << "nameFacul";
    cout << setw(12) << "dateFacul";
    cout << setw(15) << "nameSchool";
    cout << setw(12) << "dateSchool";
    cout << setw(10) << "Class";
    cout << setw(10) << "score" << endl;
}

int main()
{
    Student x;
    x.input();
    title();
    x.output();
    return 0;
}

