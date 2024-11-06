#include <vector>
#include <iostream>
using namespace std;

int main(){
    // make vector
    vector<int> student_vector;
    while(1){ // Infinite Loop
        int score;
        cout << "성적을 입력하시오(종료는 -1) : ";
        cin >> score;
        if (score == -1) break; // Escape Loop when get Terminal Flag
        student_vector.push_back(score); // append score in vector
    }
    float ave = 0;
    for(int score:student_vector){ // score sum
        ave += score;
    }
    
    ave /= student_vector.size(); // average
    cout << "성적 평균=" << ave << endl; // print result
    return 0;
}