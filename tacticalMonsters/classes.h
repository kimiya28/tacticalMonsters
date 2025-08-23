#ifndef CLASSES_H
#define CLASSES_H
#include <string>

using namespace std;

class Agent{
private:
    int HP;
    int Mobility;
    int Damage;
    int AttackRanger;
public:
    Agent(int HP, int Mobility, int Damage, int AttackRanger)
        :HP(HP), Mobility(Mobility), Damage(Damage), AttackRanger(AttackRanger){}

    int getHP() const {return HP;}
    int getMobility() const {return Mobility;}
    int getDamage() const {return Damage;}
    int getAttackRanger() const {AttackRanger;}

    void setHP(int hp) {HP = hp;}
    void setMobility(int m) {Mobility = m;}
    void setDamage(int d) {Damage = d;}
    void setAttackRanger(int a) {AttackRanger = a;}
};
class WaterWalking :public Agent {
public:
    WaterWalking(int HP, int Mobility, int Damage, int AttackRanger)
        : Agent(HP, Mobility, Damage, AttackRanger){}

};

class Grounded :public Agent {
public:
    Grounded(int HP, int Mobility, int Damage, int AttackRanger)
        : Agent(HP, Mobility, Damage, AttackRanger){}
};

class Flying :public Agent {
public:
   // FLying(int HP, int Mobility, int Damage, int AttackRanger)
    //    : Agent(HP, Mobility, Damage, AttackRanger){}
};

class Floating :public Agent {
public:
    Floating(int HP, int Mobility, int Damage, int AttackRanger)
        : Agent(HP, Mobility, Damage, AttackRanger){}
};

#endif // CLASSES_H
