#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Date.h"

using namespace std;

int main (int argc, char const *argv[])
{
  int month, day, year;
  int numLines;
  string line;
  
  // allows program to read contents of file used in command-line argument
  ifstream myfile;
  myfile.open(argv[1]);
  
  while (!myfile.eof())   // loops until compiler reaches the end of file
  {
    // reads first line in file (which contains the # of dates to read)
    myfile >> numLines;
    
    vector <Date> dateVector;   // vector to store the instances of class Date
    
    for (int i = 0; i < numLines; i++)
    {
      Date date(month, day, year);    // creates instance of class Date
      
      myfile >> month;        // reads file input
      date.setMonth(month);
      
      myfile >> day;        // reads file input
      date.setDay(day);
      
      myfile >> year;        // reads file input
      date.setYear(year);
      
      dateVector.push_back(date);   // stores objects in vector
    }
    
    // calls sort() passing the static compare method
    sort(dateVector.begin(), dateVector.end(), Date::compare);
    
    // prints contents of vector at the given index
    for (int i = 0; i < numLines; i++)
      { cout << dateVector.at(i).print() << endl; }
  }
  
  myfile.close();   // closes file used in command-line argument
  
  return 0;
}