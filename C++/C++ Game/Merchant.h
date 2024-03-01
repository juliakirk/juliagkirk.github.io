// CSCI 1300 Fall 2022
// Author: Julia Kirk
// Recitation: 105 – Raegan Rychecky
// Project 3
#ifndef MERCHANT_H
#define MERCHANT_H
#include <iostream>
#include "Stats.h"
#include "Merchant.h"
#include "Player.h"
 
using namespace std;
 
class Merchant
{
   public:
       Merchant();
       bool setGold(int price);
       void sellTreasure();
       void buyIngredients();
       void buyCookware();
       void buyWeapons();
       void buyArmor();
       int getGold();
       int getIngredients();
       int getCookware(int place);
       int getWeapons(int place);
       int getArmor();
       int getTreasure(int place);
       void setTreasure(int place);
       void shop(Stats stats);
       void loseFood();
       void loseCookware();
       void loseArmor(int i);
       void loseWeapon();
       void setPrice(int rooms);
       void cookwearBreak(int place, int amount);
       void useFood(int amount);
       
   private:
       int gold;
       int ingredient;
       int cookware[3];
       int weapons[5];
       int armor;
       int treasures[5];
       int prob;
       double priceInc;
 
};


#endif