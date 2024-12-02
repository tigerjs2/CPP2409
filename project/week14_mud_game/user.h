#include <iostream>
using namespace std;

class User{
    public:
        virtual void IncreaseHP(int inc_hp) = 0;
        virtual void DecreaseHP(int dec_hp) = 0;
        virtual int GetHP() = 0;
        virtual int itemCnt() = 0;
        virtual void increaseItem() = 0;
        virtual string GetJob() = 0;
        virtual void DoAttack() = 0;
        virtual string GetName() = 0;
        virtual int GetX() = 0;
        virtual void SetX(int n) = 0;
        virtual int GetY() = 0;
        virtual void SetY(int n) = 0;
        friend ostream& operator<<(ostream& os, User &v){
            os << "현재 HP는 " << v.GetHP() << "이고, 먹은 아이템은 총 " << v.itemCnt() << "개 입니다" << endl;
            return os;
        }
};

class Magician : public User {
    protected:
        string job;  // user's job, later this will be used for child identifier
        int x, y;  // user location
        string name;  // user's name
    private:
        int hp;
        int item; // the number of item user have
    public:
        Magician() { hp = 20; item=0; job = "Magician"; }
        Magician(string n, int x, int y) : x(x), y(y),name(n) { hp = 20; item=0; job = "Magician"; }
        void DoAttack() override;

        void IncreaseHP(int inc_hp);
        void DecreaseHP(int dec_hp);
        int GetHP();
        int itemCnt();
        void increaseItem();
        string GetJob();
        string GetName();
        int GetX();
        void SetX(int n);
        int GetY();
        void SetY(int n);
};

class Warrior : public User {
    protected:
        string job;  // user's job, later this will be used for child identifier
        int x, y;  // user location
        string name;  // user's name
    private:
        int hp;
        int item; // the number of item user have
    public:
        Warrior() { hp = 20; item=0; job = "Warrior"; }
        Warrior(string n, int x, int y) : x(x), y(y),name(n){ hp = 20; item=0; job = "Warrior"; }
        void DoAttack() override;
        
        void IncreaseHP(int inc_hp);
        void DecreaseHP(int dec_hp);
        int GetHP();
        int itemCnt();
        void increaseItem();
        string GetJob();
        string GetName();
        int GetX();
        void SetX(int n);
        int GetY();
        void SetY(int n);
};