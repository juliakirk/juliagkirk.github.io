// CSCI 1300 Fall 2022
// Author: Julia Kirk
// Recitation: 105 – Raegan Rychecky
// Project 2 

#include <iostream>
#include "User.h"

using namespace std;

User::User()
{
  username_ = "";
  num_posts_ = 0;

  for (int i = 0; i < size_; i++)
  {
    likes_[i] = -1;
  }
}
User ::User(string username, int likes[], int num_posts)
{
  username_ = username;
  num_posts_ = num_posts;

  if (num_posts == size_)
  {
    for (int i = 0; i < size_; i++)
    {
      likes_[i] = likes[i];
    }
  }
  if (num_posts < size_)
  {
    for (int i = 0; i < num_posts; i++)
    {
      likes_[i] = likes[i];
    }
    for (int j = num_posts; j < size_; j++)
    {
      likes_[j] = -1;
    }
  }
}
string User::getUsername()
{
  return username_;
}
void User::setUsername(string username)
{
  username_ = username;
}
int User ::getLikesAt(int post_id)
{
  if (post_id >= size_ || post_id < 0)
  {
    return -2;
  }
  else
  {
    return likes_[post_id];
  }
}
bool User::setLikesAt(int post_id, int num_likes)
{

  if (post_id < num_posts_ && post_id >= 0 && num_likes >= -1 && num_likes <= 10)
  {
    likes_[post_id] = num_likes;
    return true;
  }
  else
  {
    return false;
  }
}
int User ::getNumPosts()
{
  return num_posts_;
}
void User ::setNumPosts(int posts)
{
  if (posts > 0 && posts <= size_)
  {
    num_posts_ = posts;
  }
}
int User::getSize()
{
  return size_;
}
