#ifndef CREATURE_H
#define CREATURE_H

#include "helper.h"

using namespace std;

enum types { BAHAMUT = 0, CYBER_BAHAMUT, CEFFYL, NUGGLE };
const int NUM_OF_TYPES = 4;
const string TYPE_NAMES[NUM_OF_TYPES] = { "BAHAMUT", "CYBER BAHAMUT", "CEFFYL", "NUGGLE" };
const string DEFAULT_TYPE = "CREATURE";

const int NAME_WIDTH = 14, TYPE_WIDTH = 15, HEALTH_WIDTH = 8, STRENGTH_WIDTH = 10,
          DAMAGE_WIDTH = 8, ARMY_WIDTH = 16, GAP_WIDTH = 10;

const int MAX_HEALTH = 250, MIN_HEALTH = 120, DEFAULT_HEALTH = 150;
const int MAX_STRENGTH = 250, MIN_STRENGTH = 120, DEFAULT_STRENGTH = 150;

const int CREATURE_WIDTH = TYPE_WIDTH + NAME_WIDTH + HEALTH_WIDTH + STRENGTH_WIDTH;

const int MIN_CREATURE_NAME = 3;
const string DEFAULT_CREATURE_NAME = "CREATURE";

class Creature {
protected:
    string name = DEFAULT_CREATURE_NAME;
    int health = DEFAULT_HEALTH;
    int strength = DEFAULT_STRENGTH;


public:
    Creature();
    Creature(const Creature& rhsCreature);
    Creature(string rhsName, int rhsHealth, int rhsStrength);

    virtual ~Creature();

	Creature& operator=(const Creature& rhs);

    void SetCreature(string rhsName, int rhsHealth, int rhsStrength);
    void SetName(string rhsName);
    void SetHealth(int rhsHealth);
    void SetStrength(int rhsStrength);

    bool AllAreValid(string rhsName, int rhsHealth, int rhsStrength) const;
    bool NameIsValid(string rhs) const;
    bool HealthIsValid(int rhs) const;
    bool StrengthIsValid(int rhs) const;

    virtual string TitleToString()=0;

    string GetName() const;
    int GetHealth() const;
    int GetStrength() const;
    virtual string GetType() const;
    virtual int GetDamage() const;

    friend ostream& operator<<(ostream& os, const Creature& rhsCreature);
};

#endif