#ifndef GAME_H
#define GAME_H

#include "army.h"

class Game {
private:
    Army player;
    Army opponent;
    int size = DEFAULT_ARMY_SIZE;

public:
    Game();
    Game(const Game& rhsGame);
    Game(string playerName, string oppName, int inputSize);

    ~Game();

	Game& operator=(const Game& rhs);

    void CopyGame(const Game& rhs);
    bool SetGame(string playerName, string oppName, int armySize);
    bool SizeIsValid(int rhs)const;

    void Play();
    void InputArmyVals();
    int GetSize() const;

    string FillerToString() const;
    string ArmiesToString() const;
    string WinnerToString() const;
    string HeaderToString(int position) const;
    string RoundToString(int position);
    string MoveToString(const Army& attacker, const Army& defender, int position, int damage) const;


};

#endif