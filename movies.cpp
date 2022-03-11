#include <iostream>
#include <string>
#include "movies.h"
using namespace std;

double cmp::retRating(string cMovie) const {
  string curTrack = "";

  int cLength = cMovie.length();
  for(int i = cLength - 1; i >= 0; i--) {
    if(cMovie.at(i) == ' ' || cMovie.at(i) == ',') {
      break;
    }
    curTrack = cMovie.at(i) + curTrack;
  }
  return atof(curTrack.c_str());
}
