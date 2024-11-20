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
    cout << "공격합니다" << endl;
}


/*
for Magician
*/
void Magician::DoAttack(){
    cout << "마법 사용" << endl;
}

/*
for Warrior
*/
void Warrior::DoAttack(){
    cout << "베기 사용" << endl;
}