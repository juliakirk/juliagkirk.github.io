// CSCI 1300 Fall 2022
// Author: Julia Kirk
// Recitation: 105 – Raegan Rychecky
// Project 2 

#ifndef BUFFCHAT_H
#define BUFFCHAT_H
#include <iostream>
using namespace std;
#include "Post.h"
#include "User.h"

class Buffchat
{
    private:
        const static int posts_size_ = 50;
        const static int users_size_= 50;
        Post posts_[posts_size_];
        User users_[users_size_];
        int num_posts_;
        int num_users_;

    public:

        Buffchat();
        
        int getPostSize();
        int getUserSize();
        int getNumPosts();
        int getNumUsers();
        int readPosts(string file_name);
        void printPostsByYear(string year);
        int readLikes(string file_name);
        int getLikes(string post_author, string username);
        void findTagUser(string username_tag);
        bool addPost(string post_body, string post_author, string date);
        void printPopularPosts(int count, string year);
        User findLeastActiveUser();
        int countUniqueLikes(string post_author);

};

#endif