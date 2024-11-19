// CSCI 1300 Fall 2022
// Author: Julia Kirk
// Recitation: 105 – Raegan Rychecky
// Project 2- Problem # 4

#include <iostream>
#include "user.h"

using namespace std;

int main()
{
    User u1 = User();
    cout << u1.getUsername() << endl;
    cout << u1.getNumPosts() << endl;
    for(int i = 0; i < u1.getSize(); i++)
    {
        cout << u1.getLikesAt(i) << endl;
    }
    // expect 0, -1, -1 , ... ,-1;
    int testLikes[] = {7,1,8,-1,10,5,5,5,-1,8};
    User u3 = User("roboticscu", testLikes, 10);

    cout << u3.getUsername() << endl;
    cout << u3.getNumPosts() << endl;
            
    // test values in likes_array at random indices
    cout << u3.getLikesAt(0) << endl;
    cout << u3.getLikesAt(10) << endl;
    cout << u3.getLikesAt(50) << endl;
    // Expected Output 
    // roboticscu
    // 10
    // 7
    // -1
    // -2 
    int testLikes1[] = {7,1,8,-1,10,5,5,3,5,-1,8};
    User u2 = User("rou", testLikes, 10);

    cout << u2.getUsername() << endl;
    cout << u2.getNumPosts() << endl;
            
    // test values in likes_array at random indices
    cout << u2.getLikesAt(0) << endl;
    cout << u2.getLikesAt(5) << endl;
    cout << u2.getLikesAt(10) << endl;
    // Expected Output 
    // rou
    // 10
    // 7
    // 5
    // -1 

               
}


