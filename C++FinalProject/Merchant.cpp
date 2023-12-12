 // CSCI 1300 Fall 2022
// Author: Julia Kirk
// Recitation: 105 – Raegan Rychecky
// Project 3
 
#include <iostream>
#include "Merchant.h"
#include "Stats.h"
 
using namespace std;
 
/**
 * @brief 
 * 
 * functions for shopping using materials and selling
 * 
 */
Merchant :: Merchant()
{
   gold = 100;
   ingredient = 0;
   armor = 0;
 
   for(int i =0; i < 5; i++)
   {
      weapons[i] =0;
      treasures[i] =0;
   }
   for(int i =0; i < 3; i++)
   {
       cookware[i]= 0;
   }
 
} 

bool Merchant :: setGold(int price)
{ 
   /**
    * when item is purchased subtract price from total
    *  check to make sure money is positive
    */
   if(gold - price >= 0)
   {
       gold = gold - price;
       cout << "Purchase completed." << endl;
       return true;
   }
   else
   {
       cout << "Not enough gold to complete the transaction." << endl;
       return false;
   }
 }
void Merchant :: buyIngredients()
{
    /**
    * show message with prices and options
    * prompt user to pick which option to buy
    * confirm choice
    * subtract from gold totals
    * loop till done with ingredient purchase
    */
   int price;
   char choice;
   int ingredientAmount;
   cout << "How many kg of ingredients do you need ["<< priceInc << " Gold/kg]? (enter a positive integer of 5, or 0 to cancel" << endl;
   cin >> ingredientAmount;
   while (ingredientAmount % 5 != 0)
   {
       cout << "That is not a valid input, please enter a positive integer of 5, or 0 to exit)" << endl;
       cin >> ingredientAmount;
   }
   cout << "You would like to purchase " << ingredientAmount << " kgs of ingredients is that correct? (y/n)" << endl;
   cin >> choice;
   if(choice == 'y'|| choice == 'Y')
   {    
        price = ingredientAmount * priceInc;
       if(setGold(price)== true)
       {
           ingredient += ingredientAmount;
       }
      
   }
   else
   {
       cout << "Purchase canceled" << endl;
   }
}
void Merchant :: buyCookware()
{
   /**
    * show message with price and options
    * prompt user to make choice
    * confirm choice
    * update array with ceramic = 0, frying =1 & cauldron =2
    * prompt if done or want to buy more
    */
   int type;
   char choice;
   int price;
   int amount;
 
   cout << "I have several types of cookware, which one would you like?" << endl;
   cout << "Each type has a different chance of breaking when used." << endl;
   cout << "Chose one of the following:" << endl;
   cout << "1. Ceramic pot 25% ("<< 2 * priceInc << " gold)" << endl;
   cout << "2. Frying pan 10% ("<< 10 * priceInc << " gold)" << endl;
   cout << "3. Cauldron 2% ("<< 20 * priceInc << " gold)" << endl;
   cin >> type;
   cout << "How many would you like?" << endl;
   cin >> amount;
 
   if(amount > 0)
   {
       if(type == 1)
       {
           price = amount * 2 * priceInc;
           cout << "You would like to purchase " << amount << " ceramic pots, is that correct? (y/n)" << endl;
           cin >> choice;
           if(choice == 'y'|| choice == 'Y')
           {
               if(setGold(price)== true)
               {
                   cookware[0] += amount;
               }
           }
           else
           {
               cout << "Purchase canceled" << endl;
           }
       }
       else if(type == 2)
       {
           price = amount * 10 * priceInc;
           cout << "You would like to purchase " << amount << " Frying pans, is that correct? (y/n)" << endl;
           cin >> choice;
           if(choice == 'y'|| choice == 'Y')
           {
               if(setGold(price)== true)
               {
                   cookware[1] += amount;
               }
           }
           else{
               cout << "Purchase canceled" << endl;
           }
       }
       else if(type == 3)
       {
           price = amount * 20 * priceInc;
           cout << "You would like to purchase " << amount << " cauldrons, is that correct? (y/n)" << endl;
           cin >> choice;
           if(choice == 'y'|| choice == 'Y')
           {
               if(setGold(price)== true)
               {
                   cookware[2] += amount;
               }
           }
       }
       else
       {
           cout << "Purchase canceled" << endl;
       }
   } 
}
void Merchant :: buyArmor()
{    /**
    * show message with price and options
    * prompt user to make a choice
    * confirm choice
    * update armor & gold totals
    * prompt if done with category
    */
    char choice;
    int armourAmount;
    int price;
    price = 5 * priceInc;
 
   cout << "One set of armor costs " << price << " gold. It is recommended to equip your team with 1 set per person to provide maximum protection" << endl;
   cout << "How many sets of armor would you like to purchase?" << endl;
   cin >> armourAmount;
 
   cout << "You would like to purchase " << armourAmount << " sets of Armour is that correct? (y/n)" << endl;
   cin >> choice;
 
   if(choice == 'y')
   {
       price = armourAmount * 5;
       if(setGold(price)== true)
       {
           armor += armourAmount;
       }
   }
   else
   {
       cout << "Purchase canceled" << endl;
   }
  
}
void Merchant :: buyWeapons()
{
   int price;
   int amount;
   int type;
   char choice;
 
   cout << "I have several weapons to choose from, which would you like?" << endl;
   cout << "Some weapons have a special combat bonus marked by a (+x)." << endl;
   cout << "" << endl;
   cout << "Chose one of the following:" << endl;
   cout << "1. Stone Club (" << 2 * priceInc << " gold)" << endl;
   cout << "2. Iron Spear (" << 2 * priceInc << " gold)" << endl;
   cout << "3. (+1) Mythril Rapier ("<< 5 * priceInc << " gold)" << endl;
   cout << "4. (+2) Flaming Battle Axe ("<< 15 * priceInc << " gold)" << endl;
   cout << "5. (+3) Vorpal Longsword ("<< 50 * priceInc << " gold)" << endl;
   cout << "6. Cancel" << endl;
   cin >> type;
   cout << "How many would you like?" << endl;
   cin >> amount;
  if(type == 1)
  {
       price = 2 * amount * priceInc;
       cout << "You wish to purchase " << amount << " Stone clubs?(y/n)" << endl;
       cin >> choice;
       if(choice == 'y' || choice == 'Y')
       {
           if(setGold(price)== true)
           {
               weapons[0] += amount;
           }
       }
       else
       {
           cout << "Purchase canceled" << endl;
       }
  }
  else if(type ==2)
  {
       price = 2 * amount * priceInc;
       cout << "You wish to purchase " << amount << " Iron spears?(y/n)" << endl;
       cin >> choice;
       if(choice == 'y' || choice == 'Y')
       {
           if(setGold(price)== true)
           {
               weapons[1] += amount;
           }
       }
       else
       {
           cout << "Purchase canceled" << endl;
       }
   }
   else if(type ==3)
   {
       price = 5 * amount* priceInc;
       cout << "You wish to purchase " << amount << " Mythril Rapier? (y/n)" << endl;
       cin >> choice;
       if(choice == 'y' || choice == 'Y')
       {
           if(setGold(price)== true)
           {
               weapons[2] += amount;
           }
       }
       else
       {
           cout << "Purchase canceled" << endl;
       }
      
  }
   else if(type ==4)
  {
   {
       price = 15 * amount * priceInc;
       cout << "You wish to purchase " << amount << " Flaming Battle Axe? (y/n)" << endl;
       cin >> choice;
       if(choice == 'y' || choice == 'Y')
       {
           if(setGold(price)== true)
           {
               weapons[3] += amount;
           }
       }
       else
       {
           cout << "Purchase canceled" << endl;
       }
      
   }
  }
   else if(type ==5)
    {
        price = 50 * amount * priceInc;
        cout << "You wish to purchase " << amount << " Vorpal Longsword? (y/n)" << endl;
        cin >> choice;
        if(choice == 'y' || choice == 'Y')
        {
            if(setGold(price)== true)
            {
                weapons[4] += amount;
            }
        }
        else
        {
            cout << "Purchase canceled" << endl;
        }
    }
    else
    {
    cout << "Purchase canceled" << endl;
    }
}
void Merchant :: sellTreasure()
{
 
   /**
    * show message with price and options
    * prompt to make a choice
    * confirm choice
    * update array with value
    * update gold amount
    * prompt to see if user is done with category
    */
   int choice;
   char confirm;
   int sell;
   int price;
 
   cout << "You can sell the treasures you have found for gold." << endl;
   cout << "1. Silver ring (10 gold)" << endl;
   cout << "2. Ruby necklace (20 gold)" << endl;
   cout << "3. Emerald bracelet (30 gold)" << endl;
   cout << "4. Diamond circlet (40 gold)" << endl;
   cout << "5. Gem-encrusted goblet (50 gold)" << endl;
 
   cout << "Please make a selection:" << endl;
   cin >> choice;
   cout << "How many would you like to sell?" << endl;
   cin >> sell;
 
   switch (choice)
   {
   case 1:
       cout << "Would you like to sell " << sell << " Silver rings? (y/n)" << endl;
       cin >> confirm;
 
       if(confirm == 'y')
       {
           if(weapons[0] <= sell)
           {
               cout << "Sale could not be completed, Insufficient inventory." << endl;
           }
           else
           {
               price = sell * 10;
               weapons[0]-= sell;
               gold += price;
               cout << "Sale completed " << price << " gold has been added to your inventory." << endl;
           }
       }
       else
       {
           cout << "Transaction voided" << endl;
       }
      
       break;
   case 2:
       cout << "Would you like to sell " << sell << " Ruby Necklaces? (y/n)" << endl;
       cin >> confirm;
 
       if(confirm == 'y')
       {
 
           if(weapons[1] <= sell)
           {
               cout <<"Sale could not be completed, Insufficient inventory." << endl;
           }
           else
           {
               price = sell * 20;
               weapons[1]-= sell;
               gold += price;
               cout << "Sale completed " << price << " gold has been added to your inventory." << endl;
           }
       }
       else
       {
           cout<< "Transaction voided" << endl;
       }
       break;
 
   case 3:
       cout << "Would you like to sell " << sell << " Emerald bracelets? (y/n)" << endl;
       cin >> confirm;
 
       if(confirm == 'y')
       {
 
           if(weapons[2] <= sell)
           {
               cout <<"Sale could not be completed, Insufficient inventory." << endl;
           }
           else
           {
               price = sell * 30;
               weapons[2]-= sell;
               gold += price;
               cout << "Sale completed " << price << " gold has been added to your inventory." << endl;
           }
       }
       else
       {
           cout << "Transaction voided" << endl;
       }
       break;
   case 4:
       cout << "Would you like to sell " << sell << " Diamond circlets? (y/n)" << endl;
       cin >> confirm;
 
       if(confirm == 'y')
       {
 
           if(weapons[3] <= sell)
           {
               cout <<"Sale could not be completed, Insufficient inventory." << endl;
           }
           else
           {
               price = sell * 40;
               weapons[3]-= sell;
               gold += price;
               cout << "Sale completed " << price << " gold has been added to your inventory." << endl;
           }
       }
       else{
           cout << "Transaction voided" << endl;
       }
       break;
   case 5:
       cout << "Would you like to sell " << sell << " Gem-encrusted goblets? (y/n)" << endl;
       cin >> confirm;
       if(confirm == 'y')
       {
           if(weapons[4] <= sell)
           {
               cout << "Sale could not be completed, Insufficient inventory." << endl;
           }
           else
           {
               price = sell * 50;
               weapons[4] -= sell;
               gold += price;
               cout << "Sale completed " << price << " gold has been added to your inventory." << endl;
           }
       }
       else
       {
           cout << "Transaction voided" << endl;
       }
     
       break;
  
   default:
       cout << "Invalid input" << endl;
       break;
   }
 
 
}
int Merchant ::getGold()
{
   return gold;
}
int Merchant :: getIngredients()
{
   return ingredient;
}
int Merchant :: getCookware(int place)
{
   return cookware[place];
}
int Merchant ::getWeapons(int place)
{
   return weapons[place];
}
int Merchant ::getArmor()
{
   return armor;
}
int Merchant :: getTreasure(int place)
{
   return treasures[place];
}
void Merchant:: shop(Stats room)
{
    int rooms = room.getRoomsCleared();
    setPrice(rooms);
    cout << "Between the 5 of you, you will have 100 gold pieces" << endl;
    cout << "You will need to spend some of your money on the following items:" << endl;
    cout << endl;
    cout << "INGREDIENTS: To make food, you have to cook raw ingredients" << endl;
    cout << "COOKWEAR: If you want to cook you will need cookwear to do so" << endl;
    cout << "WEAPONS: You will want at least one weapon per party member to fend off monsters" << endl;
    cout << "ARMOUR: Armour increses the chances of surviving a monster Attack" << endl;
    cout << endl;
    cout << "You can spend all your money here or you can save some to spend along your journey. "<< endl;
    cout << "Be warned that some of the merchants in the dungeon are shady characters and may not always give you a fair deal..." << endl;
    
    int choice;
    
    do
    {
        cout<< "Inventory:" << endl;
        cout << "Gold: " << getGold() << endl;
        cout << "Ingrediants: " << getIngredients() << " kgs" << endl;
        cout << "Cookwear: " << "P: " << getCookware(0) << " F: " << getCookware(1) <<" C: " << getCookware(2) << endl;
        cout << "Weapons: " << "C: " << getWeapons(0) << " S: " << getWeapons(1)  << " R: " << getWeapons(2)  <<  " B: " << getWeapons(3) << " L: " << getWeapons(4) << endl; 
        cout << "Armour: " << getArmor() << endl; 
        cout << "Treasure:" << " R: " << getTreasure(0) << " N: " << getTreasure(1)<< " B: "<<getTreasure(2) <<" C: "<< getTreasure(3) << " G: " << getTreasure(3) << endl;
        
        cout << "Chose from one of the following" << endl;
        cout << "1. Ingredents" << endl;
        cout << "2. Cookwear" << endl;
        cout << "3. Weapons" << endl;
        cout << "4. Armor " << endl;
        cout << "5. Sell Treasure" << endl;
        cout << "6. Enter the Dungeon" << endl;

        cin >> choice;
        switch (choice)
        {
        case 1:
            buyIngredients();
            break;
        case 2:
            buyCookware();
            break;
        case 3:
            buyWeapons();
            break;
        case 4:
            buyArmor();
            break;
        case 5:
            sellTreasure();
            break;
        case 6:
            cout << "Are you sure you're finished? There will not be another chance to purchase from me (y/n)." << endl;
            char choice;
            cin >> choice;
            if(choice == 'y')
            {
                cout << "Good luck out there!" << endl;
            }
            else
            {
                shop(room);
            }
            break;
        
        default:
            cout << "Please enter a valid input" << endl;
            break;
        }
    } while(choice != 6);
    
}

