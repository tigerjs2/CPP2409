class User{
    private:
        int hp;
    public:
        User(){hp = 20;}
        void IncreaseHP(int inc_hp);
        void DecreaseHP(int dec_hp);
        int GetHP();
};