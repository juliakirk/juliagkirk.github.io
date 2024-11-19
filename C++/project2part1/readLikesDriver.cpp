// CSCI 1300 Fall 2022
// Author: Julia Kirk
// Recitation: 105 – Raegan Rychecky
// Project 2- Problem # 5

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "user.h"

using namespace std;

int split (string input_string, char seperator, string arr[], int arr_size)
{
    int inputLength =input_string.length();

    if (inputLength == 0) // validate length exists
    {
        return 0;
    }

    if ( arr_size < 1) // validate its not negative
    {
        return 0;
    }
    int pos = 0;
    int found = 0;
    int substr_start=0; // initilize varriables
    
    while (pos < inputLength ) 
    {
        if (input_string[pos]== seperator) // check for seporator
        {
        
            if (found > arr_size) // if seporator is greater than array return 0;
                {
                return -1;
                } 

            arr[found++]=input_string.substr(substr_start,pos-substr_start); // when found increse # found
            substr_start=pos+1; // update position
        }
        pos++;
    }

    if (found >= arr_size) // check # found is less than array size
    {
        return -1;
    }   

    arr[found++]=input_string.substr(substr_start,input_string.length()); // update amount found to include last substring

    return found;
}


   
int readLikes(string file_name, User users[], int num_users_stored, int users_arr_size, int max_posts)
{ 
    /**
     * validate opens and is valid
     * go through line by line
     * fill array 
     * make new object and set
     */
    ifstream file;
    file.open(file_name);  
    int max = max_posts+= 1;
    string temp[max];
    string username;
    User object;
    string line;
    if (num_users_stored == users_arr_size)
        {
                return -2;
        }
    else if (file_name == "")
        {
            return -1;
        }

    else if (file.fail())
        {
            return -1;
        }
 

    
   
    else
    {
        while (getline(file, line))
            {  
                if (num_users_stored == users_arr_size)
                    {
                        return num_users_stored;
                    }
            
                else
                {
                    int num_posts = split(line, ',', temp, 51);

                    if(num_posts != 0)
                    {
                        username = temp[0];
                        // Set the user name for the current user
                        users[num_users_stored].setUsername(username);
                        
                        users[num_users_stored].setNumPosts(num_posts - 1);

                        for (int i = 1; i < num_posts; i++)
                        {
                            int num_likes_for_post = stoi(temp[i]);
                            users[num_users_stored].setLikesAt(i - 1, num_likes_for_post);
                        }
                        num_users_stored += 1;
                    }  
                    
                }
            }
  
  // cout << num_users_stored << endl;
  return num_users_stored;
}
}

int main()
{
    User users[10];
    int num_users_stored = 0; 
    int users_arr_size = 10; 
    int max_posts = 3;
    readLikes("users_10.txt", users, num_users_stored, users_arr_size, max_posts);
    cout << users[0].getLikesAt(0) << endl; 
    cout << users[0].getLikesAt(1) << endl; 
    cout << users[0].getLikesAt(2) << endl; 
    cout << users[1].getLikesAt(0) << endl; 
    cout << users[1].getLikesAt(1) << endl; 
    cout << users[1].getLikesAt(2) << endl; 

    User users[10];

    int max_posts = 50;
    int num_users_stored = 0;
    int users_arr_size = 10;

    readLikes("users_10.txt", users, num_users_stored, users_arr_size, max_posts);
    cout << "checking if we can call the function" << endl;

}