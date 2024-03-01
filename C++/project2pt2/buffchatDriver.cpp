// CSCI 1300 Fall 2022
// Author: Julia Kirk
// Recitation: 105 – Raegan Rychecky
// Project 2 

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "Post.h"
#include "User.h"
#include "Buffchat.h"
using namespace std;

int main()
{
  Buffchat myBuffchat;
  assert(myBuffchat.readPosts("posts.txt")== 50);
  myBuffchat.printPostsByYear("18");
  assert(myBuffchat.readLikes("users.txt")==50);
  assert(myBuffchat.getLikes("Julia", "michelleryan")==8);
  myBuffchat.findTagUser("ed");
  assert(myBuffchat.addPost("Snow Day!!!", "spiritedMues", "10/25/22")== false);
  myBuffchat.printPopularPosts(4, "20");
  User u = myBuffchat.findLeastActiveUser();
  assert(u.getUsername() == "michelleryan");
  assert(myBuffchat.countUniqueLikes("bookworm43") == 150);

  Buffchat myBuffchat1;
  assert(myBuffchat1.readPosts("posts1.txt")== 5);
  myBuffchat1.printPostsByYear("18");
  assert(myBuffchat1.readLikes("users1.txt")==5);
  assert(myBuffchat1.getLikes("stacy", "michelleryan")== -3);
  myBuffchat1.findTagUser("10");
  assert(myBuffchat1.addPost("Snow Day!!!", "elf", "12/25/22") == true);
  myBuffchat1.printPopularPosts(8, "10");
  User u1 = myBuffchat1.findLeastActiveUser();
  assert(u1.getUsername() == "pacifiedIcecream7");
  assert(myBuffchat1.countUniqueLikes("bookworm43") == -1);
}
