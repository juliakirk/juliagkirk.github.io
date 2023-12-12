#include <iostream>
#include "Stats.h"

using namespace std;

Stats :: Stats() //default constructor
{
    roomsCleared = 0;
    keys = 0;
    angerLevel = 0;
}
int Stats:: getRoomsCleared()
{
    return roomsCleared;
}
void Stats:: setRoomsCleared() // increses rooms cleared
{
    roomsCleared+=1;
}
void Stats:: setKeys() // ads key
{
    keys+=1;
}
int Stats:: getKeys()
{
    return keys;
}
void Stats :: setAnger() // increses anger
{
    angerLevel+=1;
}
int Stats :: getAnger()
{
    return angerLevel;
}
void Stats :: useKey() // removes key
{
    keys -=1;
}