void Merchant::loseFood()
{
    cout << "lose food" << endl;
    if(ingredient <= 10)
    {
        cout << "Oh no! Your group was robbed and you lost all your food!" << endl;
        ingredient = 0;
        cout << ingredient << endl;
    }
    else
    {
        cout << "Oh no! your group was robbed you lost 10kg of food!" << endl;
        ingredient -= 10;
        cout << ingredient << endl;
    }
}
void Merchant::loseCookware()
{
    //cout << "lose cookware" << endl;
    int max = 2;
    int min = 0;
    prob = ((rand() % (max - min + 1)) + min);
    switch (prob)
    {
    case 0:
        if(cookware[0]>= 1)
        {
            cout << "Oh no! Your group was robbed you lost 1 Ceramic Pot" << endl;
            cookware[0] -= 1; 
            cout << cookware[0] << endl;
        }
        break;
    case 1:
        if(cookware[1]>= 1)
        {
            cout << "Oh no! Your group was robbed you lost 1 Frying Pan" << endl;
            cookware[1] -= 1;
            cout << cookware[1] << endl;
        }
        break;
    case 2:
        if(cookware[2]>=1)
        {
            cout << "Oh no! Your group was robbed you lost 1 Cauldron" << endl;
            cookware[2] -= 1; 
            cout << cookware[2] << endl;
        }
        break;
    
    default:
        break;
    }
}
void Merchant:: loseArmor(int i)
{
    cout << "lose armor" << endl;
    if(i == 1)
    {
        if(armor >= 1)
        {
           cout << "Oh no! Your group was robbed you lost 1 Armor." << endl; 
           armor -= 1;
           cout << armor << endl;
        }  
    }
    else
    {
        if(armor >= 1)
        {
            cout << "Oh no! 1 Armor broke." << endl;
            armor -= 1;
            cout << armor << endl;
        }
    }
    
}
void Merchant::loseWeapon()
{
    cout << "lose weapon" << endl;
    int max = 4;
    int min = 0;
    prob = ((rand() % (max - min + 1)) + min);
    switch (prob)
    {
        case 0:
            if(weapons[0] >= 1)
            {
                cout << "Oh no! Your club broke" << endl;
                weapons[0] -= 1;
                cout << weapons[0] << endl;
            }
            break;
        case 1:
            if(weapons[1] >= 1)
            {
                cout << "Oh no! Your Spear broke" << endl;
                weapons[1] -= 1;
                cout << weapons[1] << endl;
            }
            break;
        case 2:
            if(weapons[2] >= 1)
            {
                cout << "Oh no! Your +1 Rapier broke" << endl;
                weapons[2] -= 1;
                cout << weapons[2] << endl;
                
            }
            break;
        case 3:
            if(weapons[3] >= 1)
            {
                cout << "Oh no! Your +2 Battle-axe broke" << endl;
                weapons[3] -= 1;
                cout << weapons[3] << endl;
            }
            break;
        case 4:
            if(weapons[4] >= 1)
            {
                cout << "Oh no! Your +3 Longsword broke" << endl;
                weapons[4] -= 1;
                cout << weapons[4] << endl;
            }
            break;
    }

}
void Merchant :: setPrice(int rooms)
{
    if(rooms == 0)
    {
        priceInc = 1;
    }
    else if(rooms ==1)
    {
        priceInc = 1.25;
    }
    else if(rooms ==2)
    {
        priceInc = 1.5;
    }
    else if(rooms ==3)
    {
        priceInc = 1.75;
    }
    else if(rooms ==4)
    {
        priceInc = 2;
    }
    else if(rooms == 5)
    {
        priceInc = 2.25;
    }
}
void Merchant ::setTreasure(int place)
{
    treasures[place]+= 1;
}
void Merchant :: cookwearBreak(int place, int amount)
{
    cookware[place] -=1;
    ingredient -= amount;
}
void Merchant :: useFood(int amount)
{
    ingredient -= amount;
}