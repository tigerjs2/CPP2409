#include "user.h"
/*
for Magician
*/
void Magician::DoAttack() {
    cout << "���� ���" << endl;
}
// �Ű����� ����ŭ ��ü hp ����
void Magician::IncreaseHP(int inc_hp){
    hp += inc_hp;
}
// �Ű����� ����ŭ ��ü hp ����
void Magician::DecreaseHP(int dec_hp){
    hp -= dec_hp;
}
// ��ü�� �ܿ� ü�� ��ȯ
int Magician::GetHP(){
    return hp;
}
// return item count
int Magician::itemCnt(){
    return item;
}
// increase item once
void Magician::increaseItem() { item++; }

// Identify user's job
string Magician::GetJob() { return job; }
// get userName
string Magician::GetName() { return name; }
// get User location
int Magician::GetX() { return x; }
void Magician::SetX(int n) { x = n; }
int Magician::GetY() { return y; }
void Magician::SetY(int n) { y = n; }

/*
for Warrior
*/
void Warrior::DoAttack(){
    cout << "���� ���" << endl;
}
// �Ű����� ����ŭ ��ü hp ����
void Warrior::IncreaseHP(int inc_hp){
    hp += inc_hp;
}
// �Ű����� ����ŭ ��ü hp ����
void Warrior::DecreaseHP(int dec_hp){
    hp -= dec_hp;
}
// ��ü�� �ܿ� ü�� ��ȯ
int Warrior::GetHP(){
    return hp;
}
// return item count
int Warrior::itemCnt(){
    return item;
}
// increase item once
void Warrior::increaseItem() { item++; }

// Identify user's job
string Warrior::GetJob() { return job; }
// get userName
string Warrior::GetName() { return name; }
// get User location
int Warrior::GetX() { return x; }
void Warrior::SetX(int n) { x = n; }
int Warrior::GetY() { return y; }
void Warrior::SetY(int n) { y = n; }