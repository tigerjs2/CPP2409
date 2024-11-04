/*
이 코드를 작성할 때마다 시스템 설정을 바꾸기는 번거로워 다음과 같은 환경에서 작성함
해당 소스 코드는 VS Code의 코드 인코딩을 EUC-KR, PC의 시스템 인코딩을 EUC-KR로 통일한 상태로 작성됨
분할 소스 파일도 모두 인코딩 통일
*/
#include <iostream>
#include <string>
#include "user.h"
using namespace std;
const int mapX = 5;
const int mapY = 5;
// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY, User &user);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
void checkState(int map[][mapX], int user_x, int user_y, User &user);
bool CheckUser(User user);
// 메인  함수
int main() {
	User user{}; // 유저 객체 생성
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };
	// 유저의 위치를 저장할 변수
	int user_x = 0; // 가로 번호
	int user_y = 0; // 세로 번호
	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프
		// 사용자의 입력을 저장할 변수
		string user_input = "";
		cout << "현재 HP: " << user.GetHP() << " 명령어를 입력하세요 (상,하,좌,우,지도,종료): ";
		cin >> user_input;
        
		if (user_input == "상") {
			// 위로 한 칸 올라가기
			user_y -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY, user);
			if (inMap == false) {
				user_y += 1;
			}
			else {
				cout << "위로 한 칸 올라갑니다." << endl;
				displayMap(map, user_x, user_y);
			}
		}
		else if (user_input == "하") {
			// TODO: 아래로 한 칸 내려가기
			user_y += 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY, user);
			if (inMap == false) {
				user_y -= 1;
			}
			else {
				cout << "위로 한 칸 내려갑니다." << endl;
				displayMap(map, user_x, user_y);
			}
		}
		else if (user_input == "좌") {
			// TODO: 왼쪽으로 이동하기
			user_x -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY, user);
			if (inMap == false) {
				user_x += 1;
			}
			else {
				cout << "왼쪽으로 이동합니다." << endl;
				displayMap(map, user_x, user_y);
			}
		}
		else if (user_input == "우") {
			// TODO: 오른쪽으로 이동하기
			user_x += 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY, user);
			if (inMap == false) {
				user_x -= 1;
			}
			else {
				cout << "오른쪽으로 이동합니다." << endl;
				displayMap(map, user_x, user_y);
			}
		}
		else if (user_input == "지도") {
			// TODO: 지도 보여주기 함수 호출
			displayMap(map, user_x, user_y);
			cout << "현재 위치는 Y : " << user_y << ", X : " << user_x << " 입니다." << endl;
		}
		else if (user_input == "종료") {
			cout << "종료합니다.";
			break;
		}
		else {
			cout << "잘못된 입력입니다." << endl;
			continue;
		}
		// 이동으로 체력이 고갈됐는지 체크
		if(!(CheckUser(user))){
			break;
		}
		// 맵 상의 요소들과 만났는지 체크 후 상호작용
		checkState(map, user_x, user_y, user);
		// 몬스터 조우로 체력 고갈됐는지 체크
		if(!(CheckUser(user))){
			break;
		}
		// 목적지에 도달했는지 체크
		bool finish = checkGoal(map, user_x, user_y);
		if (finish == true) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}
	}
	return 0;
}
// 지도와 사용자 위치 출력하는 함수
void displayMap(int map[][mapX], int user_x, int user_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				cout << " USER |"; // 양 옆 1칸 공백
			}
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6칸 공백
					break;
				case 1:
					cout << "아이템|";
					break;
				case 2:
					cout << "  적  |"; // 양 옆 2칸 공백
					break;
				case 3:
					cout << " 포션 |"; // 양 옆 1칸 공백
					break;
				case 4:
					cout << "목적지|";
					break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
	}
}
// 체력에 영향을 줄 필요가 있는 함수들은 int &hp를 인자로 가짐
// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY, User &user) {
	bool checkFlag = false; // 이동 가능 시 true
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
	}
	// 경고나 체력 감소를 main에서 각 라인별로 써놓기보다는 공통으로 들어간 함수에 한 번 작성
	// 맵 벗어나는 시도인 경우
	if(checkFlag == false) // 이동 실패
		cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl; 
	// 이동 가능한 경우
	else // 이동 성공
		user.DecreaseHP(1); // 유저 객체 체력 감소
	return checkFlag;
}
// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(int map[][mapX], int user_x, int user_y) {
	// 목적지 도착하면
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}
// 유저가 요소들을 만났을 때 작용 목적지 안내문은 따로 있으니 포함 X
// 체력 증감 객체 동작 사용
void checkState(int map[][mapX], int user_x, int user_y, User &user){
	int encounter = map[user_y][user_x]; // 이동 후 유저 좌표에 원래 있던 요소
	switch(encounter){
		case 1: // 아이템 조우
			cout << "아이템이 있습니다" << endl;
			break;
		case 2: // 적 조우
			cout << "적이 있습니다. HP가 2 줄어듭니다." << endl;
			user.DecreaseHP(2);
			break;
		case 3: // 포션 조우
			cout << "포션이 있습니다. HP가 2 증가합니다." << endl;
			user.IncreaseHP(2);
			break;
	}
}
/*
변경
// 유저 잔여 체력 0이하인지 체크하는 함수
bool checkHP(int hp){
	bool isAlive = true;
	if(hp <= 0){
			cout << "HP가 0 이하가 되었습니다. 실패했습니다." << endl;
			cout << "게임을 종료합니다." << endl;
			isAlive = false;
	}
	return isAlive;
}
*/
// 유저 잔여 체력 0이하인지 체크하는 함수
bool CheckUser(User user){
    int remain = user.GetHP();
    if (remain <= 0){
        cout << "HP가 0 이하가 되었습니다. 실패했습니다." << endl;
		cout << "게임을 종료합니다." << endl;
        return false; // 0 이하
    }
    else
        return true; // 체력 남음
}