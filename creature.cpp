#include "creature.h"


Creature::Creature() { }
Creature::Creature(const Creature& rhsCreature) {
    SetCreature(rhsCreature.name, rhsCreature.health, rhsCreature.strength);
}
Creature::Creature(string rhsName, int rhsHealth, int rhsStrength) {
    SetCreature(rhsName, rhsHealth, rhsStrength);
}

Creature::~Creature() {
    name = DEFAULT_CREATURE_NAME;
    health = DEFAULT_HEALTH;
    strength = DEFAULT_STRENGTH;
}

Creature& Creature::operator=(const Creature& rhs) {
	if (this != &rhs) {
		SetCreature(rhs.name, rhs.health, rhs.strength);
	}
	return *this;
}

void Creature::SetCreature(string rhsName, int rhsHealth, int rhsStrength) {
    if (AllAreValid(rhsName, rhsHealth, rhsStrength)) {
        name = SetUpper(rhsName);
        health = rhsHealth;
        strength = rhsStrength;
    }
    else {
		cout << "\nInvalid creature values. Using default values.\n";
    }
}
void Creature::SetName(string rhsName) {
    SetCreature(rhsName, health, strength);
}
void Creature::SetHealth(int rhsHealth) {
    SetCreature(name, rhsHealth, strength);
}
void Creature::SetStrength(int rhsStrength) {
    SetCreature(name, health, rhsStrength);
}

bool Creature::AllAreValid(string rhsName, int rhsHealth, int rhsStrength) const {
    return (NameIsValid(rhsName) && HealthIsValid(rhsHealth) && StrengthIsValid(rhsStrength));
}
bool Creature::NameIsValid(string rhs) const {
    int charCount = 0;
    bool valid = false;

    for (int i = 0; i < rhs.length(); i++) {
        if (isalpha(rhs[i])) {
            charCount++;
        }
    }
    if (charCount >= MIN_CREATURE_NAME || rhs == DEFAULT_CREATURE_NAME) {
        valid = true;
    }

    if (!valid) {
        cout << "\nInvalid name.";
    }

    return valid;
}
bool Creature::HealthIsValid(int rhs) const {
    return (rhs >= 0 && rhs <= MAX_HEALTH);
}
bool Creature::StrengthIsValid(int rhs) const {
    return (rhs >= MIN_STRENGTH && rhs <= MAX_STRENGTH);
}

string Creature::GetType() const {
	return DEFAULT_TYPE; 
} 
string Creature::GetName() const {
    return name;
}
int Creature::GetHealth() const {
    return health;
}
int Creature::GetStrength() const {
    return strength;
}
int Creature::GetDamage() const {
    return rand() % strength + 1;
}

ostream& operator<<(ostream& os, const Creature& rhsCreature) {
    os << left << setw(TYPE_WIDTH) << rhsCreature.GetType() << setw(NAME_WIDTH)
        << rhsCreature.name << right << setw(HEALTH_WIDTH) << rhsCreature.health
        << setw(STRENGTH_WIDTH) << rhsCreature.strength;
    return os;
}
