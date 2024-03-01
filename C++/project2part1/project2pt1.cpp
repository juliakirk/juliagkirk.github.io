// CSCI 1300 Fall 2022
// Author: Julia Kirk
// Recitation: 105 – Raegan Rychecky
// Project 2- Problem # 8

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "user.h"
#include "post.h"

using namespace std;

int split (string input_string, char seperator, string arr[], int arr_size)
{
    int inputLength =input_string.length();

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

int readPosts(string file_name, Post post[], int num_posts_stored, int posts_arr_size)
{
    Post new_post;

    ifstream file (file_name);
    string line = "";
    string body = "";
    string user= "";
    string date ="";
    int likes= 0;
    int count = num_posts_stored;
    int arrSize = 4;
    string temp[4];
    if(num_posts_stored == posts_arr_size)
    {
        count = -2;
    }
    else if (file.fail()) // check if file opens if not return 1
    {
        count = -1;
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
                if (count < posts_arr_size)
                {
                    new_post = Post(body,user,likes, date);
                    post[count] = new_post;
                    count++; 
                } 
            }     
        }
    }
    
    return count;// return count
}

void printPostsByYear(Post posts[], string year, int num_posts_stored)
{ 
    bool yearFound = false;
    
    //string arrDate = posts[1].getPostDate();
    //string arrYear = arrDate.substr(6);
    
    for(int j=0; j < num_posts_stored; j++)
        {
            string arrDate = posts[j].getPostDate();
            string arrYear = arrDate.substr(6);
            //cout << arrYear << endl;
            //cout << arrDate << endl;
            //int intYear = stoi(year);
            //int intArrYear = stoi(arrYear);
            //cout << intArrYear << endl;
            //cout << intYear << endl;
            if(arrYear == year)
            {
                yearFound = true;
            }
        }
    if(num_posts_stored <= 0)
    {
        cout << "No posts are stored" << endl;
        return;
    }
   
   else if(yearFound == false)
    {
        cout << "No posts stored for year " << year << endl;
    }
    else
    {
       cout << "Here is a list of posts for year " << year << endl;
       for(int i= 0; i < num_posts_stored; i++)
       {
            string arrDate = posts[i].getPostDate();
            string arrYear = arrDate.substr(6);
            //int intYear = stoi(year);
            ///int intArrYear = stoi(arrYear);
            if(arrYear == year)
            {
                cout <<  posts[i].getPostBody() << endl; 
            }
         
       }
    }
}

int readLikes(string file_name, User users[], int num_users_stored, int users_arr_size, int max_posts)
{ 
    /**
     * validate opens and is valid
     * go through line by line
     * fill array 
     * make new object and set
     */
    ifstream file;
    file.open(file_name);  
    int max = max_posts+= 1;
    string temp[max];
    string username;
    User object;
    string line;
    if (num_users_stored == users_arr_size)
        {
                return -2;
        }
    else if (file_name == "")
        {
            return -1;
        }

    else if (file.fail())
        {
            return -1;
        }
 

    
   
    else
    {
        while (getline(file, line))
            {  
                if (num_users_stored == users_arr_size)
                    {
                        return num_users_stored;
                    }
            
                else
                {
                    int num_posts = split(line, ',', temp, 51);

                    if(num_posts != 0)
                    {
                        username = temp[0];
                        // Set the user name for the current user
                        users[num_users_stored].setUsername(username);
                        
                        users[num_users_stored].setNumPosts(num_posts - 1);

                        for (int i = 1; i < num_posts; i++)
                        {
                            int num_likes_for_post = stoi(temp[i]);
                            users[num_users_stored].setLikesAt(i - 1, num_likes_for_post);
                        }
                        num_users_stored += 1;
                    }  
                    
                }
            }
  
  // cout << num_users_stored << endl;
  return num_users_stored;
}
}

int getLikes(string post_author, Post posts[], int num_posts_stored,string username, User users[], int num_users_stored)
{
    /**
     * index at one
     * validate user stored size
     * check to see where author == athor and user = username
     * if indexes have not changed return -3
     * else return likes at user
     */
    int indexPost = -1;
    int indexUser = -1;

    if(num_posts_stored <= 0 || num_users_stored <= 0) // check values are greater than zero
        {
            return -2;
        }
    for(int i =0; i < num_posts_stored ; i++)
    {
        if(posts[i].getPostAuthor() == post_author)
        {
            indexPost = i;
        }
    }
    for( int i = 0; i < num_users_stored; i++)
    {
        if(users[i].getUsername() == username)
        {
            indexUser = i;
        }
    }
    if(indexPost == -1 || indexUser == -1)
    {
        return -3;
    }
    else
    {
        return users[indexUser].getLikesAt(indexPost);
    }
}

