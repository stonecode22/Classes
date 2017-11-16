//Music.cpp file
#include<iostream>
#include<string.h>
#include "music.h"
using namespace std;

music::music(char* tl, char* art, char* yr, char* pub, char* dur):category()
{
  artist = new char[30];
  publisher = new char[30];
  duration = new char[3];
  
  strcpy(title, tl);
  strcpy(artist, art);
  strcpy(year, yr);
  strcpy(publisher, pub);
  strcpy(duration, dur);
  id = 3;
}

music::~music()
{
  delete[] publisher;
  delete[] artist;
  delete[] duration;
}

char* music::get_artist()
{
  return artist;
}

char* music::get_publisher()
{
  return publisher;
}

char* music::get_duration()
{
  return duration;
}

void music::print_Desc()
{
  cout << "Music: " << title << endl;
  cout << "Year: " << year << endl;
  cout << "Artist: " << artist << endl;
  cout << "Publisher: " << publisher << endl;
  cout << "Duration (in minutes): " << duration << endl;
}
