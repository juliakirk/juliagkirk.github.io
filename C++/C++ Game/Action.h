#ifndef ACTION_H
#define ACTION_H
#include <iostream>
#include <vector>
#include "Player.h"
#include "Merchant.h"
#include "Stats.h"
#include "Map.h"
#include "Action.h"
#include "Monster.h"
#include "Puzzle.h"

using namespace std;

class Action
{
public:
    Action();
    void investigate(Player& party, Stats& stats, Merchant& inventory, Monster monst);
    void cookAndEat(Player& party, Merchant& inventory);
    void speakNPC(Puzzle& puzz, Merchant& inventory,Stats& stats,Monster& monst,Player& party);
    void openDoor(Stats& stats, Monster& monst, Puzzle& puzz, Player& party, Map& map, Merchant inventory);
    void split(string input_string, char seperator);
    void fight(int rooms, Monster& monst, Merchant& inventory, Player& party, Stats& stats, int inc, int key);
    void status(Stats& stats, Merchant& inventory, Player& party);
    void misfortuneEvent(Merchant& inventory, Player& party, bool mis);
    int getExploredSpaces();
    int getTurns();
    int getMonstersDef();
    void setExploredSpaces();
    void setTurns();
    void setMonstersDef();
    void BSP(Stats& stats, Player& party, Map& map);
    double AttackVal(Merchant& inventory, Player& party, int rate);

private:
    int exploredSpaces;
    int turns;
    int monstersDef;
    double attack;

};

#endif
