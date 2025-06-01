#include "cyber_bahamut.h"

CyberBahamut::CyberBahamut()
    : Bahamut() {
}
CyberBahamut::CyberBahamut(const CyberBahamut& rhsCreature)
    : Bahamut(rhsCreature) {
}
CyberBahamut::CyberBahamut(string rhsName, int rhsHealth, int rhsStrength)
    : Bahamut(rhsName, rhsHealth, rhsStrength) {
}

CyberBahamut::~CyberBahamut() {
    name = DEFAULT_CREATURE_NAME;
    health = DEFAULT_HEALTH;
    strength = DEFAULT_STRENGTH;
}

string CyberBahamut::TitleToString() {
    return name + " the " + GetType();
}
string CyberBahamut::GetType() const {
    return TYPE_NAMES[CYBER_BAHAMUT];
}
int CyberBahamut::GetDamage() const {
    return Bahamut::GetDamage() + ((rand() % 100 < CYBER_CHANCE) ? CYBER_BONUS : 0);
}