#ifndef STATS_H
#define STATS_H
/**
 * @brief 
 * controls statistics of game
 * 
 */
class Stats
{
    public:

    Stats();
    int getRoomsCleared();
    void setRoomsCleared();
    int getKeys();
    void setKeys();
    void useKey();
    int getAnger();
    void setAnger();
    

    private:
    int roomsCleared;
    int keys;
    int angerLevel;
};
#endif