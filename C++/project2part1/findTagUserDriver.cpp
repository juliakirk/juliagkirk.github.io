// CSCI 1300 Fall 2022
// Author: Julia Kirk
// Recitation: 105 – Raegan Rychecky
// Project 2- Problem # 7


#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "user.h"
#include "post.h"

using namespace std;

void findTagUser(string username_tag, User users[], int num_users_stored)
{
    
   /**
    * find number of times tag appears
    * if matches print out statment print
    * if contains print staitment 
    * loop through printing all that are found
    */

    int numFound = 0; // inilize num found
    for(int i = 0; i < num_users_stored; i++) // loop through num users stored
    {
        string username = users[i].getUsername();  // make username a string
        
        if (username.find(username_tag) != std::string::npos) // use find to find if found increse counter
        {
        numFound++;
        }
    }
    if(num_users_stored == 0) // if nothing is stored print out message
    {
        cout << "No users are stored in the database" << endl;
    }      
    else if(numFound == 0 && num_users_stored >= 0) // if none are found and num users exists
    {
        cout << "No matching user found" << endl;
    }

    else
    {
        cout << "Here are all the usernames that contain " << username_tag << endl; // print out statement
        for(int i= 0; i < num_users_stored; i++) 
       {
        string username = users[i].getUsername();
            if (username.find(username_tag) != std::string::npos) // loop through and print what is found
            {
                cout << username << endl;
            }
        
       }
    }     
}


int main()
{
    User user_array[5];
    findTagUser("ol",user_array,0);
    // expect no users stored

     User user_array1[5];
    int likes1[3] = {1, 0, -1};
    int likes2[3] = {4, 5, 0};
    user_array1[0] = User("foliwn22", likes1, 3);
    user_array1[1] = User("joh23k", likes2, 3);
    user_array1[2] = User("harry02", likes2, 3);
    user_array1[3] = User("luwkml1", likes2, 3);
    user_array1[4] = User("fwollow3", likes1, 3);
    findTagUser("ol", user_array1, 5);
    
    // expect
    //Here are all the usernames that contain ol
    // foliwn22
    // fwollow3
    findTagUser("hi", user_array1, 5);
    //expect no matching user found
}