#include <iostream>
using namespace std;

class Person {
    protected:
        string address;
        string name;  // private에 있으면 자식에서 접근불가
    public:
        
};
class Student : public Person {
    public:
        void SetAddress(string add) {
            address = add;
        }
        string GetAddress() {
            return address;
        }
        void SetName(string name){ this->name = name;} 
        // string Get(){ return name;}  // SetName 작동 Checker 
};
int main() {
    Student obj;
    obj.SetName("미수") ;
    obj.SetAddress("서울시 종로구 1번지");
    cout << obj.GetAddress() << endl;
    // cout << obj.Get();
    return 0;
}
