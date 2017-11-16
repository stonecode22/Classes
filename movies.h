//Movies.h file
#ifndef MOVIES_H
#define MOVIES_H
#include "category.h"

class movie : public category
{
 public:
  movie(char* tl, char* dir, char* yr, char* dur, char* rtng);
  ~movie();  
  char* get_director();
  char* get_duration();
  char* get_rating();
  void print_Desc();

 private:
  char* director;
  char* duration;
  char* rating;
};

#endif
  
  
  
  
