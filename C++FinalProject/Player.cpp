// CSCI 1300 Fall 2022
// Author: Julia Kirk
// Recitation: 105 – Raegan Rychecky
// Project 3

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "Player.h"
using namespace std;

Player:: Player()
{
    partySize = -1;
    vector<Party>group;

}
int Player :: getPartySize()
{
    return partySize;
}
void Player:: setPartySize()
{
    partySize = group.size();
}
int Player:: getFullness(int i)
{
    return group[i].fullness;
}
void Player:: setFullness(int change, int i) // prints out hunger messages when needed and decresed hunger
{
    group[i].fullness -= change;   
    if(group[0].fullness == 0)
    {
        cout << "Oh no! " << group[0].name << " has died of hunger!" << endl;
        cout << "Game Over!" << endl;
    }
    else if(group[i].fullness <= 0)
    {
        cout << "Oh no! " << group[i].name << " has died of hunger!" << endl;
        loseMember(i);
        cout << "Your party size has reduced to " << getPartySize() << " members." << endl;
    }
 
    else if(group[i].fullness <= 10)
    {
        cout << "Warning: " << group[i].name << " is on the brink of starvation!" << endl;
        cout << "You should cook and eat some food. " << endl;
    }
}
string Player::getName(int i)
{
    return group[i].name;
}
void Player::setName(string nameEnter) // sets inital structs
{
    Party member;
    member.name = nameEnter;
    member.fullness = 50;
    group.push_back(member);
    
}
void Player :: loseMember(int i) // deletes member at position
{
    group.erase(group.begin() + i);
    setPartySize();
}
void Player:: incFullness(int change, int i) // for when players eat
{
    group[i].fullness += change;
}