// Winter'22
// Instructor: Diba Mirza
// Student name: Albert Yu
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <iomanip>
#include <set>
#include <queue>
#include "movies.h"
using namespace std;




bool parseLine(string &line, string &movieName, double &movieRating);

int main(int argc, char** argv){
  
  if(argc < 2){
    cerr << "Not enough arguments provided (need at least 1 argument)." << endl;
    cerr << "Usage: " << argv[ 0 ] << " filename prefix1 prefix2 ... prefix n " << endl;
    exit(1);
  }


  ifstream movieFile (argv[1]);
 

  if (movieFile.fail()){
    cerr << "Could not open file " << argv[1];
    exit(1);
  }
  
//Create an object of a STL data-structure to store all the movies
vector<string> movNR;

  
string line;
// Read each file and store the name and rating
while (getline (movieFile, line)){
  // Use std::string movieName and double movieRating
  // to construct your Movie objects
  // cout << movieName << " has rating " << movieRating << endl;
  // insert elements into your data structure
  line.insert(line.end() - ratingLen(line), ' ');
  movNR.push_back(line);
}

movieFile.close();

if(argc == 2){
  sort(movNR.begin(), movNR.end());
  //print all the movies in ascending alphabetical order of movie names
  for(unsigned int i = 0; i < movNR.size(); i++) {
    cout << truncName(movNR.at(i)) << std::fixed << std::setprecision(1) << ", " << retRating(movNR.at(i)) << endl;
  }
  
}

vector<string> topNames;
vector<double> topRatings;
for(int i = 2; i < argc; i++) {
  priority_queue<string, vector<string>, cmp> pq;
  string prefix = argv[i];
  for(unsigned int a = 0; a < movNR.size(); a++) {
    int prefLength = prefix.length();
    string curMovie = movNR.at(a);
    string actPref = curMovie.substr(0, prefLength);
    if(actPref.compare(prefix) == 0) {
      pq.push(curMovie);
    }
  }
  if(pq.empty()) {
    topNames.push_back("NONE");
    topRatings.push_back(-1);
  } else {
    topNames.push_back(truncName(pq.top()));
    topRatings.push_back(retRating(pq.top()));
    while(!pq.empty()) {
      cout << truncName(pq.top()) << ", " << std::fixed << std::setprecision(2) << retRating(pq.top()) << endl;
      pq.pop();
    }
    cout << endl;
  }
}

for(int i = 2; i < argc; i++) {
  if(topRatings.at(i-2) != -1) {
    cout << "Best movie with prefix "<< argv[i] <<" is: " << topNames.at(i-2) <<" with rating " << std::fixed << std::setprecision(1) << topRatings.at(i-2) << endl;
  } else {
    cout<<"No movies found with prefix "<< argv[i] <<endl<<endl;
  }
}
return 0;
//  For each prefix,
//  Find all movies that have that prefix and store them in an appropriate data structure
//  If no movie with that prefix exists print the following message
cout<<"No movies found with prefix "<<"<replace with prefix>"<<endl<<endl;

//  For each prefix,
//  Print the highest rated movie with that prefix if it exists.
cout << "Best movie with prefix "<<"<replace with prefix>"<<" is: " << "replace with moview name" <<" with rating " << std::fixed << std::setprecision(1) << "replace with movie rating"<< endl;
    


return 0;
}

/* Add your run time analysis for part 3 of the assignment here as commented block*/


/*
bool parseLine(string &line, string &movieName, double &movieRating) {
  if(line.length() <= 0) return false;
  string tempRating = "";

  bool flag = false;
  movieName = tempRating = "", movieRating = 0.0, flag = false;

  for (int i = 0; i < line.length(); i++){
    if(flag) tempRating += line[i];
    else if(line[i]==','&& line[0]!='"') flag = true;
    else {
		  if(i==0 && line[0]=='"') continue;
		  if(line[i]=='"'){ i++; flag=true; continue;}
		  movieName += line[i];
	  }
  }
  
  movieRating = stod(tempRating);
  return true;
}
*/
