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

Buffchat :: Buffchat()
{
    //default constructor sets num_posts_ and num_users_ to zero 
   num_posts_ = 0;
   num_users_ = 0;
}

int split (string input_string, char seperator, string arr[], int arr_size) // split function to split string into array
{
    /**
     * take in parameters
     * validate string exists
     * if it exists go through string and when seporator is found split into several arrays
     * return number split into
     */
    int inputLength = input_string.length();

    if (inputLength == 0) // validate length exists
    {
        return 0;
    }

    if ( arr_size < 1) // validate its not negative
    {
        return 0;
    }
    int pos = 0;
    int found = 0;
    int substr_start=0; // initilize varriables
    
    while (pos < inputLength ) 
    {
        if (input_string[pos]== seperator) // check for seporator
        {
        
            if (found > arr_size) // if seporator is greater than array return 0;
                {
                return -1;
                } 

            arr[found++]=input_string.substr(substr_start,pos-substr_start); // when found increse # found
            substr_start=pos+1; // update position
        }
        pos++;
    }

    if (found >= arr_size) // check # found is less than array size
    {
        return -1;
    }   

    arr[found++]=input_string.substr(substr_start,input_string.length()); // update amount found to include last substring

    return found;
}
int Buffchat :: getPostSize()
{
    // returns post size
    return posts_size_;
}
int Buffchat :: getUserSize()
{
    // returns user size
    return users_size_;
}
int Buffchat :: getNumPosts()
{
    // returns number of posts in users array
    return num_posts_;
}
int Buffchat :: getNumUsers()
{
    // returns number of users in a users array
    return num_users_;
}
int Buffchat :: readPosts(string file_name)
{
    /**
     * create a new object
     * go through file line by line 
     * if spilt = 4 then fill object with array values
     */

    Post new_post;

    ifstream file (file_name);
    string line = "";
    string body = "";
    string user= "";
    string date ="";
    int likes = 0;
    int arrSize = 4;
    string temp[4];
    if(num_posts_ == posts_size_)
    {
        return -2;
    }
    else if (file.fail()) // check if file opens if not return 1
    {
        return -1;
    }
   
    else
    {
        while(getline(file,line))// read through whole text file line by line
        {
            
          if (split(line, ',', temp, arrSize) == 4)
            {
                body = temp[0];
                //cout << body << endl;
                user = temp[1];
                //cout << user << endl;
                date = temp[3];
                //cout << date << endl;
                likes = stoi(temp[2]);
                //cout << likes << endl;
                if (num_posts_ < posts_size_)
                {
                    new_post = Post(body,user,likes, date);
                    posts_[num_posts_] = new_post;
                    num_posts_++; 
                    
                } 
            }     
        }
    }
    
    return num_posts_;// return count
}
void Buffchat :: printPostsByYear(string year)
{
    /**
     * check to see if year is found
     * based on if found or not print out different messages 
     * if found loop through and print all posts with desired year
     */

    bool yearFound = false; // set found to false
   
    for(int j=0; j < num_posts_; j++) // loop through posts to check if year is found
        {
            string arrDate = posts_[j].getPostDate(); // get post date from post arr
            string arrYear = arrDate.substr(6); // make substr from start of year

            if(arrYear == year) // if found update bool
            {
                yearFound = true;
            }
        }
    if(num_posts_  <= 0) // check num_posts_ is valid
    {
        cout << "No posts are stored" << endl;
        return;
    }
   
   else if(yearFound == false) // check to see if year is found
    {
        cout << "No posts stored for year " << year << endl;
    }
    else
    {
       cout << "Here is a list of posts for year " << year << endl; // print out year and statement
       for(int i= 0; i < num_posts_; i++) // loop through num of posts again to print out matches
       {
            string arrDate = posts_[i].getPostDate();
            string arrYear = arrDate.substr(6);
    
            if(arrYear == year)// if year found cout;
            {
                cout <<  posts_[i].getPostBody() << endl; 
            }
       }
    }
}
int Buffchat :: readLikes(string file_name)
{
    /**
     * open file and set varriables
     * validate file opens and users array is not already full
     * read through file
     * if array full return value
     * set obect username numPosts and likes
     * return num users
     */

    ifstream file;
    file.open(file_name);  
    string temp[51];
    string username;
    User object;
    string line;
    if (num_users_ == users_size_) // check num users is less than array size
        {
            return -2;
        }
    else if (file_name == "") // check file name exists
        {
            return -1;
        }

    else if (file.fail()) //check file opens
        {
            return -1;
        }
    else
    {
        while (getline(file, line))
            {  
                if (num_users_ == users_size_) // when num users = array size return num users
                    {
                        return num_users_;
                    }
            
                else
                {
                    int num_posts = split(line, ',', temp, 51); // find number of posts

                    if(num_posts != 0) // if line is not empty
                    {
                        username = temp[0];
                        // Set the user name for the current user
                        users_[num_users_].setUsername(username);
                        //set num posts for the current user
                        users_[num_users_].setNumPosts(num_posts - 1);

                        for (int i = 1; i < num_posts; i++) // loop to fill likes 
                        {
                            int num_likes_for_post = stoi(temp[i]);
                            users_[num_users_].setLikesAt(i - 1, num_likes_for_post);
                        }
                        num_users_ += 1; // increase num users
                    }  
                    
                }
            }
        return num_users_; // return number of users
    }
}
int Buffchat :: getLikes(string post_author, string username)
{
    /**
     * validate posts and users are greater than zero
     * loop through users and check if usernames match
     * if usernames match loop through till post author matches
     * make sure size is less than position i else return 0
     * reuturn likes at that spot
     * if doesnt match return -3
     */

    if(num_posts_ <= 0 || num_users_ <= 0) // validate num posts and users are greater than zero
        {
            return -2;
        }
        
    for(int i= 0; i < num_users_; i++) // loop through users
        {
            if(users_[i].getUsername()== username) // validate users match
            {
                for(int j = 0; j < num_posts_; j++) // loop through posts
                    {
                        if(posts_[j].getPostAuthor() == post_author) // validate authors match
                        {    
                            if(users_[j].getSize() > i )// check size is less than user spit
                            {
                                return users_[i].getLikesAt(j); // return likes at that point
                            }
                            return 0; 
                            
                        }
                    }
            }  
        }
    return -3; // if doesnt match return -3
}
void Buffchat :: findTagUser(string username_tag)
{
    /**
     * loop through to find number of times tag is found
     * validate num users is greater than zero
     * if found 0 times sprint out message
     * if found print out statment and num times found then loop through again and print found posts
     */
    int numFound = 0; // inilize num found
    for(int i = 0; i < num_users_; i++) // loop through num users stored
    {
        string username = users_[i].getUsername();  // make username a string
        
        if (username.find(username_tag) != std::string::npos) // use find to find if found increse counter
        {
        numFound++;
        }
    }
    if(num_users_== 0) // if nothing is stored print out message
    {
        cout << "No users are stored in the database" << endl;
    }      
    else if(numFound == 0 && num_users_ >= 0) // if none are found and num users exists
    {
        cout << "No matching user found" << endl;
    }

    else
    {
        cout << "Here are all the usernames that contain " << username_tag << endl; // print out statement
        for(int i= 0; i < num_users_; i++) 
       {
        string username = users_[i].getUsername();
            if (username.find(username_tag) != std::string::npos) // loop through and print what is found
            {
                cout << username << endl;
            }
       }
    }     
}
bool Buffchat :: addPost(string post_body, string post_author, string date)
{
    /**
     * validate num posts is less than array size if not return false 
     * set values for post
     * increase number of posts
     */
    if(num_posts_ < posts_size_) // validate array is not full
    {
        // set values
        posts_[num_posts_].setPostAuthor(post_author);
        posts_[num_posts_].setPostBody(post_body);
        posts_[num_posts_].setPostDate(date);
        posts_[num_posts_].setPostLikes(0);
        for(int i =0; i < users_size_; i++)
        {
          users_[i].setLikesAt(num_posts_, -1);  
        }
        //increase number of posts
        num_posts_++;
        // return true
        return true;
    }
    else
    {
        //if full return false
        return false;
    }
}
void Buffchat :: printPopularPosts(int count, string year)
{
    /**
     * loop and find how many matches exist
     * validate array is not empty
     * if 0 print out statement
     *  if less than requested print out all matches
     * if more or equal to get top requested then print out in final order
     */

    int yearFound = 0; // set found to 0
    Post found[num_posts_];
    for(int j=0; j < num_posts_; j++) // loop through num posts
        {
            string arrDate = posts_[j].getPostDate(); // get post date from post arr
            string arrYear = arrDate.substr(6); // make substr from start of year

            if(arrYear == year) // if found update bool
            {
                found[yearFound]= posts_[j];
                yearFound++;
            }
        }
 
   if( num_posts_ <= 0) // validate posts array is not emoty 
   {
        cout << "No posts are stored" << endl;
   }
   else if(yearFound == 0) // if no posts for year found
   {
        cout << "No posts stored for year " << year << endl;
   }
   else if(yearFound < count) // if less found than desires
   {
        cout << "There are fewer than " << count << " posts for year " << year << ". Top " << yearFound << " posts for year " << year << endl;
        // print out all matches
        for( int i =0; i < yearFound; i++)
        {
        cout << found[i].getPostLikes() << " likes: " << found[i].getPostBody() << endl;
        }
   }
   else if (yearFound >= count) // if matches are greater than requested amount
   {
        cout << "Top " << count << " posts for year "<< year << endl;
    
        Post tempArr[num_posts_];
        for(int i = 0; i < num_posts_; i++) // sort array in decresing order
        {
            for(int j = 0; j + 1 < num_posts_- j; j++)
            {
                if(found[j].getPostLikes() < found[j+1].getPostLikes())
                {
                    tempArr[j] = found[j];
                    found[j]= found[j+1];
                    found[j+1] = tempArr[j];
                }
            }
        }
            
        for(int i = 0; i < num_posts_; i++) // loop through posts
        {
            for(int j = 0; j < count; j++) // loop till count
            {
                if(posts_[i].getPostAuthor() == found[j].getPostAuthor() && posts_[i].getPostDate() == found[j].getPostDate()) // when post order = top post print out
                {
                    cout << posts_[i].getPostLikes() << " likes: " << posts_[i].getPostBody() << endl;
                }
            }
        }
   }  
}
User Buffchat :: findLeastActiveUser()
{
    /**
     * initlize variables
     * if empty return a empty class
     * loop through all users and count the amount of inactive posts they have
     * if it is greater than previous replace and fill class definition
     * return the full user class at end
     */
    User leastUser;
    int likes[50];
    string username;
    int leastActive = -100; // set low so will be replaced
    if(num_users_ == 0)
    {
        return User();
    }
    for(int i = 0; i < num_users_; i++) 
    {
        int numInactive = 0;
        for(int j = 0; j < num_posts_; j++)
        {
            if (users_[i].getLikesAt(j) == -1) // when likes = -1 increse numInactive
            {
                numInactive++;
            }
        }
        if(numInactive > leastActive) // if number inactive is greater than previous replace and fill
        {
            leastActive = numInactive;
            username = users_[i].getUsername();
            for(int k = 0; k < users_[i].getNumPosts(); k++)
            {
                likes[k] = users_[i].getLikesAt(k);
            }
            leastUser = User(username,likes, users_[i].getNumPosts());  
        }
    }
    return leastUser;// return least user
}
int Buffchat :: countUniqueLikes(string post_author)
{
    /**
     * initlize varribles
     * check both users and posts arent empty
     * loop trough till author matches 
     * then get all likes for that user
     * if not -1 or 0 then increse unique likes
     * find sum
     * if sum 0 return 0
     * if sum / posts read/ -1 return -1
     * else return number of unique likes
     */

    int uniqueLikes = 0;
    int sum = 0;
    int postsRead =0;

    if(num_users_ == 0 || num_posts_ == 0) // validate arrays are not empty
    {
        return -2;
    }
   for(int i = 0; i < num_posts_; i++)
    {
        if(posts_[i].getPostAuthor()== post_author) // check if authors match
        {
            for(int j = 0; j < users_[i].getSize(); j++) // loop through checking all likes
            {
                if (users_[j].getLikesAt(i) != -1 || users_[j].getLikesAt(i) != 0) // if not 0 or -1 increse num likes
                {
                  uniqueLikes++;  
                }
                postsRead++; // increse number of posts read
                sum += users_[j].getLikesAt(i);  // add post to sum
            }
        }
    }
    if(sum == 0) // check if all not liked
    {
        return 0;
    }
    if(sum / postsRead == -1) // check if all not views
    {
        return -1;
    }    
return uniqueLikes; // else return unique likes
}