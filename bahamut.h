#ifndef BAHAMUT_H
#define BAHAMUT_H

#include "creature.h"

class Bahamut : public Creature {
public:
    Bahamut();
    Bahamut(const Bahamut& rhsCreature);
    Bahamut(string rhsName, int rhsHealth, int rhsStrength);

    virtual ~Bahamut();

    virtual string TitleToString();
    string GetType() const override;
    int GetDamage() const override;

};

#endif