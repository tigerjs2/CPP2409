#include <iostream>
using namespace std;

int main(){
    const int maxPeople = 5;
    string names[maxPeople];
    int ages[maxPeople];

    cout << maxPeople << "명의 회원 정보를 입력해주세요." << endl;

    for(int i = 0; i < maxPeople; i++){
        cout << "사람 " << i + 1 << "의 이름: ";
        cin >> names[i];
        cout << "사람 " << i + 1 << "의 나이: ";
        cin >> ages[i];
    }
    int selection;
    while(1){
        cout << "메뉴 선택(1. 최연장자, 2. 최연소자, 3. 종료, 4. 전원출력): ";
        cin >> selection;
        if(selection == 1){
            int maxAgeIndex = 0;
            int max = ages[0];
            for(int i = maxPeople - 1; i > 0; i--){
                if(max < ages[i]){
                    max = ages[i];
                    maxAgeIndex = i;
                }
            }
            // 동점자출력
            for(int i = 0; i < maxPeople; i++){
                if(ages[i] == ages[maxAgeIndex])
                    cout << "최연장자는 " << names[i] << "(" << ages[i] << "세)\n";
            }
            
        }
       
        else if(selection == 2){
            int minAgeIndex = 0;
            int min = ages[0];
            for(int i = maxPeople - 1; i > 0; i--){
                if(min > ages[i]){
                    min = ages[i];
                    minAgeIndex = i;
                }
            }
            // 동점자 출력
            for(int i = 0; i < maxPeople; i++){
                if(ages[i] == ages[minAgeIndex])
                    cout << "최연소자는 " << names[i] << "(" << ages[i] << "세)\n";
            }
        }
        else if(selection == 3){
            cout << "프로그램을 정상 종료합니다\n";
            break;
        }
        //추가
        else if(selection == 4){
            cout << "전 인원의 정보를 출력합니다.\n";
            for(int i = 0; i < maxPeople; i++){
                cout << names[i] << " (" << ages[i] << "세)\n";
            }
        }
        else{
            cout << "잘못된 접근으로 프로그램이 종료됩니다.\n";
            break;
        }


    }

    return 0;
}