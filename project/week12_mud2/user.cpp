#include "user.h"
// �Ű����� ����ŭ ��ü hp ����
void User::IncreaseHP(int inc_hp){
    hp += inc_hp;
}
// �Ű����� ����ŭ ��ü hp ����
void User::DecreaseHP(int dec_hp){
    hp -= dec_hp;
}
// ��ü�� �ܿ� ü�� ��ȯ
int User::GetHP(){
    return hp;
}
// return item count
int User::itemCnt(){
    return item;
}
// increase item once
void User::increaseItem() { item++; }

// Identify user's job
string User::GetJob() { return job; }
// get userName
string User::GetName() { return name; }
// get User location
int User::GetX() { return x; }
void User::SetX(int n) { x = n; }
int User::GetY() { return y; }
void User::SetY(int n) { y = n; }
// Check if another user is on same location
bool User::CheckOther(User& u) { return this->x == u.x && this->y == u.y; }

void User::DoAttack(){
    cout << "�����մϴ�" << endl;
}


/*
for Magician
*/
void Magician::DoAttack(){
    cout << "���� ���" << endl;
}

/*
for Warrior
*/
void Warrior::DoAttack(){
    cout << "���� ���" << endl;
}