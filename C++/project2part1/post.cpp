// CSCI 1300 Fall 2022
// Author: Julia Kirk
// Recitation: 105 – Raegan Rychecky
// Project 2- Problem # 1

#include <iostream>
#include "post.h"

using namespace std;

Post:: Post() // default constructor
{
    body_ = "";
    post_author_ = "";
    num_likes_ = 0;
    date_ = "";
}

Post :: Post(string body, string post_author,int num_likes, string date) // parameterized constroctor
{
    body_ = body;
    post_author_ = post_author;
    date_ = date;
    num_likes_ = num_likes;
}

//Setter functions

void Post:: setPostBody(string body)
{
    body_= body;
}
void Post:: setPostAuthor(string post_author)
{
    post_author_= post_author;
}
void Post:: setPostDate(string date)
{
    date_= date;
}
void Post:: setPostLikes(int likes)
{
   if(likes >= 0) // checks likes is greater than 0 before initilizing
   {
    num_likes_ = likes;
   } 
}
//getter functions

string Post:: getPostBody()
{
    return body_;
}
string Post:: getPostAuthor() 
{
    return post_author_;
}
string Post:: getPostDate()
{
    return date_;
}
int Post:: getPostLikes()
{

    return num_likes_;  
    
}



