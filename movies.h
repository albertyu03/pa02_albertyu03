#ifndef MOVIES_H
#define MOVIES_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class cmp {
  public:
    double retRating(string cMovie) const;
    bool cmp::operator() (string& rate1, string& rate2) const {
      return(retRating(rate1)<retRating(rate2));
    }
};

#endif