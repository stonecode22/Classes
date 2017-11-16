//Classes by Stone Yang
//Stores entries of games, movies, and music by classes
//Cred. hanst99 for showing how to use an IDE & compile correctly
#include<iostream>
#include<cstring>
#include<vector>
#include "category.h"
#include "games.h"
#include "movies.h"
#include "music.h"
using namespace std;

//function prototypes
//cred. Alex Y. demonstrating pointers and vectors
void add(vector<category*>* slct);
void srch(vector<category*> slct);
void del(vector<category*> slct);

int main()
{
  char choice;
  vector<category*> slct;
  vector<category*>* slctPtr = &slct;
  
  do
    {
      cout << "Press '1' to add, '2' to search, '3' to delete an entry; 'q' to exit out." << endl;
      cin >> choice;
      cin.ignore();

      if(choice == '1')
	{
	  add(slctPtr);
	}
      else if(choice == '2')
	{
	  srch(slct);
	}
      else if(choice == '3')
	{
	  del(slct);
	}
    }while(choice != 'q'); //loop
  return 0;
}

//functions

void add(vector<category*>* slct) //add entry
{
  char title[30];
  char year[5];
  int choice2;

  cout << "Enter title: " << endl;
  cin.getline(title, 30);

  for(int i = 0; i < strlen(title); i++) //remove case-sensitivity
    {
      title[i] = toupper(title[i]);
    }

  cout << "Enter year of release: " << endl; //get year
  cin.getline(year, 5);
  cout << "Which category does this fall under? (1 - Game, 2 - Movie, 3 - Music): ";
  cin >> choice2; //choose category
  cin.ignore();

  if(choice2 == 1) //game entry
    {
      char publisher[30];
      char rating[2];

      cout << endl << "Enter rating (out of 5): ";
      cin.getline(rating, 2);
      cout << endl << "Enter publisher: ";
      cin.getline(publisher, 30);

      game* GAME = new game(title, year, publisher, rating); //allocate space for 'GAME'
      slct -> push_back(GAME); //'GAME' stored

      cout << endl << "Changes have been saved!" << endl;
    }
  else if(choice2 == 2) //movie entry
    {
      char director[30];
      char duration[3];
      char rating[2];

      cout << endl << "Enter director: ";
      cin.getline(director, 30);
      cout << endl << "Enter duration (in minutes): ";
      cin.getline(duration, 3);
      cout << endl << "Enter rating (out of 5): ";
      cin.getline(rating, 2);

      movie* MOVIE = new movie(title, year, director, duration, rating); //allocate space for 'MOVIE'
      slct -> push_back(MOVIE); //'MOVIE' stored

      cout << endl << "Changes have been saved!" << endl;
    }
  else if(choice2 == 3) //music entry
    {
      char artist[30];
      char publisher[30];
      char duration[3];

      cout << "Enter artist: ";
      cin.getline(artist, 30);
      cout << endl << "Enter publisher: ";
      cin.getline(publisher, 30);
      cout << "Enter duration (in minutes): ";
      cin.getline(duration, 3);

      music* MUSIC = new music(title, artist, year, publisher, duration); //allocate space for 'MUSIC'
      slct -> push_back(MUSIC); //'MUSIC' stored

      cout << endl << "Changes have been saved!" << endl;
    }
  else
    {
      cout << "Invalid Category." << endl;
    }
}
      
void srch(vector<category*> slct) //search entries
{
  int choice3;
  cout << "Press '1' to search by title or press '2' to search by year." << endl;
  cin >> choice3; //prompts what method to use
  cin.ignore();

  if(choice3 == 1) //by title
    {
      char title[30];
      cout << "Enter title: ";
      cin.getline(title, 30);
      cout << endl;

      for(int i = 0; i < strlen(title); i++)
	{
	  title[i] = toupper(title[i]);
	}

      cout << "Search results: " << endl;

      for(int i = 0; i < slct.size(); i++) //prints description if title exists
	{
	  if(strcmp(title, slct[i] -> get_title()) == 0)
	    {
	      if(slct[i] -> get_id() == 1)
		{
		  ((game*) slct[i]) -> print_Desc();
		}
	      else if(slct[i] -> get_id() == 2)
		{
		  ((movie*) slct[i]) -> print_Desc();
		}
	      else if(slct[i] -> get_id() == 3)
		{
		  ((music*) slct[i]) -> print_Desc();
		}
	    }
	}
    }
  else if(choice3 == 2)
    {
      char year[5];

      cout << "Enter year of release: ";
      cin.getline(year, 5);
      cout << endl << "Search results: " << endl;

      for(int i = 0; i < slct.size(); i++) //prints descriptions if year exists
	{
	  if(strcmp(year, slct[i] -> get_year()) == 0)
	    {
	      if(slct[i] -> get_id() == 1)
		{
		  ((game*) slct[i]) -> print_Desc();
		}
	      else if(slct[i] -> get_id() == 2)
		{
		  ((movie*) slct[i]) -> print_Desc();
		}
	      else if(slct[i] -> get_id() == 3)
		{
		  ((music*) slct[i]) -> print_Desc();
		}
	    }
	}
    }
}

void del(vector<category*> slct) //deletes entries //cred. Harish Palani, showing how to use strcmp to delete entries 
{
  int choice4;

  cout << "Press '1' to delete by title, or press '2' to delete by year." << endl;
  cin >> choice4; //prompts what method to use

  if(choice4 == 1) //by title
    {
      char title[30];

      cout << "Enter title: ";
      cin.getline(title, 30);
      cin.ignore();

      for(int i = 0; i <strlen(title); i++)
	{
	  title[i] = toupper(title[i]);
	}

      for(int i = 0; i < slct.size(); i++) //delete memory space & entries
	{
	  if(strcmp(title, slct[i] -> get_title()) == 0)
	    {
	      if(slct[i] -> get_id() == 1)
		{
		  delete ((game*) slct[i]);
		  slct.erase(slct.begin() + i); //deletes a game entry of the vector from term "i" from the beginning term of vector 'slct'
		}
	      else if(slct[i] -> get_id() == 2)
		{
		  delete ((movie*) slct[i]);
		  slct.erase(slct.begin() + i);
		}
	      else if(slct[i] -> get_id() == 3)
		{
		  delete ((music*) slct[i]);
		  slct.erase(slct.begin() + i);
		}
	    }
	  cout << "Entry successfully deleted." << endl;
	}
    }
  else if(choice4 == 2) //same thing by year
    {
      char year[5];

      cout << "Enter year of release: ";
      cin.getline(year, 5);

      for(int i = 0; i < slct.size(); i++)
	{
	  if(strcmp(year, slct[i] -> get_year()) == 0)
	    {
	      if(slct[i] -> get_id() == 1)
		{
		  delete ((game*) slct[i]);
		  slct.erase(slct.begin() + i);
		}
	      if(slct[i] -> get_id() == 2)
		{
		  delete ((movie*) slct[i]);
		  slct.erase(slct.begin() + i);
		}
	      if(slct[i] -> get_id() == 3)
		{
		  delete ((music*) slct[i]);
		  slct.erase(slct.begin() + i);
		}
	    }
	}
      cout << "Entry successfully deleted." << endl;
    }
}
