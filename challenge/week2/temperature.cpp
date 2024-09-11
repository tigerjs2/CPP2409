#include <iostream>
using namespace std;

int main() {
    int fahrenheit;         // Fahrenheit degree
    float celsius;            // Celsius degree
    cout << "화씨온도: ";
    cin >> fahrenheit;
    celsius = (5.0 / 9.0) * (fahrenheit -32);
    cout << "섭씨온도 = " << celsius << endl;
    return 0;

}