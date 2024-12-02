#include "user.h"
/*
for Magician
*/
void Magician::DoAttack() {
    cout << "마법 사용" << endl;
}
// 매개변수 값만큼 객체 hp 증가
void Magician::IncreaseHP(int inc_hp){
    hp += inc_hp;
}
// 매개변수 값만큼 객체 hp 감소
void Magician::DecreaseHP(int dec_hp){
    hp -= dec_hp;
}
// 객체의 잔여 체력 반환
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
    cout << "베기 사용" << endl;
}
// 매개변수 값만큼 객체 hp 증가
void Warrior::IncreaseHP(int inc_hp){
    hp += inc_hp;
}
// 매개변수 값만큼 객체 hp 감소
void Warrior::DecreaseHP(int dec_hp){
    hp -= dec_hp;
}
// 객체의 잔여 체력 반환
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