// CSCI 1300 Fall 2022
// Author: Julia Kirk
// Recitation: 105 – Raegan Rychecky
// Project 2- Problem # 4

#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

class User
{
public:
    User();
    User(string username, int likes[], int numPosts);

    // getters
    string getUsername();
    int getLikesAt(int post_id);
    int getNumPosts();
    int getSize();

    // setters
    void setUsername(string username);
    bool setLikesAt(int post_id, int num_likes);
    void setNumPosts(int posts);

private:
    static const int size_ = 50;
    string username_;
    int likes_[size_];
    int num_posts_;
};
#endif