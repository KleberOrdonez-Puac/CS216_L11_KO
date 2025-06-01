#include "army.h"


Army::Army() {
    SetArmy(DEFAULT_ARMY_NAME, DEFAULT_ARMY_SIZE);
}
Army::Army(const Army& rhsArmy) {
	CopyArmy(rhsArmy);
}
Army::Army(string rhsName, int rhsSize) {
    SetArmy(rhsName, rhsSize);
}

Army::~Army() {
    ClearArmy(ppCreatures, size);
    name = DEFAULT_ARMY_NAME;
    size = DEFAULT_ARMY_SIZE;
}

Army& Army::operator=(const Army& rhs) {
    
	CopyArmy(rhs);

    return *this;
}

void Army::SetArmy(string rhsName, int rhsSize) {
    Creature** ppTemp = nullptr;
    types tempType = static_cast<types>(NUM_OF_TYPES);

    try {
        if (AllAreValid(rhsName, rhsSize)) {

            ppTemp = new Creature * [rhsSize] {nullptr};

            for (int i = 0; i < rhsSize; i++) {
                tempType = static_cast<types>(GiveRanVal(0, NUM_OF_TYPES - 1));
                switch (tempType) {
                case BAHAMUT:
                    ppTemp[i] = new Bahamut;
                    break;
                case CYBER_BAHAMUT:
                    ppTemp[i] = new CyberBahamut;
                    break;
                case CEFFYL:
                    ppTemp[i] = new Ceffyl;
                    break;
                case NUGGLE:
                default:
                    ppTemp[i] = new Nuggle;
                    break;
                }
            }

            ClearArmy(ppCreatures, size);
            ppCreatures = ppTemp;

            name = SetUpper(rhsName);
            size = rhsSize;
        }
    }

    catch (bad_alloc& ba) {
        cout << "\nMemory allocation failed: " << ba.what() << endl;
        ClearArmy(ppTemp, rhsSize);
    }
    catch (...) {
        cout << "\nUnknown error occurred n";
       ClearArmy(ppTemp, rhsSize);
    }
}
void Army::CopyArmy(const Army& rhs) {
    Creature** ppTemp = nullptr;
    types tempType = static_cast<types>(NUM_OF_TYPES);

    if (this != &rhs) {
        try {
            if (AllAreValid(rhs.name, rhs.size)) {

                ppTemp = new Creature * [rhs.size] {nullptr};

                for (int i = 0; i < rhs.size; i++) {
                    tempType = TypeToEnum(rhs.ppCreatures[i]->GetType());
                    switch (tempType) {
                    case BAHAMUT:
                        ppTemp[i] = new Bahamut(*static_cast<Bahamut*>(rhs.ppCreatures[i]));
                        break;
                    case CEFFYL:
                        ppTemp[i] = new Ceffyl(*static_cast<Ceffyl*>(rhs.ppCreatures[i]));
                        break;
                    case NUGGLE:
                        ppTemp[i] = new Nuggle(*static_cast<Nuggle*>(rhs.ppCreatures[i]));
                        break;
                    case CYBER_BAHAMUT:
                        ppTemp[i] = new CyberBahamut(*static_cast<CyberBahamut*>(rhs.ppCreatures[i]));
                        break;
                    }
                }

                ClearArmy(ppCreatures, size);
                ppCreatures = ppTemp;

                name = SetUpper(rhs.name);
                size = rhs.size;
            }
        }

        catch (bad_alloc& ba) {
            cout << "\nMemory allocation failed: " << ba.what() << endl;
            ClearArmy(ppTemp, rhs.size);
        }
        catch (...) {
            cout << "\nUnknown error occurred during memory allocation\n";
            ClearArmy(ppTemp, rhs.size);
        }
    }
}

bool Army::AllAreValid(string rhsName, int rhsSize) const {
    return (NameIsValid(rhsName) && SizeIsValid(rhsSize));
}
bool Army::NameIsValid(string rhs) const {
    int charCount = 0;
    bool valid = false;
    for (int i = 0; i < rhs.length(); i++) {
        if (isalpha(rhs[i])) {
            charCount++;
        }
    }
    if (charCount >= MIN_ARMY_NAME || rhs == DEFAULT_ARMY_NAME) {
        valid = true;
    }
    else{
        cout << "\nInvalid name.\n" << charCount << "\n\n";
    }
    return (valid);
}
bool Army::SizeIsValid(int rhs) const {
    bool valid = false;
    if (rhs < MIN_ARMY_SIZE) {
        cout << "\nArmy size must be greater than " << MIN_ARMY_SIZE << "\n";
    }
    else {
        valid = true;
    }
    return (valid);
}

string Army::HeaderToString() const {
    stringstream tempString;
    tempString << left << setw(TYPE_WIDTH) << "TYPE"
        << setw(NAME_WIDTH) << "NAME"
        << right << setw(HEALTH_WIDTH) << "HEALTH"
        << setw(STRENGTH_WIDTH) << "STRENGTH";
    return tempString.str();
}

string Army::DefendToString(int position) const {
    stringstream tempString;
    tempString << left << setw(ARMY_WIDTH) << name
        << setw(NAME_WIDTH) << ppCreatures[position]->GetName()
        << right << setw(HEALTH_WIDTH) << ppCreatures[position]->GetHealth();
    return tempString.str();
}
string Army::AttackToString(int position, int damage) const {
    stringstream tempString;
    tempString << left << setw(ARMY_WIDTH) << name
        << setw(NAME_WIDTH) << ppCreatures[position]->GetName()
        << right << setw(DAMAGE_WIDTH) << damage;
    return tempString.str();
}

