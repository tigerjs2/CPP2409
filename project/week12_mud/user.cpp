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

ostream& operator<<(ostream& os, User &v){
    os << "현재 HP는 " << v.GetHP() << "이고, 먹은 아이템은 총 " << v.itemCnt() << "개 입니다" << endl;
    return os;
}