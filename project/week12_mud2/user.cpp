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
void User::increaseItem(){item++;}

void User::DoAttack(){
    cout << "�����մϴ�" << endl;
}

void Magician::DoAttack(){
    cout << "���� ���" << endl;
}