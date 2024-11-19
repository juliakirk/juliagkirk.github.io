#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <string>
#include "Player.h"
#include "Merchant.h"
#include "Stats.h"
#include "Map.h"
#include "Action.h"
#include "Monster.h"
#include "Puzzle.h"

using namespace std;
using namespace std::this_thread;
using namespace std::chrono_literals;

int randomNumbers(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

int main()
{
    Merchant inventory;
    Stats stats;
    Player party;
    Map map;
    Action act;
    Puzzle puzz;
    Monster monst;

    //Player users;
    cout << "Welcome to Dungeon Escape!" << endl;
    //sleep_for(1s);
    cout << "The game is summarized in these main concepts:" << endl;
    //sleep_for(1s);
    cout << "✦ You will have the opertunity to buy supplies, once at the start of the game and several times throughout. The price will rise as you progress through the game." << endl;
    cout << "✦ You will need to clear 5 rooms to exit the dungeon. To clear a room you need to defeat the monster inside the room." << endl;
    cout << "✦ Keys can be found two ways, fighting monsters and by investigating spaces." << endl;
    cout << "✦ There are oppertunities to cook food along the way, you will need to manage your parties hunger to avoid starvation." << endl;
    cout << "✦ There is a chance to find treasures along the way. You will have an oppertunity to sell these treasures to merchants in exchange for gold." << endl;
    cout << "✦ Misfortunes will happen frequently throughout the game. Examples include getting robbed, items breaking, getting locked in a room, or food posiing. " << endl;
    cout << "✦ Everytime you move to a space that is unexplored the sorcerers anger increses by 1" << endl;
    cout << "✦ You lose if all party members die or if the sorcerers anger reaches 100" << endl;
    cout << "✦ You win when all rooms are cleared and you exit the dungeon" << endl;
    //sleep_for(10s);
    cout << "Good Luck!" << endl;

    string name;

    cout << "Please enter your name: ";
    cin >> name;
    party.setName(name);
    cout<< "Please enter the names of your group members: " << endl;
    for (int i =1; i < 5; i++)
    {
        cout<< "Please enter the name of group member " << i << ": ";
        cin >> name;
        party.setName(name);
    }
    cout << endl;
    cout << endl;
    inventory.shop(stats);
    act.status(stats, inventory, party);
    
    cout << "Map:" << endl;
    int roomCount =0;
    int npcCount = 0;
    int row = 0;
    int col = 0;
    srand(time(0)); // seed the random number generator

    while (roomCount < 5)
    {
        row = randomNumbers(0, 11);
        col = randomNumbers(0,11);
        if ((map.isRoomLocation(row,col) == false))
        {
            map.addRoom(row,col);
            roomCount++;
            //cout << "Room Added at "<< roomCount << " row: " << row << " col: " << col << endl;
            //map.displayMap();
            //cout << endl;
        }
   }
   while (npcCount < 5)
   {
      row = randomNumbers(0, 11);
      col = randomNumbers(0,11);
      if ((map.isRoomLocation(row,col)== false) && (map.isNPCLocation(row,col)== false))
      {
         map.addNPC(row,col);
         npcCount++;
         //cout << "NPC Added at "<< npcCount << " row: "<< row << " col: " << col << endl;
         //map.displayMap();
      }
   }
    map.displayMap();
    cout << "Use the W,A,S & D keys to move around the map." << endl;

    char direction;
    while (stats.getAnger() != 100)
    {   
        bool misProb = false;
        puzz.readLine();
        monst.readMonsters();
        party.setPartySize();
        row = map.getPlayerRow();
        col = map.getPlayerCol();
        char choice;
        act.status(stats, inventory, party);
        map.displayMap();
        act.setTurns();
        //cout << act.getTurns();
        if(map.isExplored(row,col) == false && stats.getRoomsCleared() != 5)
        {
            stats.setAnger();
        }

        if(map.isFreeSpace(row,col) == true)
        {
            cout << "Select one:" << endl;
            cout << "1. Move " << endl;
            cout << "2. Investigate " << endl;
            cout << "3. Pick a fight " << endl;
            cout << "4. Cook and eat " << endl;
            cout << "5. Give up " << endl;
            cin >> choice;

            if(choice == '1')
            {
                cout << "Select a direction to move in:" << endl;
                cin >> direction;
                map.move(direction);
                //cout << party.getPartySize() << endl;
                for(int i = 0; i < party.getPartySize(); i++ )
                {
                    //cout << randomNumbers(1,5) << endl;
                    if(randomNumbers(1,5) == 1)
                    {
                        party.setFullness(1,i);
                    }
                }
            }
            else if(choice == '2')
            {
                if(map.isExplored(row,col)== false)
                {
                    act.investigate(party, stats,  inventory, monst);
                    map.exploreSpace(row, col);
                    int chance = randomNumbers(1,5);
                    if(chance == 1 || chance == 2)
                    {
                        misProb = true;
                    }
                    act.misfortuneEvent(inventory, party, misProb);
                }
                else
                {
                    cout << "This space has already been explored, plese select a different option." << endl;
                }
            }
            else if(choice == '3')
            {
                int fightRooms = stats.getRoomsCleared();
                act.fight(fightRooms, monst ,inventory, party,stats, 1,1);          
            }
            else if(choice == '4')
            {
                act.cookAndEat(party, inventory);
                int chance = randomNumbers(1,5);
                if(chance == 1 || chance == 2)
                {
                    misProb = true;
                }
                act.misfortuneEvent(inventory, party, misProb);
            }
            else if(choice == '5')
            {
                cout << "I'm sorry to see you go. Better luck next time!" << endl;
                break;
            }
            else
            {
                cout << "Invalid Input" << endl;
            }
        }
        else if(map.isRoomLocation(row, col)== true)
        {
            cout << "Select one:" << endl;
            cout << "1. Move " << endl;
            cout << "2. Open the door " << endl;
            cout << "3. Give up " << endl;
            cin >> choice;
            if(choice == '1')
            {
                cout << "Select a direction to move in:" << endl;
                cin >> direction;
                map.move(direction);
                for(int i =0; i < party.getPartySize(); i++ )
                {
                    if(randomNumbers(1,5) == 1)
                    {
                        party.setFullness(1,i);
                    }
                    
                }
            }
            else if(choice == '2')
            {
                act.openDoor(stats, monst, puzz, party, map, inventory);
                stats.useKey();
                int chance = randomNumbers(1,5);
                if(chance == 1 || chance == 2)
                {
                    misProb = true;
                }
                act.misfortuneEvent(inventory, party, misProb);
                map.removeRoom(row, col);
            }
            else if(choice == '3')
            {
                cout << "I'm sorry to see you go. Better luck next time!" << endl;
                break;
            }
            else
            {
                cout << "Invaild input." << endl;
            }
        }
        else if(map.isNPCLocation(row, col) == true)
        {
            cout << "Select one:" << endl;
            cout << "1. Move " << endl;
            cout << "2. Speak to NPC " << endl;
            cout << "3. Give up" << endl;
            cin >> choice;
            if(choice == '1')
            {
                cout << "Select a direction to move in:" << endl;
                cin >> direction;
                map.move(direction);
                for(int i =0; i < party.getPartySize(); i++ )
                {
                    if(randomNumbers(1,5) == 1)
                    {
                        party.setFullness(1,i);
                    }
                }
            }
            else if(choice == '2')
            {
                act.speakNPC(puzz, inventory,stats,monst, party);
                map.removeNPC(row,col);
                map.isExplored(row,col);
                
            }
            else if(choice == '3')
            {
                cout << "I'm sorry to see you go. Better luck next time!" << endl;
                break;
            }
            else
            {
                cout << "Invalid input." << endl;
            }
        
        }
        else if(map.isDungeonExit(row, col)== true)
        {
            if(stats.getRoomsCleared()== 5)
            {
                cout << "Congrats you win!" << endl;
                break;
            }
            else
            {
                cout << "You have not cleared enough rooms to leave the dungeon" << endl;
            }
        }
        if(party.getPartySize() == 1)
        {
            return;
        }
        
    }
    if(stats.getAnger() == 100)
    {
    cout << "The sorcer killed the group. Better luck next time!" << endl;
    }
    //game is over so write ending stats to file
    ofstream file;
    
    file.open("results.txt");
    file << "Game Stats:" << endl;
    file <<"Remaining Players:" << endl;
    party.setPartySize();
    for(int i =0; i < party.getPartySize(); i++)
    {
        file << party.getName(i) << endl;
    }
    file << "Rooms cleared: " <<stats.getRoomsCleared() << endl;
    file << "Gold Remaining: " << inventory.getGold()<< endl;;
    file << "Treasure:" << endl;
    file << "Silver Rings: " << inventory.getTreasure(0)<< endl;
    file << "Ruby Necklaces: " << inventory.getTreasure(1)<< endl;
    file << "Emerald Bracelets: " << inventory.getTreasure(2)<< endl;
    file << "Diamond Circlets: " << inventory.getTreasure(3)<< endl;
    file << "Gem-encrusted Goblets: " << inventory.getTreasure(4)<< endl;
    file << "Number of Spaces Explored: " << act.getExploredSpaces() << endl;
    file << "Number of Monsters Defeated: " << act.getMonstersDef() << endl;
    file << "Number of Turns: " << act.getTurns() << endl;
    file.close();
    return 0;

}

