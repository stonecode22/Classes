//Music.h file
#ifndef MUSIC_H
#define MUSIC_H
#include "category.h"

class music : public category
{
 public:
  music(char* tl, char* art, char* yr, char* dur, char* pub);
  ~music();
  char* get_artist();
  char* get_duration();
  char* get_publisher();
  void print_Desc();

 private:
  char* artist;
  char* duration;
  char* publisher;
};
  
#endif
