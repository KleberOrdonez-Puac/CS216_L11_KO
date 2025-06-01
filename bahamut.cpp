#include "bahamut.h"

Bahamut::Bahamut( )  : Creature() {
}
Bahamut::Bahamut(const Bahamut& rhsCreature): Creature(rhsCreature)
{
}
Bahamut::Bahamut(string rhsName, int rhsHealth, int rhsStrength): Creature(rhsName, rhsHealth, rhsStrength) 
{
}

Bahamut::~Bahamut() {

}

string Bahamut::TitleToString() {
	return name + " the " + GetType();
}
string Bahamut::GetType() const {
    return TYPE_NAMES[BAHAMUT];
}
int Bahamut::GetDamage() const {
    return Creature::GetDamage() + Creature::GetDamage();
}
