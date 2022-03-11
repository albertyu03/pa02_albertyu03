#include <iostream>
#include <string>
#include "movies.h"
using namespace std;

string truncQuotes(string cMovie) {
  string nMovie = cMovie;
  string::iterator it;
  for(it = nMovie.begin(); it != nMovie.end(); it++) {
    if(*it == '"') {
      nMovie.erase(it);
    }
  }
  return nMovie;
}

double retRating(string cMovie) {
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

int ratingLen(string cMovie) {
  int ratLen = 0;

  int cLength = cMovie.length();
  for(int i = cLength - 1; i >= 0; i--) {
    if(cMovie.at(i) == ' ' || cMovie.at(i) == ',') {
      break;
    }
    ratLen++;
  }
  return ratLen;
}


string truncName(string cMovie) {
  string curTrack = cMovie;
  curTrack.erase(curTrack.end() - ratingLen(cMovie) - 2, curTrack.end()); //subtract 2 for ", "
  return curTrack;
}

