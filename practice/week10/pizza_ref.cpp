#include <iostream>
using namespace std;

class Pizza {
    public:
        Pizza(int s) : size(s) { }
        int size; // 단위: 인치
};

void MakeDouble(Pizza& p){
    p.size *= 2;
}
// 아래 경우 원본이 아닌 복사본이 전달됨
Pizza CreatePizza() {
    Pizza p(10);
    return p;
}

int main() {
    Pizza pizza = CreatePizza(); // p와 주소가 다름
    MakeDouble(pizza);
    cout << pizza.size << "인치 피자" << endl;
    return 0;
}