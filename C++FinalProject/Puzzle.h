#ifndef PUZZLE_H
#define PUZZLE_H
#include <iostream>
#include <vector>

using namespace std;
/**
 * controls riddles in game
 * reads from files
 * 
 */
class Puzzle
{
    public:
    Puzzle();
    void setPuzzle(string riddle, string answer);
    string getRiddle(int i);
    string getAnswer(int i);
    void readLine();
    void setSize();
    int getSize();

    private:
    struct riddles
    {
        string riddle = "";
        string answer = "";
    };
    vector<riddles>riddler;
    int riddleSize;
};

#endif
