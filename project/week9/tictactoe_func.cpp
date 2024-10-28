/*

함수화 이전 코드들은 모두 지우지 않고 주석처리했습니다.

*/
#include <iostream>
using namespace std;
const int numCell = 3; // 보드판의 가로 세로 길이, 함수의 매개변수 크기에 활용하기 위해 전역변수화

bool isValid(int x, int y, int num, char board[numCell][numCell]);
bool checkWin(char currentUser, int num, char board[numCell][numCell]);

int main() {
	// 게임을 진행하는 데 필요한 변수 선언

	
	int k = 0; // 누구 차례인지 체크하기 위한 변수
	char currentUser = 'X'; // 현재 유저의 돌을 저장하기 위한 변수
	char board[numCell][numCell]{}; // 보드판을 나타내는 2차원 배열
	int x, y = 0; // 사용자에게 xy좌표값을 입력받기 위한 변수

	// 보드판 초기화
	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			board[i][j] = ' ';
		}
	}

	// 게임을 무한 반복
	while (true) {
		// 1. 누구 차례인지 출력
		// TODO 1.1: 3인용 게임으로 변경
        // % 3으로 바꿔 k가 0, 1, 2 갖도록 변경
		switch (k % 3) {
		case 0:
			currentUser = 'X';
			break;
		case 1:			
			currentUser = 'O';
			break;
        case 2:
            currentUser = 'H';
            break;
		}
		cout << k % 3 + 1 << "번 유저("<< currentUser <<")의 차례입니다. -> ";

		// 2. 좌표 입력 받기
		cout << "(x, y) 좌표를 입력하세요: ";
		int x, y;
		cin >> x >> y;

		// 3. 입력받은 좌표의 유효성 체크
		// TODO FUNC 1: isValid 함수 생성 후 호출
		/*
        원본
        if (x >= numCell || y >= numCell) {// 좌표 범위를 벗어날때
			cout << x << "," << y << ": x와 y둘중 하나가 칸을 벗어납니다. " << endl;
			continue;
		}
		if (board[x][y] != ' ') {// 좌표범위의 입력값이 중복될때
			cout << x << "," << y << ": 이미 돌이 차있습니다. " << endl;
			continue;
		}
        */
        if(!isValid(x, y, numCell, board))
            continue;



		// 4. 입력받은 좌표에 현재 유저의 돌 놓기
		board[x][y] = currentUser;

		// 5. 현재 보드 판 출력
		// TODO 1.2: numCell 숫자에 맞춘 보드판 출력
		for (int i = 0; i < numCell; i++) {
            // num cell에 맞춰 보드의 천장부분이 생성되게 하는 반복문, numCell - 1 만큼 ---| 출력 후 최후에 --- 출력
            for (int k = 0; k < numCell - 1; k++){
                cout << "---|";
            }
            cout << "---" << endl;

			for (int j = 0; j < numCell; j++)
			{
				cout << board[i][j];
				if (j == numCell - 1) {
					break;
				}
				cout << "  |";
			}
			cout << endl;
		}
		for (int k = 0; k < numCell - 1; k++){
                cout << "---|";
        }
        cout << "---" << endl;



		bool isWin = false; // 승리 여부
		// TODO FUNC2: 6.1부터 6.2까지 checkWin 함수 생성 후 호출
		// 6.1. 가로/세로 돌 체크하기
		/*
        함수화 이전
        for (int i = 0; i < numCell; i++) {
			if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser) {
				cout << "가로에 모두 돌이 놓였습니다!!";
				isWin = true;
				break;
			}
			if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser) {
				cout << "세로에 모두 돌이 놓였습니다!!";
				isWin = true;
				break;
			}
		}
        */
		// 6.2. 대각선을 체크하기
		// TODO 1.3: numCell에 맞춘 대각선 빙고 체크 코드로 확장
		// HINT: for 문
        /*
        함수화 이전 코드
        // for 문이 끝까지 실행되면 true, currentUser가 아닌 칸이 있으면 isWin은 false인 채로 반복문 탈출
        // 아래 대각선 체크를 그냥 진행 시 가로 세로 줄에 승자 나와도 false 될 수 있음 따라서 승자 없을 때 실행한다는 조건 추가
        if(isWin == false){
            for(int i = 0; i < numCell; i++){
                if(board[i][i] != currentUser){
                    isWin = false;
                    break;
               }
                isWin = true;
                // 반복문의 마지막 iteration까지와서 여기가 실행되면 isWin은 true
                if(i == numCell - 1)
                cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!" << endl;
            }
        }
        if(isWin == false){
            for(int i = 0; i < numCell; i++){
                if(board[i][numCell - 1 - i] != currentUser){
                    isWin = false;
                    break;
                }
                isWin = true;
            // 반복문의 마지막 iteration까지와서 여기가 실행되면 isWin은 true
            if(i == numCell - 1)
                cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다!" << endl;
        }
        }
        */
        /*
        원본 대각선 체크
		if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser) {
			cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!" << endl;
			isWin = true;			
		}
		if (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser) {
			cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다!" << endl;
			isWin = true;			
		}
        */
        isWin = checkWin(currentUser, numCell, board);
		// 승리자가 결정되었으면 해당 플레이어를 출력하고 게임을 종료한다.
		if (isWin == true) {
			cout << k % 3 + 1<< "번 유저(" << currentUser << ")의 승리입니다!" << endl;
			break;
		}

		// 7. 모든 칸 다 찼는지 체크하기
		int checked = 0;
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') {
					checked++;
				}
			}
		}
		if (checked == 0) {
			cout << "모든 칸이 다 찼습니다.  종료합니다. " << endl;
			break;
		}

		k++;
	}

	return 0;
}

// isValid 함수는 부적절한 위치에 돌 놓기를 시도 시 false 아니면 true 반환
bool isValid(int x, int y, int num, char board[numCell][numCell]){
    if (x >= num || y >= num) {// 좌표 범위를 벗어날때
		cout << x << "," << y << ": x와 y둘중 하나가 칸을 벗어납니다. " << endl;
		return false;
	}
	if (board[x][y] != ' ') {// 좌표범위의 입력값이 중복될때
		cout << x << "," << y << ": 이미 돌이 차있습니다. " << endl;
		return false;
	}
    return true;
}
// 승자 체크기 함수화
bool checkWin(char currentUser, int num, char board[numCell][numCell]){
    bool isWin = false;
    // 6.1. 가로/세로 돌 체크하기
	for (int i = 0; i < num; i++) {
		if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser) {
			cout << "가로에 모두 돌이 놓였습니다!!";
			isWin = true;
			break;
		}
		if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser) {
			cout << "세로에 모두 돌이 놓였습니다!!";
			isWin = true;
			break;
		}
	}
    if(isWin) return isWin; // 아래로 넘어가면 승자 나와도 false될 수 있음
    // 대각선
    for(int i = 0; i < numCell; i++){
        if(board[i][i] != currentUser){
            isWin = false;
            break;
        }
        isWin = true;
        // 반복문의 마지막 iteration까지와서 여기가 실행되면 isWin은 true
        if(i == numCell - 1)
            cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!" << endl;
    }
	if(isWin) return isWin; // 아래로 넘어가면 승자 나와도 false될 수 있음
    for(int i = 0; i < numCell; i++){
        if(board[i][numCell - 1 - i] != currentUser){
            isWin = false;
            break;
        }
        isWin = true;
        // 반복문의 마지막 iteration까지와서 여기가 실행되면 isWin은 true
        if(i == numCell - 1)
            cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다!" << endl;
    }
    return isWin;
}