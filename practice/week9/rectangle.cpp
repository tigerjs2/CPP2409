#include <iostream>
using namespace std;

class Rectangle{
    public:
        int width, height;
        int CalcArea(){
            return width * height;
        }
};

int main(){
    Rectangle obj;
    obj.width = 3;
    obj.height = 4;
    int area = obj.CalcArea();

    Rectangle obj2;
    obj2.width = 10;
    obj2.height = 10;
    int area2 = obj2.CalcArea();

    cout << "사각형의 넓이1: " << area << endl;
    cout << "사각형의 넓이2: " << area2 << endl;
    return 0;
}