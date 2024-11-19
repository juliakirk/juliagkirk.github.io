#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "Monster.h"

using namespace std;

Monster:: Monster()
{
    vector<monst>fights;
    monstSize = 0;
}
void Monster :: setMonster(string name, int level) // sets structure vals
{
    monst member;
    member.name = name;
    member.rating = level;
    fights.push_back(member);

}
string Monster :: getName(int i)
{
    return fights[i].name;
}
int Monster ::getRating(int i)
{
    return fights[i].rating;
}
void Monster :: readMonsters() // reads from file and assigns values to struct
{
    ifstream file;
    file.open("monsters.txt");
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
            string name;
            int rating;
            char seperator = ',';
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
                        name = arr[0];
                        substr_start=pos+1; // update position
                        arr[1]= line.substr(substr_start);
                        rating = stoi(arr[1]);
                        setMonster(name,rating);
                        setSize();
                    }  
                    pos++;
                }
                
            } 
        }
    }  
}

void Monster:: setSize()
{
    monstSize = fights.size();
}
int Monster :: getSize()
{
    return monstSize;
}
