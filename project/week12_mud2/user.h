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
            os << "���� HP�� " << v.GetHP() << "�̰�, ���� �������� �� " << v.itemCnt() << "�� �Դϴ�" << endl;
            return os;
        }
        void DoAttack();
};

class Magician : public User {
     void DoAttack();
};

class Warrior : public User {
        void DoAttack();
};