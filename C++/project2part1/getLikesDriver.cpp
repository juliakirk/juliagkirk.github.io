// CSCI 1300 Fall 2022
// Author: Julia Kirk
// Recitation: 105 – Raegan Rychecky
// Project 2- Problem # 6


#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "user.h"
#include "post.h"

using namespace std;

int getLikes(string post_author, Post posts[], int num_posts_stored,string username, User users[], int num_users_stored)
{
    /**
     * index at one
     * validate user stored size
     * check to see where author == athor and user = username
     * if indexes have not changed return -3
     * else return likes at user
     */
    int PostPos = -1;
    int UserPos = -1;

if(num_posts_stored <= 0 || num_users_stored <= 0) // check values are greater than zero
    {
        return -2;
    }
for(int i =0; i < num_posts_stored ; i++)
{
    if(posts[i].getPostAuthor() == post_author)
    {
        PostPos = i;
    }
}
for( int i = 0; i < num_users_stored; i++)
{
    if(users[i].getUsername() == username)
    {
        UserPos = i;
    }
}
if(PostPos == -1 || UserPos == -1)
{
    return -3;
}
else
{
    return users[UserPos].getLikesAt(PostPos);
}
}


int main()
{

    #include <iostream>
    #include "post.h"
    Post posts[3]; 
    Post my_post_1 = Post("Hello!","Xuefei", 10, "10/02/22");
    posts[0] = my_post_1;
    Post my_post_2 = Post("new post","Morgan", 9, "10/04/22");
    posts[1] = my_post_2;
    Post my_post_3 = Post("Hey!","Jot", 10, "10/05/22");
    posts[2] = my_post_3;
    
    User users[2];
    // // user 1
    int likes1[3] = {1, 3, 2};
    User u1 = User("bookworm43", likes1, 3);
    users[0] = u1; // insert first object at index 0
    // // user 2
    users[1].setUsername("roboticscu");
    users[1].setLikesAt(0,-1); 
    users[1].setLikesAt(1,2); 
    users[1].setLikesAt(2,4);

    cout << getLikes("Xuefei", posts, 3, "bookworm43", users, 2) << endl;
    // expect 1
    User user_array[] = {};
    cout << getLikes("Raegan", posts, 3, "bookworm43", user_array, 0) << endl;
    //expect -2
    cout << getLikes("Raegan", posts, 3, "bookworm43", users, 2)<< endl;
    // expect -3
    
    
    
}