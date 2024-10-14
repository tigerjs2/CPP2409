#include <iostream>
#include <string>
using namespace std;

string toLowerStr(string str);
string toUpperStr(string str);
int calcHammingDist(string s1, string s2);

int main(){
    string s1, s2;

    cout << "DNA1:";
    cin >> s1;
    cout << "DNA2:";
    cin >> s2;

    if(s1.length() != s2.length())
        cout << "오류: 길이가 다름" << endl;
    else{
        // 해밍거리 반환
        int count = calcHammingDist(s1, s2);
        cout << "해밍 거리는 " << count << endl;
    }
    return 0;
}
// 파이썬, 자바 등과 달리 string은 클래스지만 자동으로 깊은 복사가 됨
string toLowerStr(string str){
    // 한 문자씩 소문자화
    for(char &c : str){
        c = tolower(c);
    }
    return str;
}

string toUpperStr(string str){
    // 한 문자씩 대문자화
    for(char &c : str){
        c = toupper(c);
    }
    return str;
}

int calcHammingDist(string s1, string s2){
    int count = 0;
    // 두 문자 모두 소문자로 통일 (동일 함수를 쓰기만하면 toUpperStr 사용가능)
    s1 = toLowerStr(s1);
    s2 = toLowerStr(s2);
    for(int i = 0; i < s1.length(); i++){
        if (s1[i] != s2[i]){
            count += 1;
        }
    }
    return count;
}