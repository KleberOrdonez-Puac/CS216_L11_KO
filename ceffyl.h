#ifndef CEFFYL_H
#define CEFFYL_H

#include "creature.h"

const int CEFFYL_BONUS = 25, CEFFYL_CHANCE = 15;

class Ceffyl : public Creature {
public:
    Ceffyl();
    Ceffyl(const Ceffyl& rhsCreature);
    Ceffyl(string rhsName, int rhsHealth, int rhsStrength);

    ~Ceffyl();

	string TitleToString();
    string GetType() const;
    int GetDamage() const;
};

#endif
