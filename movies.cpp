//Movies.cpp file
#include<iostream>
#include<cstring>
#include "movies.h"
using namespace std;

movie::movie(char* tl, char* yr, char* dir, char* dur, char* rtng):category()
{
  director = new char[30];
  duration = new char[3];
  rating = new char[2];
  
  strcpy(title, tl);
  strcpy(year, yr);
  strcpy(director, dir);
  strcpy(duration, dur);
  strcpy(rating, rtng);
  id = 2;
}

movie::~movie()
{
  delete[] director;
  delete[] duration;
  delete[] rating;
}

char* movie::get_director()
{
  return director;
}

char* movie::get_duration()
{
  return duration;
}

char* movie::get_rating()
{
  return rating;
}

void movie::print_Desc()
{
  cout << "Movie: " << title << endl;
  cout << "Year: " << year << endl;
  cout << "Director: " << director << endl;
  cout << "Duration (in minutes): " << duration << endl;
  cout << "Rating (out of 5): " << rating << endl;
}
