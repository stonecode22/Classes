#ifndef CATEGORY_H
#define CATEGORY_H

class category
{
 public:
  category();
  ~category();
  char* get_title();
  char* get_year();
  int get_id();

 protected:
  char* title;
  char* year;
  int id;
};

#endif
