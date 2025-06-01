#ifndef NUGGLE_H
#define NUGGLE_H

#include "creature.h"

class Nuggle : public Creature {
public:
    Nuggle();
    Nuggle(const Nuggle& rhsCreature);
    Nuggle(string rhsName, int rhsHealth, int rhsStrength);

    ~Nuggle();
    
	string TitleToString();
    string GetType() const;
    int GetDamage() const;
};
#endif