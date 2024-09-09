#include <iostream>
#include <string>
using namespace std;

int main() {
    // char ch = "1";     타입 에러
    // char ch = '1';     정상 코드

    string s1 = "Good";
    string s2 = "Morning";
    string s3 = s1 + " " + s2 + "!";
    // string s3 = s1 + 10 + s2 + "!";      타입 에러
    cout << s3 << endl;
    return 0;

}