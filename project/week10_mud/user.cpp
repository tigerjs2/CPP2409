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