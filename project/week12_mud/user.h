#include <iostream>
using namespace std;
class User{
    private:
        int hp;
        int item; // the number of item user have
    public:
        User(){hp = 20; item=0;}
        void IncreaseHP(int inc_hp);
        void DecreaseHP(int dec_hp);
        int GetHP();
        int itemCnt();
        void increaseItem();
        friend ostream& operator<<(ostream& os, User &v){
            os << "현재 HP는 " << v.GetHP() << "이고, 먹은 아이템은 총 " << v.itemCnt() << "개 입니다" << endl;
            return os;
        }
};