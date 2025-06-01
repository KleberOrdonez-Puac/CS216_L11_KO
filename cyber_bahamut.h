#ifndef CYBER_BAHAMUT_H
#define CYBER_BAHAMUT_H

#include "bahamut.h"

const int CYBER_BONUS = 30, CYBER_CHANCE = 10;

class CyberBahamut : public Bahamut {
public:
    CyberBahamut();
    CyberBahamut(const CyberBahamut& rhsCreature);
    CyberBahamut(string rhsName, int rhsHealth, int rhsStrength);

    ~CyberBahamut();

	string TitleToString() override;
    string GetType() const override;
    int GetDamage() const override;
};

#endif