#ifndef MOVIES_H
#define MOVIES_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string truncQuotes(string cMovie);
double retRating(string cMovie);
string truncName(string cMovie);
int ratingLen(string cMovie);
class cmp {
  public:
    bool operator() (string& rate1, string& rate2) const {
      if(retRating(rate1) == retRating(rate2)) {
        return (truncName(rate1)>truncName(rate2));
      }
      return(retRating(rate1)<retRating(rate2));
    }
};


#endif
