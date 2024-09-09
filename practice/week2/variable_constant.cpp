#include <iostream>
#define PI 3.14159265359                    // PI는 기호 상수
using namespace std;

int main() {
    int income = 1000;                      // 1000은 리터럴 상수
    const double TAX_RATE = 0.25;           // TAX_RATE는 상수 변수
    income = income - TAX_RATE * income;

    double x = 100;
    x = x * PI;

    cout << x << endl;
    return 0;
}