string Army::GetName() const {
    return name;
}
int Army::GetSize() const {
    return size;
}
int Army::GetDamage(int position) {
    int damage = 0;
    if (position >= 0 && position < size) {
        damage = ppCreatures[position]->GetDamage();
    }
    else {
        cout << "\nInvalid position\n";
    }
    return damage;
}
int Army::GetHealth(int position) const {
    int health = 0;
    if (position >= 0 && position < size) {
        health = ppCreatures[position]->GetHealth();
    }
    else {
        cout << "\nInvalid position\n";
    }
    return health;
}
string Army::GetName(int position) const {
    string name = DEFAULT_CREATURE_NAME;
    if (position >= 0 && position < size) {
        name = ppCreatures[position]->GetName();
    }
    else {
        cout << "\nInvalid position\n";
    }
    return name;
}
string Army::GetSingle(int position) const {
    stringstream tempString;
    if (position >= 0 && position < size) {
        tempString << *ppCreatures[position];
    }
    else {
        cout << "\nInvalid position\n";
    }
    return tempString.str();
}


void Army::SetDamage(int position, int damage) {
    int newHealth = 0;

    if (position >= 0 && position < size) {

        newHealth = ppCreatures[position]->GetHealth() - damage;

        if (newHealth < 0) {
            ppCreatures[position]->SetHealth(0);
        }
        else {
            ppCreatures[position]->SetHealth(newHealth);
        }
    }
    else {
        cout << "\nInvalid position\n";
    }
}


void Army::LoadCreatures() {
    string tempType = "", tempName = DEFAULT_CREATURE_NAME;
    int ranStrength = DEFAULT_STRENGTH, ranHealth = DEFAULT_HEALTH, i = 0;

    while (i < size) {
        tempName = "creature_" + to_string(i + 1);
        ranHealth = GiveRanVal(MIN_HEALTH, MAX_HEALTH);
        ranStrength = GiveRanVal(MIN_STRENGTH, MAX_STRENGTH);
        ppCreatures[i]->SetCreature(tempName, ranHealth, ranStrength);
        i++;
    }
}
void Army::Sort(sort selection) {
    bool swapped = false;
    Creature* pTemp = nullptr;


    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            bool shouldSwap = false;

            switch (selection) {
            case TYPE:
                shouldSwap = ppCreatures[j]->GetType() > ppCreatures[j + 1]->GetType();
                break;
            case NAME:
                shouldSwap = ppCreatures[j]->GetName() > ppCreatures[j + 1]->GetName();
                break;
            case HEALTH:
                shouldSwap = ppCreatures[j]->GetHealth() > ppCreatures[j + 1]->GetHealth();
                break;
            case STRENGTH:
                shouldSwap = ppCreatures[j]->GetStrength() > ppCreatures[j + 1]->GetStrength();
                break;
            }
            if (shouldSwap) {
                pTemp = ppCreatures[j];
                ppCreatures[j] = ppCreatures[j + 1];
                ppCreatures[j + 1] = pTemp;
                swapped = true;
            }
        }
    }
}
void Army::Filter(int minHealth, int maxHealth) {
    stringstream tempString;

    for (int i = 0; i < GetSize(); i++) {
        if (ppCreatures[i]->GetHealth() >= minHealth && ppCreatures[i]->GetHealth() <= maxHealth) {
            tempString << "\n" << ppCreatures[i];
        }
    }

    if (tempString.str() == HeaderToString()) {
        cout << "\n\nNo creatures found in the specified range\n";
    }
    else {
        cout << "\n\nCreatures in the specified range:\n"
            << tempString.str();
    }
}
void Army::ClearArmy() {
	ClearArmy(ppCreatures, size);
}
void Army::ClearArmy(Creature**& ppRhs, int rhsSize) {
    if (ppRhs != nullptr)
    {
        for (int i = 0; i < rhsSize; i++) {
            if (ppRhs[i] != nullptr) {
                delete ppRhs[i];
                ppRhs[i] = nullptr;
            }
        }

        delete[] ppRhs;
        ppRhs = nullptr;
    }
}


istream& operator>>(istream& is, Army& rhsArmy) {
    string tempName = DEFAULT_ARMY_NAME;
    int tempSize = DEFAULT_ARMY_SIZE;

	tempName = GetString("Enter the name of the army: ");
	tempSize = GetNum("Enter the size of the army: ");

	rhsArmy.SetArmy(tempName, tempSize);

    return is;
}
ostream& operator<<(ostream& os, const Army& rhsArmy) {

    if (rhsArmy.size == 0) {
        os << "\nThere are no creatures in this army.\n";
    }
    else {
        os << "\n" << rhsArmy.name << "\n" 
           << rhsArmy.HeaderToString() << "\n\n";
        for (int i = 0; i < rhsArmy.size; i++) {
            os << "\n" << *rhsArmy.ppCreatures[i];
        }
    }
    return os;
}

types TypeToEnum(string type) {
    types tempType = static_cast<types>(NUM_OF_TYPES);
    for (int i = 0; i < NUM_OF_TYPES; i++) {
        if (type == TYPE_NAMES[i]) {
            tempType = static_cast<types>(i);
        }
    }
    return tempType;
}