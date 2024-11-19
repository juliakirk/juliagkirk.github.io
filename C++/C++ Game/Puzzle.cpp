#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "Puzzle.h"

using namespace std;

Puzzle :: Puzzle()
{
    riddleSize =0;
    vector<riddles>riddler;
}
void Puzzle ::setPuzzle(string riddle, string answer) // fills struct and adds to array
{
    riddles member;
    member.riddle = riddle;
    member.answer = answer;
    riddler.push_back(member);
}
string Puzzle ::getRiddle(int i)
{
    return riddler[i].riddle;
}
string Puzzle ::getAnswer(int i)
{
    return riddler[i].answer;
}
void Puzzle ::readLine() // reads file and sets structs
{
    ifstream file;
    file.open("riddles.txt");
    string line;
    if(file.fail())
    {
        cout << "fail" << endl;
    }
    else
    {
        while (getline(file, line))
        {
            string arr[2];
            string rid;
            string ans;
            char seperator = '~';
            int pos = 0;
            int substr_start=0;

            int lineLength = line.length();

            if (lineLength != 0) // validate length exists
            {
                while(pos < lineLength)
                {
                    if (line[pos] == seperator) // check for seporator
                    {
                        arr[0]=line.substr(substr_start,pos-substr_start); // when found increse # found
                        rid = arr[0];
                        substr_start=pos+1; // update position
                        arr[1]= line.substr(substr_start);
                        ans = arr[1];
                        setPuzzle(rid, ans);
                        setSize();
                    }  
                    pos++;
                }
                
            } 
        }
    }  
}
void Puzzle ::setSize()
{
    riddleSize = riddler.size();
}
int Puzzle :: getSize()
{
    return riddleSize;
}