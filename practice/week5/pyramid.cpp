#include <iostream>
using namespace std;

int main(){
    int floor;
    cout << "몇 층을 쌓겠습니까? (5~100):";
    cin >> floor;
    // 조건 변형 k를 감소시킴
    for (int i = 0; i < floor; i++){
        
        for(int j = 0; j < floor - i - 1; j++)
            cout << "S";
        for(int k = i * 2 + 1; k > 0; k--)
            cout << "*";
        cout << endl;
    }
    /*
    for (int i = 0; i < floor; i++){
        for(int j = 0; j < floor - i - 1; j++)
            cout << "S";
        for(int k = 0; k < i*2+1; k++)
            cout << "*";
        cout << endl;
    }
    */
    return 0;
}