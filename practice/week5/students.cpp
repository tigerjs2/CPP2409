#include <iostream>
using namespace std;

int main(){
    const int STUDENTS = 5;
    int scores[STUDENTS];
    int sum = 0;
    int i, average;
    // 합계도 한 반복문 내에서 진행해도 동일한 결과
    for(i = 0; i < STUDENTS; i++){
        cout << "학생들의 성적을 입력하시오: ";
        cin >> scores[i];
        sum += scores[i];
    }
    
    average = sum / STUDENTS;
    cout << "성적 평균= " << average << endl;
   
    return 0;
}