#ifndef CLASSES_H
#define CLASSES_H
#include <string>

using namespace std;

class Agent {
private:
    int HP;
    int Mobility;
    int Damage;
    int AttackRanger;
    bool waterWalking;
    bool standOnWater;
    bool rockWalking;
    bool standOnRock;

public:
    Agent(int HP, int Mobility, int Damage, int AttackRanger,
          bool waterWalking, bool standOnWater, bool rockWalking, bool standOnRock)
        : HP(HP), Mobility(Mobility), Damage(Damage), AttackRanger(AttackRanger),
        waterWalking(waterWalking), standOnWater(standOnWater),
        rockWalking(rockWalking), standOnRock(standOnRock) {}

    int getHP() const { return HP; }
    int getMobility() const { return Mobility; }
    int getDamage() const { return Damage; }
    int getAttackRanger() const { return AttackRanger; }

    // getterهای bool
    bool getWaterWalking() const { return waterWalking; }
    bool getStandOnWater() const { return standOnWater; }
    bool getRockWalking() const { return rockWalking; } // تصحیح اسم: rockWalking نه ockWalking
    bool getStandOnRock() const { return standOnRock; } // تصحیح اسم: standOnRock نه standOnRock

    void setHP(int hp) {HP = hp;}
    void setMobility(int m) {Mobility = m;}
    void setDamage(int d) {Damage = d;}
    void setAttackRanger(int a) {AttackRanger = a;}
};
class WaterWalking :public Agent {
public:
    WaterWalking(int HP, int Mobility, int Damage, int AttackRanger, bool waterWalking, bool standOnWater, bool rockWalking, bool standOnRock)
        : Agent(HP, Mobility, Damage, AttackRanger, waterWalking, waterWalking, rockWalking, standOnRock){}

};

class Grounded :public Agent {
public:
    Grounded(int HP, int Mobility, int Damage, int AttackRanger, bool waterWalking, bool standOnWater, bool rockWalking, bool standOnRock)
        : Agent(HP, Mobility, Damage, AttackRanger, waterWalking, waterWalking, rockWalking, standOnRock){}
};

class Flying :public Agent {
public:
   //FLying(int HP, int Mobility, int Damage, int AttackRanger)
        //: Agent(HP, Mobility, Damage, AttackRanger){}
};

class Floating :public Agent {
public:
    Floating(int HP, int Mobility, int Damage, int AttackRanger, bool waterWalking, bool standOnWater, bool rockWalking, bool standOnRock)
        : Agent(HP, Mobility, Damage, AttackRanger, waterWalking, waterWalking, rockWalking, standOnRock){}
};

#endif // CLASSES_H
