/*
�� �ڵ带 �ۼ��� ������ �ý��� ������ �ٲٱ�� ���ŷο� ������ ���� ȯ�濡�� �ۼ���
�ش� �ҽ� �ڵ�� VS Code�� �ڵ� ���ڵ��� EUC-KR, PC�� �ý��� ���ڵ��� EUC-KR�� ������ ���·� �ۼ���
���� �ҽ� ���ϵ� ��� ���ڵ� ����
*/
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include "user.h"
using namespace std;
using std::cout;

const int mapX = 5;
const int mapY = 5;
// ����� ���� �Լ�
bool checkXY(int user_x, int mapX, int user_y, int mapY, User &user);
void displayMap(vector<vector<int>> map, User *user);
bool checkGoal(vector<vector<int>> map, int user_x, int user_y);
void checkState(vector<vector<int>> map, int user_x, int user_y, User &user);
bool CheckUser(User *user);
void OpenMap(string name, vector<vector<int>> &map);
// ����  �Լ�
int main() {
	// 0�� �� ����, 1�� ������, 2�� ��, 3�� ����, 4�� ������
	vector<vector<int>> map;
    OpenMap("map1.txt", map);
	User *user;  // ���� ���� ������
	while(1){ // ���� ����
		cout << "������ �����ϼ��� ( Magician | Warrior ): ";
		string job;
		cin >> job;
		if (job == "Magician"){
			user = new Magician("USER", 0, 0);
			break;
		}
		else if (job == "Warrior"){
			user = new Warrior("USER", 0, 0);
			break;
		}
		else
			cout << "�ٽ� �Է��Ͻʽÿ�." << endl;
	}
	// ���� ���� 
	while (1) { // ����ڿ��� ��� �Է¹ޱ� ���� ���� ����
        // �ε����� ����� ���� �ǵ��� �߻����� �ʵ��� ó�������� vector�� �ε����� ������ �� ������ ����� ���� �߻��� �� �ִ�.
        // �� ���� �ӿ��� ���ͷ� �����ϴ� ������ ���� �ִ�. ���� �ش� loop�� ���� ��ü�� try-catch ó���ϰڴ�.
        try{
		    string user_input = "";  // ������� �Է��� ������ ����
		    cout << user->GetName() << "(" << user->GetJob() << ") �� ���� HP: " << user->GetHP() << " ��ɾ �Է��ϼ��� (��,��,��,��,����,����,����): ";
		    cin >> user_input;
		    if (user_input == "��") {
			    // ���� �� ĭ �ö󰡱�
			    user->SetY(user->GetY() - 1);
			    bool inMap = checkXY(user->GetX(), mapX, user->GetY(), mapY, *user);
			    if (inMap == false) {
				    user->SetY(user->GetY() + 1);
		    	}
			    else {
				    cout << "���� �� ĭ �ö󰩴ϴ�." << endl;
				    displayMap(map, user);
	    		}
		    }
		    else if (user_input == "��") {
			    // TODO: �Ʒ��� �� ĭ ��������
			    user->SetY(user->GetY() + 1);
			    bool inMap = checkXY(user->GetX(), mapX, user->GetY(), mapY, *user);
			        if (inMap == false) {
				        user->SetY(user->GetY() - 1);
		        	}
			        else {
				        cout << "���� �� ĭ �������ϴ�." << endl;
				        displayMap(map, user);
			        }
		    }
		    else if (user_input == "��") {
			    // TODO: �������� �̵��ϱ�
			    user->SetX(user->GetX() - 1);
			    bool inMap = checkXY(user->GetX(), mapX, user->GetY(), mapY, *user);
			    if (inMap == false) {
				    user->SetX(user->GetX() + 1);
			    }
			    else {
				    cout << "�������� �̵��մϴ�." << endl;
				    displayMap(map, user);
		    	}
	    	}
		    else if (user_input == "��") {
			    // TODO: ���������� �̵��ϱ�
			    user->SetX(user->GetX() + 1);
			    bool inMap = checkXY(user->GetX(), mapX, user->GetY(), mapY, *user);
			    if (inMap == false) {
				    user->SetX(user->GetX() - 1);
		    	}
			    else {
				    cout << "���������� �̵��մϴ�." << endl;
				    displayMap(map, user);
		    	}
		    }
		    else if (user_input == "����") {
			    // TODO: ���� �����ֱ� �Լ� ȣ��
			    displayMap(map, user);
			    cout << user->GetName() << "�� ���� ��ġ�� Y : " << user->GetY() << ", X : " << user->GetX() << " �Դϴ�." << endl;
		    }
		    else if (user_input == "����") {
			    cout << user->GetName() << "���� �������ϴ�. �����մϴ�.";
			    break;
	    	}
		    else if(user_input == "����"){
			    cout << *user;
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
		    if(user_input != "����" && user_input != "����") // ���ڸ� ���ۿ��� ���� üũ x
			    checkState(map, user->GetX(), user->GetY(), *user);
    		// ���� ����� ü�� ���ƴ��� üũ
	    	if(!(CheckUser(user))){
		    	break;
		    }
		    // �������� �����ߴ��� üũ
		    bool finish = checkGoal(map, user->GetX(), user->GetY());
		    if (finish == true) {
			    cout << user->GetName() << "���� �������� �����߽��ϴ�! �����մϴ�!" << endl;
			    cout << "������ �����մϴ�." << endl;
			    break;
		    }
        }
        catch(out_of_range e){
            // �̵��ϴٰ� ���� ������ ����� ��Ȳ�� �̹� ������ ó���ߴ� �׷����� �ش� ���ܰ� �߻��ϸ� �ɰ��� ������ �߻��� ���̹Ƿ� ���α׷��� �����Ѵ�.
            cerr << "Exception: " << e.what() << endl;
            exit(1);
        }
	}
	return 0;
}
// ������ ����� ��ġ ����ϴ� �Լ�
void displayMap(vector<vector<int>> map, User *user) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user->GetY() && j == user->GetX()) {
				cout << " " << user->GetName() << " |"; // �� �� 1ĭ ����

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
bool checkGoal(vector<vector<int>> map, int user_x, int user_y) {
	// ������ �����ϸ�
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}
// ������ ��ҵ��� ������ �� �ۿ� ������ �ȳ����� ���� ������ ���� X
// ü�� ���� ��ü ���� ���
void checkState(vector<vector<int>> map, int user_x, int user_y, User &user){
	int encounter = map[user_y][user_x]; // �̵� �� ���� ��ǥ�� ���� �ִ� ���
	switch(encounter){
		case 1: // ������ ����
			cout << "�������� �ֽ��ϴ�" << endl;
			user.increaseItem();
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


// ���� �ܿ� ü�� 0�������� üũ�ϴ� �Լ�
bool CheckUser(User *user){
    int remain = user->GetHP();
    if (remain <= 0){
        cout << user->GetName() << "���� HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�." << endl;
		cout << "������ �����մϴ�." << endl;
        return false; // 0 ����
    }
    else
        return true; // ü�� ����
}

// �־��� �̸��� ���� �ҷ��´�
void OpenMap(string name, vector<vector<int>> &map){
    ifstream is{name};
    if(!is){  // ���ڷ� �־��� ���ϸ��� ������ ������ ����
        cerr << "Error! Fail to Load Map" << endl;
        exit(1);
    }
    int n;
    // ���� �о� ���� ����
    for(int i = 0; i < mapY; i++){
        vector<int> tmp;
        for(int j = 0; j < mapX; j++){
            is >> n;
            tmp.push_back(n);
        }
        map.push_back(tmp);
    }
    is.close();
}