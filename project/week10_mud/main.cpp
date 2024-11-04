/*
�� �ڵ带 �ۼ��� ������ �ý��� ������ �ٲٱ�� ���ŷο� ������ ���� ȯ�濡�� �ۼ���
�ش� �ҽ� �ڵ�� VS Code�� �ڵ� ���ڵ��� EUC-KR, PC�� �ý��� ���ڵ��� EUC-KR�� ������ ���·� �ۼ���
���� �ҽ� ���ϵ� ��� ���ڵ� ����
*/
#include <iostream>
#include <string>
#include "user.h"
using namespace std;
const int mapX = 5;
const int mapY = 5;
// ����� ���� �Լ�
bool checkXY(int user_x, int mapX, int user_y, int mapY, User &user);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
void checkState(int map[][mapX], int user_x, int user_y, User &user);
bool CheckUser(User user);
// ����  �Լ�
int main() {
	User user{}; // ���� ��ü ����
	// 0�� �� ����, 1�� ������, 2�� ��, 3�� ����, 4�� ������
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };
	// ������ ��ġ�� ������ ����
	int user_x = 0; // ���� ��ȣ
	int user_y = 0; // ���� ��ȣ
	// ���� ���� 
	while (1) { // ����ڿ��� ��� �Է¹ޱ� ���� ���� ����
		// ������� �Է��� ������ ����
		string user_input = "";
		cout << "���� HP: " << user.GetHP() << " ��ɾ �Է��ϼ��� (��,��,��,��,����,����): ";
		cin >> user_input;
        
		if (user_input == "��") {
			// ���� �� ĭ �ö󰡱�
			user_y -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY, user);
			if (inMap == false) {
				user_y += 1;
			}
			else {
				cout << "���� �� ĭ �ö󰩴ϴ�." << endl;
				displayMap(map, user_x, user_y);
			}
		}
		else if (user_input == "��") {
			// TODO: �Ʒ��� �� ĭ ��������
			user_y += 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY, user);
			if (inMap == false) {
				user_y -= 1;
			}
			else {
				cout << "���� �� ĭ �������ϴ�." << endl;
				displayMap(map, user_x, user_y);
			}
		}
		else if (user_input == "��") {
			// TODO: �������� �̵��ϱ�
			user_x -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY, user);
			if (inMap == false) {
				user_x += 1;
			}
			else {
				cout << "�������� �̵��մϴ�." << endl;
				displayMap(map, user_x, user_y);
			}
		}
		else if (user_input == "��") {
			// TODO: ���������� �̵��ϱ�
			user_x += 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY, user);
			if (inMap == false) {
				user_x -= 1;
			}
			else {
				cout << "���������� �̵��մϴ�." << endl;
				displayMap(map, user_x, user_y);
			}
		}
		else if (user_input == "����") {
			// TODO: ���� �����ֱ� �Լ� ȣ��
			displayMap(map, user_x, user_y);
			cout << "���� ��ġ�� Y : " << user_y << ", X : " << user_x << " �Դϴ�." << endl;
		}
		else if (user_input == "����") {
			cout << "�����մϴ�.";
			break;
		}
		else {
			cout << "�߸��� �Է��Դϴ�." << endl;
			continue;
		}
		// �̵����� ü���� ���ƴ��� üũ
		if(!(CheckUser(user))){
			break;
		}
		// �� ���� ��ҵ�� �������� üũ �� ��ȣ�ۿ�
		checkState(map, user_x, user_y, user);
		// ���� ����� ü�� ���ƴ��� üũ
		if(!(CheckUser(user))){
			break;
		}
		// �������� �����ߴ��� üũ
		bool finish = checkGoal(map, user_x, user_y);
		if (finish == true) {
			cout << "�������� �����߽��ϴ�! �����մϴ�!" << endl;
			cout << "������ �����մϴ�." << endl;
			break;
		}
	}
	return 0;
}
// ������ ����� ��ġ ����ϴ� �Լ�
void displayMap(int map[][mapX], int user_x, int user_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				cout << " USER |"; // �� �� 1ĭ ����
			}
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6ĭ ����
					break;
				case 1:
					cout << "������|";
					break;
				case 2:
					cout << "  ��  |"; // �� �� 2ĭ ����
					break;
				case 3:
					cout << " ���� |"; // �� �� 1ĭ ����
					break;
				case 4:
					cout << "������|";
					break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
	}
}
// ü�¿� ������ �� �ʿ䰡 �ִ� �Լ����� int &hp�� ���ڷ� ����
// �̵��Ϸ��� ���� ��ȿ�� ��ǥ���� üũ�ϴ� �Լ�
bool checkXY(int user_x, int mapX, int user_y, int mapY, User &user) {
	bool checkFlag = false; // �̵� ���� �� true
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
	}
	// ��� ü�� ���Ҹ� main���� �� ���κ��� ����⺸�ٴ� �������� �� �Լ��� �� �� �ۼ�
	// �� ����� �õ��� ���
	if(checkFlag == false) // �̵� ����
		cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl; 
	// �̵� ������ ���
	else // �̵� ����
		user.DecreaseHP(1); // ���� ��ü ü�� ����
	return checkFlag;
}
// ������ ��ġ�� ���������� üũ�ϴ� �Լ�
bool checkGoal(int map[][mapX], int user_x, int user_y) {
	// ������ �����ϸ�
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}
// ������ ��ҵ��� ������ �� �ۿ� ������ �ȳ����� ���� ������ ���� X
// ü�� ���� ��ü ���� ���
void checkState(int map[][mapX], int user_x, int user_y, User &user){
	int encounter = map[user_y][user_x]; // �̵� �� ���� ��ǥ�� ���� �ִ� ���
	switch(encounter){
		case 1: // ������ ����
			cout << "�������� �ֽ��ϴ�" << endl;
			break;
		case 2: // �� ����
			cout << "���� �ֽ��ϴ�. HP�� 2 �پ��ϴ�." << endl;
			user.DecreaseHP(2);
			break;
		case 3: // ���� ����
			cout << "������ �ֽ��ϴ�. HP�� 2 �����մϴ�." << endl;
			user.IncreaseHP(2);
			break;
	}
}
/*
����
// ���� �ܿ� ü�� 0�������� üũ�ϴ� �Լ�
bool checkHP(int hp){
	bool isAlive = true;
	if(hp <= 0){
			cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�." << endl;
			cout << "������ �����մϴ�." << endl;
			isAlive = false;
	}
	return isAlive;
}
*/
// ���� �ܿ� ü�� 0�������� üũ�ϴ� �Լ�
bool CheckUser(User user){
    int remain = user.GetHP();
    if (remain <= 0){
        cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�." << endl;
		cout << "������ �����մϴ�." << endl;
        return false; // 0 ����
    }
    else
        return true; // ü�� ����
}