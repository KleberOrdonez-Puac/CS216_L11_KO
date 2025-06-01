#include "nuggle.h"

const int NUGGLE_MULTIPLIER = 2, NUGGLE_CHANCE = 15;

Nuggle::Nuggle()
    : Creature() {
}
Nuggle::Nuggle(const Nuggle& rhsCreature)
    : Creature(rhsCreature) {
}
Nuggle::Nuggle(string rhsName, int rhsHealth, int rhsStrength)
    : Creature(rhsName, rhsHealth, rhsStrength) {
}

Nuggle::~Nuggle() {
    name = DEFAULT_CREATURE_NAME;
    health = DEFAULT_HEALTH;
    strength = DEFAULT_STRENGTH;
}

string Nuggle::TitleToString() {
    return name + " the " + GetType();
}
string Nuggle::GetType() const {
    return TYPE_NAMES[NUGGLE];
}
int Nuggle::GetDamage() const {
    int damage = Creature::GetDamage();

    if ((rand() % 100) < NUGGLE_CHANCE) {
        damage = damage * NUGGLE_MULTIPLIER;
    }
    return damage;
}