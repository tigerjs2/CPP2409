#include <iostream>
#include <string>
using namespace std;
class Date {
        int year, month, day;
    public:
        Date(){} // Person 멤버 선언에서 한 번 실행되야하기 때문에 선언
        Date(int y, int m, int d) { year = y; month=m; day=d; }
        void Print() {
            cout << year << "." << month << "." << day <<endl;
        }
};
class Person {
        string name;
        Date birth; // 객체 생성시 Date() 호출됨
    public:
        // d는 복사생성자 호출해 매개변수에 복사됨
        Person(string n, Date d) { name = n; birth = d; }
        void Print() {
            cout << name << ":";
            birth.Print();
            cout << endl;
        }
};

int main(){
    Date d{ 1998, 3, 1 };
    Person p{ "김철수", d };
    p.Print();
    return 0;
}