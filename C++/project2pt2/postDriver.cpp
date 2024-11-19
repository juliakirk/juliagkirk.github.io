// CSCI 1300 Fall 2022
// Author: Julia Kirk
// Recitation: 105 – Raegan Rychecky
// Project 2 

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "Post.h"
using namespace std;

int main()
{
    Post my_post_1 = Post(); // default constructor
    assert(my_post_1.getPostAuthor() == "");
    assert(my_post_1.getPostBody() == "");
    assert(my_post_1.getPostDate()== "");
    assert(my_post_1.getPostLikes() == 0);

    Post my_post_2 = Post("hi :)","Abby", 10, "10/02/22"); // parameterized constructor
    assert(my_post_2.getPostAuthor() == "Abby");
    assert(my_post_2.getPostBody() == "hi :)");
    assert(my_post_2.getPostDate() == "10/02/22");
    assert(my_post_2.getPostLikes() == 10);

    Post my_post_3 = Post("Today was a good day!","Julia", 3, "09/26/02"); // parameterized constructor
    assert(my_post_3.getPostAuthor() == "Julia");
    assert(my_post_3.getPostBody() == "Today was a good day!");
    assert(my_post_3.getPostDate() == "09/26/02");
    assert(my_post_3.getPostLikes() == 3);
    


            

}
