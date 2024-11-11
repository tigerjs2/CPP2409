#include <iostream>
using namespace std;

class Dog{
    private:
        int *pWeight;
        int *pAge;
    public:
        Dog(){
            // 필드 동적 할당
            pAge = new int(1);
            pWeight = new int(10);
        }
        ~Dog(){
            // 필드 소멸
            delete pAge;
            delete pWeight;
        }
        int GetAge() {return *pAge;}
        void setAge(int age) {*pAge = age;}
        int GetWeight() {return *pWeight;}
        void SetWeight(int weight) {*pWeight = weight;}
};

int main(){
    Dog * pDog = new Dog;
    cout << "강아지의 나이: " << pDog->GetAge() << endl;
    pDog->setAge(5);
    cout << "강아지의 나이: " << pDog->GetAge() << endl;
    delete pDog;
    return 0;
}