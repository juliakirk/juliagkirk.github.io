// CSCI 1300 Fall 2022
// Author: Julia Kirk
// Recitation: 105 – Raegan Rychecky
// Project 2- Problem # 3

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "post.h"
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

void printPostsByYear(Post posts[], string year, int num_posts_stored)
{ 
    /**
     * check for matches
     * if no matches print out there are none
     * if empty print that
     * if match print out match year and all matches
     */
    bool yearFound = false; // set found to false
   
    for(int j=0; j < num_posts_stored; j++) // loop through num posts
        {
            string arrDate = posts[j].getPostDate(); // get post date from post arr
            string arrYear = arrDate.substr(6); // make substr from start of year

            if(arrYear == year) // if found update bool
            {
                yearFound = true;
            }
        }
    if(num_posts_stored <= 0) // if no posts return 
    {
        cout << "No posts are stored" << endl;
        return;
    }
   
   else if(yearFound == false) // if not found return
    {
        cout << "No posts stored for year " << year << endl;
    }
    else
    {
       cout << "Here is a list of posts for year " << year << endl; // print out year and statement
       for(int i= 0; i < num_posts_stored; i++) // loop through num of posts
       {
            string arrDate = posts[i].getPostDate();
            string arrYear = arrDate.substr(6);
    
            if(arrYear == year)// if year found cout;
            {
                cout <<  posts[i].getPostBody() << endl; 
            }
       }
    }
}

int main()
{
    Post p1 = Post("new post1","Lisa1", 10, "10/02/22");
    Post p2 = Post("new post2","Lisa2", 10, "10/02/22");
    Post p3 = Post("new post3","Lisa3", 10, "10/02/12");
    Post list_Posts[] = {p1, p2, p3};
    int number_Posts = 3;
    string year = "22";
    printPostsByYear(list_Posts, year, number_Posts);
    // Expected
    // Here is a list of posts for year 22
    // new post1
    // new post2
    Post list_of_posts[] = {};
    int number_of_posts = 0;
    string year1 = "20";
    printPostsByYear(list_of_posts, year1, number_of_posts);
    // expected no posts are stored
    Post p_1 = Post("new post1","Lisa1", 10, "10/02/22");
    Post p_2 = Post("new post2","Lisa2", 11, "10/02/22");
    Post list_of_posts1[] = {p_1, p_2};
    int number_of_posts1 = 2;
    string year2 = "12";
    printPostsByYear(list_of_posts1, year2, number_of_posts1);
    //expected no posts are stored for year 12
}