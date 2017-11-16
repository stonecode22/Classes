//Games.cpp file
#include<iostream>
#include<string.h>
#include "games.h"
using namespace std;

game::game(char* tl, char* yr, char* pub, char* rtng):category()
{
  publisher = new char[30];
  rating = new char[2];
  
  strcpy(publisher, pub);
  strcpy(rating, rtng);
  strcpy(title, tl);
  strcpy(year, yr);
  id = 1;
} //copies & creates new memory space for rating and publisher

game::~game()
{
  delete[] publisher;
  delete[] rating;
} //"delete" from memory to prevent leakage

char* game::get_publisher()
{
  return publisher;
}

char* game::get_rating()
{
  return rating;
}

void game::print_Desc()
{
  cout << "Video Game: " << title << endl;
  cout << "Year: " << year << endl;
  cout << "Publisher: " << publisher << endl;
  cout << "Rating: " << rating << endl;
}
