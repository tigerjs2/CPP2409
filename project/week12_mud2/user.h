#include <iostream>
using namespace std;
class User{
    protected:
        string job;  // user's job, later this will be used for child identifier
        int x, y;  // user location
        string name;  // user's name
    private:
        int hp;
        int item; // the number of item user have
    public:
        User(){hp = 20; item=0; job = "None"; }
        User(string n, int x, int y): name{n}, x{x}, y{y} {hp = 20; item=0;}
        void IncreaseHP(int inc_hp);
        void DecreaseHP(int dec_hp);
        int GetHP();
        int itemCnt();
        void increaseItem();
        string GetJob();
        friend ostream& operator<<(ostream& os, User &v){
            os << "현재 HP는 " << v.GetHP() << "이고, 먹은 아이템은 총 " << v.itemCnt() << "개 입니다" << endl;
            return os;
        }
        void DoAttack();
        string GetName();
        int GetX();
        void SetX(int n);
        int GetY();
        void SetY(int n);
        bool CheckOther(User& u);
};

class Magician : public User {
    public:
        Magician() { job = "Magician"; }
        Magician(string n, int x, int y): User(n, x, y) { job = "Magician"; }
        void DoAttack();
};

class Warrior : public User {
    public:
        Warrior() { job = "Warrior"; }
        Warrior(string n, int x, int y): User(n, x, y) { job = "Warrior"; }
        void DoAttack();
};