//Category.cpp file
#include<iostream>
#include<cstring>
#include "category.h"
using namespace std;

category::category()
{
  title = new char[30];
  year = new char[5];
  id = 0; //cred. Harish Palani for giving advice to use "ids"
}

category::~category()
{
  delete[] title;
  delete[] year;
}

char* category::get_title()
{
  return title;
}

char* category::get_year()
{
  return year;
}

int category::get_id()
{
  return id;
}