void findTagUser(string username_tag, User users[], int num_users_stored)
{
    int numFound = 0; // inilize num found
   

    for(int i = 0; i < num_users_stored; i++) // loop through num users stored
    {
        string username = users[i].getUsername();  // make username a string
        
        if (username.find(username_tag) != std::string::npos) // use find to find if found increse counter
        {
        numFound++;
        }
    }
    if(num_users_stored == 0) // if nothing is stored print out message
    {
        cout << "No users are stored in the database" << endl;
    }      
    else if(numFound == 0 && num_users_stored >= 0) // if none are found and num users exists
    {
        cout << "No matching user found" << endl;
    }

    else
    {
        cout << "Here are all the usernames that contain " << username_tag << endl; // print out statement
        for(int i= 0; i < num_users_stored; i++) 
       {
        string username = users[i].getUsername();
            if (username.find(username_tag) != std::string::npos) // loop through and print what is found
            {
                cout << username << endl;
            }
        
       }
    }     
}
// introduce all varriables
int main()
{
    /**
     * initlize varribales
     * go through choices 
     * print out each function when called
     */
   string filename;
   string choice;
   string year = "";
   Post post[50];
   User user[50];

   int const size = 50;
   int num_posts = 0;
   int num_posts_stored = 0;
   int num_users = 0;
   int num_users_stored = 0;
   int maxPost = 50;
   string postAuth ="";
   string postUser = "";
   string tag = "";

   
   do
   {
      cout << "======Main Menu======" <<endl;
      cout << "1. Read Posts " << endl;
      cout << "2. Print Posts By Year" << endl;
      cout << "3. Read Likes" << endl;
      cout << "4. Get Likes" << endl;
      cout << "5. Find users with matching tag" << endl;
      cout << "6. Quit " << endl;

      cin >> choice;
      
     if(choice == "1") // when 1 is selected
     {
        cout << "Enter a post file name:" << endl;
        cin >> filename;

        int Stored = readPosts(filename, post , num_posts_stored ,size);

            if ( Stored == -1) /// calls for different coutcomes
            {
               cout << "File failed to open. No posts saved to the database." << endl;
               
            }
            else if (Stored == -2)
            {
               cout << "Database is already full. No posts were added." << endl;
               num_posts_stored = size;
               
               
            }
            else if(Stored == size)
            {
               cout << "Database is full. Some posts may have not been added." << endl;
               num_posts_stored = size;
               
            }
             else if(Stored <= 50)
            {
                cout<< "Total posts in the database: " << Stored << endl;
                num_posts_stored = Stored + num_posts;
            }
     }
      else if(choice == "2")
      {
         cout << "Enter the year(YY):" << endl;
            cin >> year;
            //cout << year << endl;
            //cout << post[0].getPostAuthor() << post[0].getPostBody() << endl;
            printPostsByYear(post, year, num_posts_stored );
      }
      else if(choice == "3")
      {
        cout << "Enter a user file name:" << endl;
        cin >> filename;

        int likesRead = readLikes(filename, user, num_users_stored, size, maxPost);
        
        if(likesRead == -1)
        {
            cout << "File failed to open. No users saved to the database." << endl;

        }
        else if(likesRead == -2)
        {
            cout << "Database is already full. No users were added." << endl;
            num_users_stored = size;
        }
        else if(likesRead == size)
        {
            cout << "Database is full. Some users may have not been added." << endl;
            num_users_stored = size;
        }
        else if(likesRead <= 50)
        {
            cout << "Total users in the database: " << likesRead << endl;
            num_users_stored = likesRead + num_users;
        }

      }
      else if(choice == "4")
      {
        
        cout << "Enter a post author:" << endl;
        cin >> postAuth;
        cout << "Enter a user name:" << endl;
        cin >> postUser;

        //cout << num_users_stored << endl;

        int getLike = getLikes(postAuth, post, num_posts_stored , postUser, user, num_users_stored);
        //cout << getLike;

        if(getLike == 0 )
        {
           cout << postUser << " has not liked the post posted by " << postAuth << endl;
        }
        else if(getLike == -1)
        {
            cout << postUser << " has not viewed the post posted by " << postAuth << endl;
        }
        else if (getLike == -2)
        {
            cout << "Database is empty." << endl;
        }
        else if(getLike== -3)
        {
            cout << postUser << " or " << postAuth << " does not exist." << endl;
        }
        else
        {
            cout << postUser << " liked the post posted by " << postAuth << " "<< getLike << " times" << endl;
        }
      }

    else if(choice == "5")
      {
        cout << "Enter a tag:" << endl;
        cin >> tag;
        findTagUser(tag, user, num_users_stored);

      }      
   
      else if( choice == "6")
      {
         cout << "Good bye!" << endl;
      }
            
      else
      {
         cout << "Invalid input." << endl;
      }
}while (choice != "6");
}
                                                  


