#ifndef GAMES_H
#define GAMES_H
#include "category.h"

class game : public category
{
 public:
  game(char* tl, char* yr, char* pub, char* rtng);
  ~game();
  char* get_publisher();
  char* get_rating();
  void print_Desc();

 private:
  char* publisher;
  char* rating;
};

#endif
  
  
  
  
