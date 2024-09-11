#include <iostream>
using namespace std;

int main() {
    int current_m;      // Money you have
    int price;          // Candy's price
    int max;            // Maximum amount of candy
    int exchange;       // Money left

    cout << "현재 가지고있는 돈: ";
    cin >> current_m;
    cout << "캔디의 가격 : ";
    cin >> price;

    max = current_m / price;
    exchange = current_m - (price * max);

    cout << "최대로 살 수 있는 캔디 = " << max << endl;
    cout << "캔디 구입 후 남은 돈 = " << exchange << endl;

    return 0;

}