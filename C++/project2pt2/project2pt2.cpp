// CSCI 1300 Fall 2022
// Author: Julia Kirk
// Recitation: 105 – Raegan Rychecky
// Project 2 

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "Post.h"
#include "User.h"
#include "Buffchat.h"
using namespace std;

int main()
{
    // initlize varriables
    Buffchat app;
    string filename = "";
    string choice = "";
    string year = "";
    string postAuth = "";
    string userName = "";
    string postDate = "";
    string postBody = "";
    string postAuthor = "";
    string tag = "";
    int popular = 0;
    int getLikes = 0;
    int num_posts = 0;
    int num_users = 0;
    int uniqueLikes = 0;

 do // loop till 10 is entered
 {
    cout << "======Main Menu===== "<< endl;
    cout << "1. Read posts " << endl;
    cout << "2. Print Posts By Year" << endl;
    cout <<"3. Read Likes"<< endl;
    cout << "4. Get Likes" << endl;
    cout << "5. Find users with matching tag" << endl;
    cout << "6. Add a new post"<< endl;
    cout << "7. Print popular posts for a year"<< endl;
    cout <<"8. Find least active user"<< endl;
    cout <<"9. Find unique likes for a post author"<< endl;
    cout << "10. Quit"<< endl;
    cin >> choice;

    if(choice == "1") // if 1 is entered
    {
        // prompt user for parameters
        cout << "Enter a post file name:" << endl;
        cin >> filename;
        // plug into function
        num_posts =  app.readPosts(filename);
        // compare output to values and print out corelated statement
        if(num_posts== -1)
        {
        cout << "File failed to open. No posts saved to the database." << endl; 
        }
        else if(num_posts== -2)
        {
        cout << "Database is already full. No posts were added." << endl; 
        }
        else if(num_posts == 50)
        {
        cout << "Database is full. Some posts may have not been added." << endl; 
        }
        else
        {
        cout << "Total posts in the database: " << num_posts << endl;
        }
    }

    else if(choice == "2") // if 2 is entered
    {
        // prompt for year
        cout << "Enter the year(YY):" << endl;
        cin >> year;
        // plug into postbyyear function
        app.printPostsByYear(year);
    }
    else if(choice == "3") // if 3 is entered
    {
        // prompt for fn inputs
        cout << "Enter a user file name:" << endl;
        cin >> filename;
        // plug into function and set as num_users_
        num_users = app.readLikes(filename);
        // compare output to values then print out staments
        if(num_users== -1)
        {
        cout << "File failed to open. No users saved to the database." << endl; 
        }
        else if(num_users == -2)
        {
        cout << "Database is already full. No users were added." << endl; 
        }
        else if(num_users == 50)
        {
        cout << "Database is full. Some users may have not been added." << endl; 
        }
        else
        {
        cout << "Total users in the database: " << num_users << endl;
        }

    }
    else if(choice == "4") // if 4 is entered
    {
        // prompt for parameters
        cout << "Enter a post author:" << endl;
        cin >> postAuth;
        cout << "Enter a user name:" << endl;
        cin >> userName;
        // plug into function
        getLikes = app.getLikes(postAuth, userName);
        // compare output to values
        if(getLikes == 0 )
        {
            cout << userName << " has not liked the post posted by " << postAuth << endl;
        }
        else if(getLikes== -1)
        {
            cout << userName << " has not viewed the post posted by " << postAuth << endl;
        }
        else if (getLikes == -2)
        {
            cout << "Database is empty." << endl;
        }
        else if(getLikes == -3)
        {
            cout << userName << " or " << postAuth << " does not exist." << endl;
        }
        else
        {
            cout << userName << " liked the post posted by " << postAuth << " "<< getLikes << " times" << endl;
        }
    }
    else if(choice == "5") // if 5 is entered
    {
        // prompt for tage
        cout << "Enter a tag:" << endl;
        cin >> tag;
        // call function using tag
        app.findTagUser(tag);
    }
    else if(choice == "6") // if 6 is entered
    {
        // prompt for function call inputs
        cout << "Enter a post body:" << endl;
        cin >> postBody;
        cout << "Enter a post author:" << endl;
        cin >> postAuthor;
        cout << "Enter a date(mm/dd/yy):" << endl;
        cin >> postDate;
        // call function
        bool add = app.addPost(postBody,postAuthor,postDate);
        // compare output and print out what is prompted
        if(add == true)
        {
        cout << postAuthor << "'s post added successfully" << endl;
        }
        if(add == false)
        {
        cout << "Database is already full. "<< postAuthor <<"'s post was not added" << endl;
        }
    }
    else if(choice == "7") // if 7 is entered
    {
        // prompt for parameters
        cout << "Enter the number of posts:" << endl;
        cin >> popular;
        cout << "Enter the year(YY):" << endl;
        cin >> year;
        // call function
        app.printPopularPosts(popular,year);
    }
    else if(choice == "8") // if 8 is entered
    {
        // call function
        User u = app.findLeastActiveUser();
        if(u.getUsername() == "")
        {
        cout << "There are no users stored" << endl;
        }
        else
        {
        cout << u.getUsername() << " is the least active user" << endl;
        }
        
    }
    else if(choice == "9") // if 9 is entered
    {
        // prompt for values
        cout << "Enter a post author:" << endl;
        cin >> postAuthor;
        // call function
        uniqueLikes = app.countUniqueLikes(postAuthor);
        // compare outcome
        if(uniqueLikes == 0)
        {
        cout << "The posts posted by " << postAuthor << " have received 0 likes so far." << endl;
        }
        if(uniqueLikes == -1)
        {
        cout << "The posts posted by " << postAuthor << "have not been viewed by anyone." << endl;
        }
        if(uniqueLikes == -2)
        {
        cout << "Database is empty." << endl;
        }
        else
        {
        cout << "The posts posted by "<< postAuthor << " have been liked by " << uniqueLikes << " unique users." << endl;
        }

    }
    else if(choice == "10") // if 10 is entered print out then end loop
    {
        cout << "Good bye!" << endl;
    }
    else // if not any of the options print out it is invalid
    {
        cout << "Invalid input" << endl;
    }

 } while (choice != "10");
}
