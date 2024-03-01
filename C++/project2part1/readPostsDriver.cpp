// CSCI 1300 Fall 2022
// Author: Julia Kirk
// Recitation: 105 – Raegan Rychecky
// Project 2- Problem # 2

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
int readPosts(string file_name, Post post[], int num_posts_stored, int posts_arr_size)
{
    /**
     * set vars
     * check if opens
     * read through file
     * chekc spilt = 4
     * fill object
     */
    Post new_post;

    ifstream file (file_name);
    string line = "";
    string body = "";
    string user= "";
    string date ="";
    int likes= 0;
    int count = num_posts_stored;
    int arrSize = 4;
    string temp[4];
    if(num_posts_stored == posts_arr_size)
    {
        count = -2;
    }
    else if (file.fail()) // check if file opens if not return 1
    {
        count = -1;
    }
   
    else
    {
        while(getline(file,line))// read through whole text file line by line
        {
            
          if (split(line, ',', temp, arrSize) == 4)
            {
                body = temp[0];
                //cout << body << endl;
                user = temp[1];
                //cout << user << endl;
                date = temp[3];
                //cout << date << endl;
                likes = stoi(temp[2]);
                //cout << likes << endl;
                if (count < posts_arr_size)
                {
                    new_post = Post(body,user,likes, date);
                    post[count] = new_post;
                    count++; 
                } 
            }     
        }
    }
    
    return count;// return count
}
int main()
{
    Post posts[10]; 
    int value =readPosts("posts1.txt", posts, 0, 10);
    // Code to print the values 
    cout << value << endl; // expected 3
    cout << posts[0].getPostAuthor() << endl; 
    cout << posts[1].getPostAuthor() << endl; 
    cout << posts[2].getPostAuthor() << endl; 
            
    // Expected Output 
    //user1
    //user2
    //user3
    Post posts1[2]; 
    Post my_post_1 = Post("new post","Xuefei", 10, "10/02/22");
    posts[0] = my_post_1;
    Post my_post_2 = Post("Hello!","Morgan", 9, "10/04/22");
    posts[1] = my_post_2;
    value = readPosts("posts_test2.txt",posts1,2,2);
    cout << value << endl;
    // expected -2
    cout << posts[0].getPostAuthor() << endl; 
    cout << posts[1].getPostAuthor() << endl;
    //expected 
    //Xuefei
    //Morgan
    value = readPosts("posts_test.txt", posts1 ,1,2); // expected -1
    cout << value << endl;
   

}