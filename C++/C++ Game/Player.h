#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>

using namespace std;

class Player
{
    public:

    Player();
    int getPartySize();
    void setPartySize();
    int getFullness(int i);
    void setFullness(int change, int i);
    void incFullness(int change, int i);
    string getName(int i);
    void setName(string nameEnter);
    void loseMember(int i);
   
  
    private:
    string nameEnter;
    int partySize;
    //int fullness;
    struct Party
    {
       string name = "";
       int fullness=0;

    };
    vector<Party>group;
    


};

#endif