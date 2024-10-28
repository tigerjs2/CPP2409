/*

함수화 이전 코드들은 모두 지우지 않고 주석처리했습니다.

*/

#include <iostream>
#include <string>
using namespace std;

bool checkNumber(int first, int second, int third);

int main() {
	int randomNum; // 맞춰야 하는 3자리수의 숫자 저장 변수
	int firstNum; // 정답의 첫번째 자리수
	int secondNum; // 정답의 두번째 자리수
	int thirdNum; // 정답의 세번째 자리수

	while (1) {		
		randomNum = rand() % 900 + 100; // 랜덤한 3자리수 생성

		bool same = false; // 모든 수가 다를 경우 true를 갖는 변수

		// TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성
        thirdNum = randomNum % 10; // 10으로 나눈 나머지는 1의 자리만 남음
        secondNum = (randomNum % 100) / 10; // % 100으로 백의 자리 제거 10으로 나눈 몫으로 10의 자리 구함
        firstNum = randomNum / 100; // 100으로 나눈 몫은 100의 자리만 남음
        
        // 세 수가 모두 다르면 same은 true, 모두 만족해야하니 AND 연산
        /*
        함수화 전
        if (thirdNum != secondNum && thirdNum != firstNum && firstNum != secondNum)
            same = true;
        */
        same = checkNumber(firstNum, secondNum, thirdNum);
		if (same == true) {
			break;
		}
	}

	int turn = 0;
	while (1) {
		cout << turn + 1 << "번째 시도입니다. " << endl;

		int userNumber; // 사용자가 입력한 세자리수 저장 변수
		int guessFirst; // 추측한 숫자의 첫번째 자리수
		int guessSecond; // 추측한 숫자의 두번째 자리수
		int guessThird; // 추측한 숫자의 세번째 자리수


		// 사용자에게 세자리 수를 입력받는 코드 블록
		while (1) {
			cout << "세자리 수를 입력해주세요: ";
			cin >> userNumber;

			bool same = false; // 모든 수가 다를 경우 true를 갖는 변수
			// TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성

            guessThird = userNumber % 10; // 10으로 나눈 나머지는 1의 자리만 남음
            guessSecond = (userNumber % 100) / 10; // % 100으로 백의 자리 제거 10으로 나눈 나머지로 10의 자리 구함
            guessFirst = userNumber / 100; // 100으로 나눈 몫은 100의 자리만 남음

            // 세 수가 모두 다르면 same은 true, 모두 만족해야하니 AND 연산
            /*
            함수화 전
            if (guessThird != guessSecond && guessThird != guessFirst && guessFirst != guessSecond)
                same = true;
            */
            same = checkNumber(guessFirst, guessSecond, guessThird); // 1자릿수 이하는 여기서 걸러짐
			if (to_string(userNumber).length() > 3 || (to_string(userNumber).length() == 2 && guessFirst != 0)) { // 조건 수정 012 등 0으로 시작하는 경우도 회피
				cout << "입력된 숫자가 3자리 수가 아닙니다. 다시 입력하세요." << endl;
				continue;
			}

			if (same == true) {
				break;
			}
            else{
                cout << "입력한 숫자에 중복된 숫자가 있습니다. 다시 입력하세요" << endl;
            }

		}


		int strike = 0; // 스트라이크 갯수를 저장하는 변수
		int ball = 0; // 볼 갯수를 저장하는 변수

		// TODO 2: 정답과 추측한 숫자의 자릿수와 숫자를 비교하며 힌트를 주기 위한 코드블록 작성
        // 한 조건문에 모든 자릿수 비교하면 증가가 한번만 진행됨 따라서 if else문 세 개 생성
        // 추측이 완전 같으면 strike 다른 위치에 있으면 ball
        if(firstNum == guessFirst)
            strike++;
        else if(firstNum == guessSecond || firstNum == guessThird)
            ball++;
		if(secondNum == guessSecond)
            strike++;
        else if(secondNum == guessFirst || secondNum == guessThird)
            ball++;
        if(thirdNum == guessThird)
            strike++;
        else if(thirdNum == guessSecond || thirdNum == guessFirst)
            ball++;
        
		cout << userNumber << "의 결과 : " << strike << " 스트라이크, " << ball << "볼 입니다." << endl;
		
		if (strike == 3) {
			cout << "정답을 맞췄습니다. 축하합니다.";
			break;
		}

		turn += 1;
	}

	return 0;
}

// checkNumber 함수화, 자릿수 분리 결과는 이 함수 밖에서도 써야하니 함수 밖에서 처리해 매개변수로 활용
bool checkNumber(int first, int second, int third){  
    // 세 수가 모두 다르면 true 반환, 모두 만족해야하니 AND 연산
    if (third != second && third != first && first != second)
        return true;
    else 
        return false;
}