#include <iostream>
using namespace std;

int main(){
    int number = 10;
    int *p = &number; // number의 주소값이 p의 값
    cout << *p << endl; // 역참조
    return 0;
}