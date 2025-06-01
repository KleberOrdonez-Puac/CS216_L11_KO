#ifndef ARMY_H
#define ARMY_H

#include "bahamut.h"
#include "cyber_bahamut.h"
#include "ceffyl.h"
#include "nuggle.h"

const int MIN_ARMY_SIZE = 5, MAX_ARMY_SIZE = 30, DEFAULT_ARMY_SIZE = 5, MIN_ARMY_NAME = 3;
const string DEFAULT_ARMY_NAME = "ARMY";

enum sort { TYPE = 1, NAME, HEALTH, STRENGTH, RETURN };

class Army {
private:
    int size = DEFAULT_ARMY_SIZE;
    string name = DEFAULT_CREATURE_NAME;
    Creature** ppCreatures = nullptr;

public:
    Army();
    Army(const Army& rhsArmy);
    Army(string rhsName, int rhsSize);

    ~Army();

    Army& operator=(const Army& rhs);

    void SetArmy(string rhsName, int rhsSize);
	void CopyArmy(const Army& rhs);

    bool AllAreValid(string rhsName, int rhsSize) const;
    bool NameIsValid(string rhs) const;
    bool SizeIsValid(int rhs) const;

    string HeaderToString() const;
    string DefendToString(int position) const;
    string AttackToString(int position, int damage) const;

    string GetName() const;
    int GetSize() const;
    int GetDamage(int position);
    int GetHealth(int position) const;
    string GetName(int position)const;
    string GetSingle(int position) const;


    void SetDamage(int postion, int damage);

    void LoadCreatures();
    void Sort(sort selection);
    void Filter(int minHealth, int maxHealth);
    void ClearArmy();
    void ClearArmy(Creature**& ppRhs, int rhsSize);

    friend istream& operator>>(istream& is, Army& rhsArmy);
    friend ostream& operator<<(ostream& os, const Army& rhsArmy);
};

types TypeToEnum(string rhs);


#endif