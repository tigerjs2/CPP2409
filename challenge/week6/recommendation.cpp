#include <iostream>
using namespace std;
/* set values into global values to use in functions */ 
const int NUM_USERS = 3;
const int NUM_ITEMS =3;
int userPreferences[NUM_USERS][NUM_ITEMS];

/* 함수 원형 선언 */
void initializePreferences(int preferences[NUM_USERS][NUM_ITEMS]);
void findRecommendedItems(const int preferences[NUM_USERS][NUM_ITEMS]);

/* main logic */
int main(){
    initializePreferences(userPreferences);
    findRecommendedItems(userPreferences);
    return 0;
}

/* initialize individual user's preferences */
void initializePreferences(int preferences[NUM_USERS][NUM_ITEMS]){
    for(int i = 0; i < NUM_USERS; ++i){
        cout << "사용자 " << (i + 1) << "의 선호도를 입력하세요 (";
        cout << NUM_ITEMS << "개의 항목에 대해): ";
        for(int j = 0; j < NUM_ITEMS; ++j){
            cin >> userPreferences[i][j];
        }
    }
}

/* find and print each user's preference */ 
void findRecommendedItems(const int preferences[NUM_USERS][NUM_ITEMS]){
    // if preferences score is same recommend faster index
    for(int i = 0; i < NUM_USERS; ++i){
        int maxPreferenceIndex = 0;
        for(int j = 0; j < NUM_ITEMS; ++j){
            if(userPreferences[i][j] > userPreferences[i][maxPreferenceIndex]){
                maxPreferenceIndex = j;
            }
        }
        // print recommended content
        cout << "사용자 " << (i + 1) << "에게 추천하는 항목: ";
        cout << (maxPreferenceIndex + 1) << endl;
    }
}