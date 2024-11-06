#include <vector>
#include <iostream>
using namespace std;

int main(){
    // make vector
    vector<int> v;
    for(int i = 0; i < 10; i++){
        v.push_back(i);
    }

    cout << "현재의 v= ";
    for(auto& e:v){
        cout << e <<" ";
    }
    cout << endl;
    v.erase(v.begin() + 5);
    cout << "5번 인덱스 제거한 후 v= ";
    for(auto& e:v){
        cout << e <<" ";
    }
    cout << endl;
    return 0;
}