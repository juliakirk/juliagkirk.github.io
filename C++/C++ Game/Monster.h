#ifndef MONSTER_H
#define MONSTER_H
#include <iostream>
#include <vector>

/**
 * controls monsters and their attributes
 */
using namespace std;

class Monster
{
private:
    struct monst
    {
        string name = "";
        int rating = 0;
    };
    vector<monst>fights;
    int monstSize;
    
public:
    Monster();
    void setMonster(string name, int level);
    string getName(int i);
    int getRating(int i);
    void readMonsters();
    void setSize();
    int getSize();
};

#endif

