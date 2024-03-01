#include <iostream>
#include "Player.h"
#include "Merchant.h"
#include "Stats.h"
#include "Map.h"
#include "Action.h"
#include "Monster.h"
#include "Puzzle.h"

using namespace std;

/**
 * @brief 
 * class to control actions in game 
 * 
 */
int randNumbers(int min, int max) // rand num generator
{
    return (rand() % (max - min + 1)) + min;
}
Action :: Action() // defalut constructor
{
    exploredSpaces = 0;
    turns = 0;
    monstersDef = 0;
}
void Action :: investigate(Player& party, Stats& stats, Merchant& inventory, Monster monst) // controls investigate
{
    /**
     * randomize for prob
     * based on outcome perform different actions
     */
    int prob = randNumbers(1,10); // randomize and follow actions based on outcome
    if(prob == 1)
    {
        cout << "You found a key!" << endl;
        stats.setKeys();
    }
    else if(prob == 2 || prob == 3)
    {
        int rooms = stats.getRoomsCleared();
        if(rooms == 0)
        {
            cout << "You found a Silver ring!" << endl;
            inventory.setTreasure(0);
        }
        else if(rooms == 1)
        {
            cout << "You found a ruby necklace!" << endl;
            inventory.setTreasure(1);
        }
        else if(rooms == 2)
        {
            cout << "You found an emerald braclet!" << endl;
            inventory.setTreasure(2);
        }
        else if(rooms == 3)
        {
            cout << "You found a diamond circlet!" << endl;
            inventory.setTreasure(3);
        }
        else if(rooms == 4)
        {
            cout << "You found a gem-encrusted goblet!" << endl;
            inventory.setTreasure(4);
        }
    }
    else if(prob == 4 || prob == 5)
    {
        int rooms = stats.getRoomsCleared();
        fight(rooms, monst ,inventory, party,stats, 1,1);

    }
    else
    {
        cout << "Unfontunatly your investigation was unsuccessful." << endl;
    }
    for(int i = 0; i < party.getPartySize()-1; i++ )
    {
        if(randNumbers(1,2) == 1)
        {
            party.setFullness(1,i);
        }
    }
}
void Action ::cookAndEat(Player& party, Merchant& inventory)
{
    /**
     * action of cooking and eating
     * prompt user
     * validate 
     * attempt to cook
     * if succesful update hunger
     * deceres use amounts
     */
    int input;
    int cook;
    int breakProb;
    cout<< "How much food would you like to cook? Please enter an interger of 5." << endl;
    cin >> input;
    while (input % 5 != 0)
   {
       cout << "That is not a valid input, please enter a positive integer of 5, or 0 to exit)" << endl;
       cin >> input;
   }

    if(input > inventory.getIngredients())
    {
        cout << "Insufficent inventory." << endl;
    }
    else
    {
        cout << "You own the following cookware: " << endl;
        cout  << "1. Ceramic Pot: " << inventory.getCookware(0) << endl;
        cout << "2. Frying Pan: " << inventory.getCookware(1) << endl;
        cout << "3. Cauldron: " << inventory.getCookware(2) << endl;
        cout << "What cookwear would you like to use?" << endl;
        cin >> cook;

        if(cook == 1)
        {
            if(inventory.getCookware(0) == 0)
            {
                cout << "Insufficent inventory." << endl;
            }
            else
            {
                breakProb = randNumbers(1,4);
                if(breakProb == 1)
                {
                    cout << "Oh no! Your Ceramic Pot broke." << endl;
                    inventory.cookwearBreak(0, input);
                    //cout << inventory.getIngredients();
                }
                else
                {
                    int cookedAmount = input / 5;
                    cout << "Cook successful! Each members hunger has incresed by " << cookedAmount << "." << endl;
                    inventory.useFood(input);
                    party.setPartySize();
                    //cout << party.getPartySize() << endl;
                    for(int i = 0; i < party.getPartySize()-1; i++)
                    {
                        party.incFullness(cookedAmount, i);
                    }
                }
            }
        }
        else if(cook ==2)
        {
            if(inventory.getCookware(1) == 0)
            {
                cout << "Insufficent inventory." << endl;
            }
            else
            {
                breakProb = randNumbers(1,4);
                if(breakProb == 1)
                {
                    cout << "Oh no! Your Frying pan broke." << endl;
                    inventory.cookwearBreak(1, input);
                }
                else
                {
                    int cookedAmount = input / 5;
                    cout << "Cook successful! Each members hunger has incresed by " << cookedAmount << "." << endl;
                    inventory.useFood(input);
                    party.setPartySize();
                    for(int i = 0; i < party.getPartySize()-1; i++)
                    {
                        party.incFullness(cookedAmount, i);
                    }
                }
            }

        }
        else if (cook == 3)
        {
            if(inventory.getCookware(2) == 0)
            {
                cout << "Insufficent inventory." << endl;
            }
            else
            {
                breakProb = randNumbers(1,50);
                if(breakProb == 1)
                {
                    cout << "Oh no! Your Cauldron broke." << endl;
                    inventory.cookwearBreak(2, input);
                }
                else
                {
                    int cookedAmount = input / 5;
                    cout << "Cook successful! Each members hunger has incresed by " << cookedAmount << "." << endl;
                    inventory.useFood(input);
                    party.setPartySize();
                    for(int i = 0; i < party.getPartySize(); i++)
                    {
                        party.incFullness(cookedAmount, i);
                    }
                }
            }
        }
        else
        {
            cout << "Invalid input." << endl;
        }
    }
}
void Action ::speakNPC(Puzzle& puzz, Merchant& inventory,Stats& stats,Monster& monst,Player& party)
{
    /**
     * prompt user with q
     * have answer
     * of right then shop
     * else fight monster
     */
    int rooms = stats.getRoomsCleared();
    string answer;
    int puzzNum = randNumbers(0, puzz.getSize());
    cout << "To continue you will need to complete a puzzle?" << endl;
    cout << puzz.getRiddle(puzzNum) << endl;
    cout << "What do you belive the answer is?" << endl;
    cin >> answer;
    if(answer == puzz.getAnswer(puzzNum))
    {
        cout << "You successfully answered the riddle! Would you like to shop?(y/n)" << endl;
        cin >> answer;
        if( answer == "y" || answer == "Y")
        {
            inventory.shop(stats);
        }
    }
    else
    {
        int rooms = stats.getRoomsCleared();
        fight(rooms, monst ,inventory, party,stats, 1,3);
    }
}
void Action ::openDoor(Stats& stats, Monster& monst, Puzzle& puzz, Player& party, Map& map, Merchant inventory)
{
    /**
     * check key is in inventory
     * if not play game
     * if it is fight monster
     */
    int keys = stats.getKeys();
    int rooms = stats.getRoomsCleared();
    if(keys >= 1)
    {
        fight(rooms, monst ,inventory, party,stats,2, 2);
    }
    else
    {
        cout << "Oh no! You fell into a trap, Win the game to escape!" << endl;
        BSP(stats, party, map);
    }
}
void Action:: fight(int rooms, Monster& monst, Merchant& inventory, Player& party, Stats& stats, int inc, int key)
{
    /**
     * find monster to fight
     * calcuate attack value
     * propt with options
     * fight or surrender
     */
    int monstLev = 0;
    int desLevel = rooms + inc;
    int choice = 0;
    int misProb = false;
    while(choice != 2)
    {
        monst.setSize();
        int rand = randNumbers(0,monst.getSize());
        if(desLevel == monst.getRating(rand))
        {
            cout << "Oh no! A " << monst.getName(rand) << " is approching!" << endl;
            cout << "Chose an option:" << endl;
            cout << "1. Fight" << endl;
            cout << "2. Surrender" << endl;
            cin >> choice;

            if(choice ==1)
            {
                if(AttackVal(inventory, party, rand) > 0)
                {
                    cout << "You win!" << endl;
                    monstersDef += 1;
                    int chance = randNumbers(1,5);
                    
                    if(key == 1)
                    {   
                         if(chance == 1 || chance == 2)
                        {
                            misProb = true;
                        }
                        misfortuneEvent(inventory, party, misProb);
                        int prob = randNumbers(1, 10);
                        if(prob == 1)
                        {
                            stats.setKeys();
                        }  
                    }
                    if (key == 2)
                    {
                        if(chance == 1 || chance == 2 || chance == 3)
                        {
                            misProb = true;
                        }
                        misfortuneEvent(inventory, party, misProb);
                    }
                }
                else
                {
                    cout << "You lose!" << endl;
                    int goldDec = inventory.getGold()/ 4;
                    inventory.setGold(goldDec);

                    return;
                }
               return;
            }
            else
            {   
                party.setPartySize();
                rand = randNumbers(1,party.getPartySize()-1);
                cout << party.getName(rand) << " was unable to escape the monster!" << endl;
                party.loseMember(rand);
                int chance = randNumbers(1,5);
                if(chance == 1 || chance == 2)
                {
                    misProb = true;
                }
                misfortuneEvent(inventory, party, misProb);
                break;
                
            }
            
            party.setPartySize();
            for(int i = 0; i < party.getPartySize() -1; i++ )
            {
                if(randNumbers(1,2) == 1)
                {
                    party.setFullness(1,i);
                }
            }
        }
    }
}
void Action ::status(Stats& stats, Merchant& inventory, Player& party)
{
    /**
     * prints out all statments for game at end of turn
     */
    cout << "Status:" << endl;
    cout << "Rooms Cleared: " <<  stats.getRoomsCleared() << " Keys: "<< stats.getKeys() << " Anger Level: " << stats.getAnger() << endl;
    cout << "Inventory:" << endl;
    cout << "Gold: " << inventory.getGold() << endl;
    cout << "Ingrediants: " << inventory.getIngredients() << " kgs" << endl;
    cout << "Cookwear: " << "P: " << inventory.getCookware(0) << " F: " << inventory.getCookware(1) <<" C: " << inventory.getCookware(2) << endl;
    cout << "Weapons: " << "C: " << inventory.getWeapons(0) << " S: " << inventory.getWeapons(1)  << " R: " << inventory.getWeapons(2)  <<  " B: " << inventory.getWeapons(3) << " L: " << inventory.getWeapons(4) << endl; 
    cout << "Armour: " << inventory.getArmor() << endl; 
    cout << "Treasure:" << " R: " << inventory.getTreasure(0) << " N: " << inventory.getTreasure(1)<< " B: "<< inventory.getTreasure(2) <<" C: "<< inventory.getTreasure(3) << " G: " << inventory.getTreasure(3) << endl;
    cout << "Party:" << endl;
    party.setPartySize();
    //cout << party.getPartySize()<< endl;
    for(int i = 0; i < party.getPartySize() -1; i++)
    {
        cout << party.getName(i) << "    Fullness: " << party.getFullness(i) << endl;
    }
}
void Action ::misfortuneEvent( Merchant& inventory, Player& party, bool mis)
{  
    /**
     * caluclates prob for misfortune
     * prompts for events to happen
     * 
     */
    if( mis == true)
    {
        int probability = randNumbers(1,10);
        switch (probability)
        {
        case 1:
            inventory.loseFood();
            break;
        case 2:
            inventory.loseCookware();
            break;
        case 3:
            inventory.loseArmor(1);
            break;
        case 4:
            probability = randNumbers(1,2);
            if(probability == 1)
            {
                inventory.loseArmor(2);
            }
            else
            {
                inventory.loseWeapon();
            }
            break;
        case 5:
        case 6:
        case 7:
            party.setPartySize();
            probability = randNumbers(0,party.getPartySize()-1);
            party.setFullness(10, probability);
            cout << "Oh no! " << party.getName(probability) << " Got food poisioning and lost 10 health." << endl;
            break;
        case 8:
        case 9:
        case 10:
            party.setPartySize();
            probability = randNumbers(1,party.getPartySize()-1);
            cout << "Oh no! " << party.getName(probability) << " Got stuck in the room." << endl;
            party.loseMember(probability);
            //cout << "locked in room" << endl;
            break;
    }

}

}
int Action:: getExploredSpaces()
{
    return exploredSpaces;
}
int Action::getTurns()
{
    return turns;
}
int Action::getMonstersDef()
{
    return monstersDef;
}
void Action::setExploredSpaces()
{
    exploredSpaces +=1;
}
void Action::setTurns()
{
    turns +=1;
}
void Action::setMonstersDef()
{
    monstersDef +=1;
}
void Action :: BSP(Stats& stats, Player& party, Map& map)
{
    /**
     * rock paper sissers type game
     * randomizes and askes for input to compare
     * 
     */
    int choice = 0;
    int rand = randNumbers(1,3);
    int tries = 0;
    cout << "You will be playing a game of Boulder Parchement Shears" << endl;
    cout << "Boulder beats Shears" << endl;
    cout << "Parchment beats Boulder" << endl;
    cout << "Shears beat Parchment" << endl;

    while(choice != '1' ||choice != '2'|| choice != '3' )
    {
        while(tries < 3)
        {  
            cout << "Chose one:" << endl;
            cout << "1. Boulder" << endl;
            cout << "2. Parchment" << endl;
            cout << "3. Shears" << endl;
            cin >> choice;
            if(choice == 1)
            {
                if(rand == 1)
                {   cout << "You tie!" << endl;
                    tries++;
                }
                else if(rand == 2)
                {
                    cout << "You lose." << endl;
                    tries++;
                }
                else if (rand == 3)
                {
                    cout << "You win!" << endl;
                    stats.setRoomsCleared();
                    return;
                }
            }
            else if(choice == 2)
            {
                if(rand == 1)
                {
                    cout << "You win!" << endl;
                    stats.setRoomsCleared();
                    return;
                }
                else if(rand == 2)
                {   
                    cout << "You tie!" << endl;
                    tries++;
                    
                }
                else if (rand == 3)
                {
                    cout << "You lose." << endl;
                    tries++;
                }
            }
            else if (choice == 3)
            {
                if(rand == 1)
                {
                    cout << "You lose." << endl;
                    tries++;
                }
                else if(rand == 2)
                {
                    cout << "You win!" << endl;
                    stats.setRoomsCleared();
                    return;
                }
                else if (rand == 3)
                {
                    cout << "You tie!" << endl;
                    tries++;
                }
            }
            else
            {
                cout << "Invalid input." << endl;
            }

        } 
        if(tries == 3)
        {
            party.setPartySize();
            int probability = randNumbers(1,party.getPartySize()-1);
            cout << "Oh no! " << party.getName(probability) << " Got stuck in the room." << endl;
            party.loseMember(probability);
        } 
    }

}
double Action :: AttackVal(Merchant& inventory, Player& party, int rate)
{  
    /**
     * @brief 
     * use formula thats given
     * calculate value
     */
    int weaponTot=0;
    int inc =0;
    int w =0;
    for(int i =0; i < 5; i++)
    {
        weaponTot+= inventory.getWeapons(i); 
        w += inventory.getWeapons(i);
        if(inventory.getWeapons(2) >= 1)
        {
            inc = inventory.getWeapons(2);
            w += inc;
        }
        else if(inventory.getWeapons(3) >= 1)
        {
            inc = inventory.getWeapons(2) * 2;
            w += inc;
        }
        else if(inventory.getWeapons(4) >= 1)
        {
            inc = inventory.getWeapons(2) * 3;
            w += inc;
        }

    }
    int r1 = randNumbers(1,6);
    int r2 = randNumbers(1,6);
    int d = 0;
    int a = inventory.getArmor();
    party.setPartySize();
    if(weaponTot >= party.getPartySize())
    {
        d = 4;
    }
    int c = rate;
    if(a == 0)
    {
        return 0;
    }
    attack = (r1* w + d) - ((r2 *c)/a);
    return attack;
    
}