#include <iostream>
using namespace std;

int main(){
    int a, b, c, largest;
    cout << "3개의 정수를 입력하시오: ";
    cin >> a >> b >> c;
    // 원래 코드는 a == b인데 c < a이면 c가 largest가 됨.
    // 첫 조건에서 처리 시 동일 예외 상황을 처리하면 중복처리 따라서 변경x
    if(a >= b && a > c)  // a와 b가 같으면 어느 쪽이 largest여도 상관없음
        largest = a;
    else if(b > a && b > c)
        largest = b;
    else
        largest = c;
    
    cout << "가장 큰 정수는" << largest << endl;
    return 0;
}