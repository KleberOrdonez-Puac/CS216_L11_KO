#include "game.h"

Game::Game() {
}
Game::Game(const Game& rhs) {
	CopyGame(rhs);
}
Game::Game(string playerName, string oppName, int rhsSize) {
    player.SetArmy(playerName, rhsSize);
    opponent.SetArmy(oppName, rhsSize);
    size = rhsSize;
}

Game::~Game() {
    size = DEFAULT_ARMY_SIZE;
    cout << "\nGame has ended\n\n";
}

Game& Game::operator=(const Game& rhs) {
	if (this != &rhs) {
        CopyGame(rhs);
	}
	return *this;
}

void Game::CopyGame(const Game& rhs) {
	if (SizeIsValid(rhs.size)) {
		player = rhs.player;
		opponent = rhs.opponent;
		size = rhs.size;
	}
}
bool Game::SizeIsValid(int rhs)const {
    bool valid = false;
    if (rhs < MIN_ARMY_SIZE) {
        cout << "\nArmy size must be greater than " << MIN_ARMY_SIZE << "\n";
    }
    else {
        valid = true;
    }
    return (valid);
}
bool Game::SetGame(string playerName, string oppName, int armySize) {
    if (SizeIsValid(armySize)) {
        player.SetArmy(playerName, armySize);
        opponent.SetArmy(oppName, armySize);
        player.LoadCreatures();
        opponent.LoadCreatures();

        size = armySize;
    }

    return player.GetSize() == armySize && opponent.GetSize() == armySize;
}

void Game::Play() {
	InputArmyVals();

	cout << FillerToString()
		<< "\nOriginal stats:\n"
		<< ArmiesToString()
		<< FillerToString();
	for (int i = 0; i < size; i++) {
		cout << FillerToString()
			<< HeaderToString(i)
			<< RoundToString(i)
			<< FillerToString();
	}
	cout << WinnerToString();
}
void Game::InputArmyVals() {
    int inputSize = 0;
    string playerName = DEFAULT_ARMY_NAME, opponentName = DEFAULT_ARMY_NAME;

    ClearInputError();

	playerName = GetString("Name your army: ");
	opponentName = GetString("Name your opponent's army: ");
	inputSize = GetNum("Enter the size of the armies: ");


	cout << playerName << " vs " << opponentName << "\n"
		<< "Army size: " << inputSize << "\n";

    if (!SetGame(playerName, opponentName, inputSize)) {
        cout << "An error occurred while setting the game.\n"
                "Please try again later";
    }
}
int Game::GetSize() const {
    return size;
}

string Game::FillerToString() const {
    stringstream tempString;
    int totalWidth = (CREATURE_WIDTH * 2) + GAP_WIDTH;

    tempString << "\n" << setfill('-') << setw(totalWidth) << "" << "\n";
    return tempString.str();
}
string Game::ArmiesToString() const {
    stringstream tempString;

    tempString << "\n" << left
        << setw(CREATURE_WIDTH) << player.GetName() << setw(GAP_WIDTH) << ""
        << setw(CREATURE_WIDTH) << opponent.GetName() << "\n\n"
        << player.HeaderToString() << setw(GAP_WIDTH)
        << "" << opponent.HeaderToString() << "\n\n";

    for (int i = 0; i < size; i++) {
        tempString << player.GetSingle(i) << setw(GAP_WIDTH) << ""
            << opponent.GetSingle(i) << "\n";
    }
    return tempString.str();
}
string Game::WinnerToString() const {
    stringstream tempString;
    int playerNetHealth = 0, oppNetHealth = 0;

    for (int i = 0; i < size; i++) {
        playerNetHealth += player.GetHealth(i);
        oppNetHealth += opponent.GetHealth(i);
    }

    tempString << FillerToString();

    if (playerNetHealth > oppNetHealth) {
        tempString << "\n" << player.GetName() << " has won with a net health of "
            << playerNetHealth << " to " << opponent.GetName() << "'S net health of " << oppNetHealth << "\n";
    }
    else if (playerNetHealth < oppNetHealth) {
        tempString << "\n" << opponent.GetName() << " has won with a net health of "
            << oppNetHealth << " to " << player.GetName() << "'S net health of " << playerNetHealth << "\n";
    }
    else {
        tempString << "Both " << player.GetName() << " and " << opponent.GetName() << " have the same net health of "
            << playerNetHealth << "\n";
    }

    tempString << FillerToString();

    return tempString.str();
}
string Game::HeaderToString(int position) const {
    stringstream tempString;

    tempString << "\nRound " << position + 1 << "\n\n" << left
        << setw(ARMY_WIDTH) << "ARMY"
        << setw(NAME_WIDTH) << "ATTACKER"
        << right << setw(DAMAGE_WIDTH) << "DAMAGE"
        << setw(GAP_WIDTH) << ""
        << left << setw(ARMY_WIDTH) << "ARMY"
        << setw(NAME_WIDTH) << "DEFENDER"
        << right << setw(HEALTH_WIDTH) << "HEALTH" << "\n\n";

    return tempString.str();
}
string Game::RoundToString(int position) {
    stringstream tempString;
    int damage = 0;
    bool playerTurn = true;

    if (rand() % 2 == 0) {
        playerTurn = false;
    }

    while (player.GetHealth(position) > 0 && opponent.GetHealth(position) > 0) {
        if (playerTurn) {
            damage = player.GetDamage(position);
            tempString << MoveToString(player, opponent, position, damage);
            opponent.SetDamage(position, damage);
            playerTurn = false;
        }
        else {
            damage = opponent.GetDamage(position);
            tempString << MoveToString(opponent, player, position, damage);
            player.SetDamage(position, damage);
            playerTurn = true;
        }
    }

    if (playerTurn) {
        tempString << "\n" << player.GetName() << "'S " << player.GetName(position)
            << " has been defeated by "
            << opponent.GetName() << "'S " << opponent.GetName(position) << "\n";
    }
    else {
        tempString << "\n" << opponent.GetName() << "'S " << opponent.GetName(position)
            << " has been defeated by "
            << player.GetName() << "'S " << player.GetName(position) << "\n";
    }

    tempString << "\n\nCurrent stats:\n" << ArmiesToString();

    return tempString.str();
}
string Game::MoveToString(const Army& attacker, const Army& defender, int position, int damage) const {
    stringstream tempString;
    tempString << attacker.AttackToString(position, damage)
        << right << setw(GAP_WIDTH) << " "
        << defender.DefendToString(position) << "\n";
    return tempString.str();
}