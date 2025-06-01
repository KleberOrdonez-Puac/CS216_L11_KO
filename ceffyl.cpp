#include "ceffyl.h"

Ceffyl::Ceffyl()
    : Creature() {
}
Ceffyl::Ceffyl(const Ceffyl& rhsCreature) : Creature(rhsCreature) {
}
Ceffyl::Ceffyl(string rhsName, int rhsHealth, int rhsStrength) : Creature(rhsName, rhsHealth, rhsStrength) {
    SetCreature(rhsName, rhsHealth, rhsStrength);
}

Ceffyl::~Ceffyl() {
    name = DEFAULT_CREATURE_NAME;
    health = DEFAULT_HEALTH;
    strength = DEFAULT_STRENGTH;
}

string Ceffyl::TitleToString() {
    return name + " the " + GetType();
}
string Ceffyl::GetType() const {
    return TYPE_NAMES[CEFFYL];
}
int Ceffyl::GetDamage() const {
    int damage = Creature::GetDamage();

    if ((rand() % 100) < CEFFYL_CHANCE) {
        damage += CEFFYL_BONUS;
    }
    return Creature::GetDamage();
}
