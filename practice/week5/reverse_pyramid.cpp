#include <iostream>
using namespace std;

int main(){
    int floor;
    cout << "몇 층을 쌓겠습니까? (5~100):";
    cin >> floor;
    // 조건 변형 j, k를 감소하며 반복
    for (int i = floor; i > 0; i--){
        
        for(int j = floor - i; j > 0; j--)
            cout << "S";
        for(int k = i * 2 - 1; k > 0; k--)
            cout << "*";
        cout << endl;
    }
   
    return 0;
}