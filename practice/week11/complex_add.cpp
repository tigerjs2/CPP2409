#include <iostream>
using namespace std;
class Complex {
public:
double real, imag;
Complex(double r = 0.0, double i = 0.0) {
real = r;
imag = i;
cout << "생성자 호출";
Print();
}
~Complex() {
cout << "소멸자 호출";
Print();
}
void Print() {
cout << real << "+" << imag << "i" << endl;
}
};

// 매개변수는 참조자
Complex Add(const Complex& c1, const Complex& c2){
    // 복사가 아니기 때문에 함수 호출 시 c1, c2 생성 안함
    Complex tmp{c1.real + c2.real, c1.imag + c2.imag};
    return tmp;
}

/*
// 매개변수는 복사본
Complex Add(Complex c1, Complex c2){
    // c1, c2를 복사하고 함수 종료 시 소멸하는 과정이 추가됨
    Complex tmp{c1.real + c2.real, c1.imag + c2.imag};
    return tmp;
}
*/
/*
// 포인터 매개변수
Complex Add(Complex *c1, Complex *c2){
    Complex tmp{c1->real + c2->real, c1->imag + c2->imag};
    return tmp;
}
*/


int main()
{
Complex c1{ 1,2 }, c2{ 3,4 };
Complex t;
t = Add(c1, c2);
// t = Add(&c1, &c2); // 포인터 매개변수일 때
t.Print();
return 0;
}