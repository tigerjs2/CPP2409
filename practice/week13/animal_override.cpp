#include <iostream>
using namespace std;

class Animal {
    public:
        virtual void Move() = 0;
        virtual void Eat() = 0;
        virtual void Speak() = 0;
        void AnimalSpeak() {
            cout << "동물의 Speak()" << endl;
        }
};

class Lion : public Animal {
    public:
        void Move() override {
            cout << "사자의 Move()" << endl;
        }
        void Eat() override {
            cout << "사자의 Eat()" << endl;
        }
        void Speak() override {
            cout << "사자의 Speak()" << endl;
        }
};

int main() {
    Animal *lion = new Lion();
    lion->Speak();
    lion->AnimalSpeak();
    delete lion;
    return 0;
}