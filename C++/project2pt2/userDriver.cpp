// CSCI 1300 Fall 2022
// Author: Julia Kirk
// Recitation: 105 – Raegan Rychecky
// Project 2 

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "User.h"
using namespace std;

int main()
{
    User u1 = User();
    assert(u1.getUsername() == "");
    assert(u1.getNumPosts() == 0);
    assert(u1.getLikesAt(1)== -1);
    assert(u1.getLikesAt(49)== -1);

    int testLikes[] = {7,1,8,-1,10,5,5,5,-1,8};
    User u2 = User("roboticscu", testLikes, 10);
    assert(u2.getUsername() == "roboticscu");
    assert(u2.getNumPosts() == 10);
    assert(u2.getLikesAt(1)== 1);
    assert(u2.getLikesAt(5)== 5);
    assert(u2.getLikesAt(50)== -2);
    assert(u2.getSize() == 50);

}
