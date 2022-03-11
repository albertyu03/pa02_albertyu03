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
vector<string> movNR;

  
string line;
while (getline (movieFile, line)){
  if(line.at(0) == '"') {
    line = truncQuotes(line);
  }
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
      cout << truncName(pq.top()) << ", " << std::fixed << std::setprecision(1) << retRating(pq.top()) << endl;
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
}

/* Add your run time analysis for part 3 of the assignment here as commented block*/
/*
FINDING RUNTIME:
As per instructions, we assume that our movies and prefix lists have already been stored.
Our given variables are m(prefix#), k(most matching), and n(movies#)

1. First, we know that for every prefix we are iterating through n values. 
2. While iterating through n values, we are pushing k of them to a priority queue, which has a time complexity of o(log k).
3. As such, one "loop" of forming a priority queue of all movies matching that prefix has a time complexity of O(n + k[log(k)])
4. Of course, this will be for m prefixes, putting our complexity so far at O(m * [n + k(log[k])])
5. We are fetching, pushing, and eventually printing m prefixes. However, this has no significant impact on the runtime. Simplifying would yield O(m * [n + k(log[k]) + 3]), which can be pretty much disregarded on large scale.
6. Simplifying our complexity for #4 yields O(mn + mk[log(k)])
*/