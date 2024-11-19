// CSCI 1300 Fall 2022
// Author: Julia Kirk
// Recitation: 105 – Raegan Rychecky
// Project 2

#ifndef POST_H
#define POST_H

#include <iostream>
using namespace std;

class Post
{
    public:
        Post();
        Post(string body_, string post_author_, int num_likes_ ,string date_);

        // getters
        string getPostBody();
        string getPostAuthor();
        int getPostLikes();
        string getPostDate();
        

        //setters
        void setPostBody(string post_body);
        void setPostAuthor(string author);
        void setPostLikes(int likes);
        void setPostDate(string post_date);
        void setPost(string post);
        

    private:
        string body_;
        string post_author_;
        int num_likes_;
        string date_;

};

#endif