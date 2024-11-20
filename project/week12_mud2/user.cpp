#include "user.h"
// 매개변수 값만큼 객체 hp 증가
void User::IncreaseHP(int inc_hp){
    hp += inc_hp;
}
// 매개변수 값만큼 객체 hp 감소
void User::DecreaseHP(int dec_hp){
    hp -= dec_hp;
}
// 객체의 잔여 체력 반환
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
    cout << "공격합니다" << endl;
}

void Magician::DoAttack(){
    cout << "마법 사용" << endl;
}