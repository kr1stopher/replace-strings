# include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <cstring>


using namespace std;



//function to replace strings in myString per specifications found in myPairs
//will use a brute force algorithm
string replaceSubs(string myString, string find, string replace){
  string myReplace [] = {find, replace};
  string modString = myString;
  int i =0;
  while (i<(myString.length()-myReplace[0].length())){
    if (myString[i]==myReplace[0][0]){
      int isMatch = 0; //will be changed to 1 when no longer matching string to be replaced
      int j = 1; //used to iterate over string to be replaced
      while (isMatch ==0 && j<myReplace[0].length()){
        if (myString[i+j] != myReplace[0][j]){
          isMatch = 1;
        }
        else {
          j++;
        }
      }
      if (isMatch==0){
        modString = myString.substr(0,i) + myReplace[1] + myString.substr(i+j,myString.length());
      }
    }
    i++;
  }
  return modString;
}

//goes through string myString and replaces instances even members of myReplace with their appropriate odd members
string replaceSubs1(string myString, vector<string> &myReplace){
  string modString = myString;
  //for (int i = 0; i<(sizeof(myReplace)/sizeof(myReplace[0])); i++){
  for (int i = 0; i<myReplace.size(); i=i+2){
    modString = replaceSubs(modString, myReplace[i], myReplace[i+1]);
  }
  return modString;
}

//parses a string line into appropriate vector of input pairs, returns vector
vector<string> parsePairs(string line){
  vector<string> inputPairs;
  int i = 0;
  string myline = line;
  int startSub = 0;
  int endSub = 0;
  while (i<myline.length()) {
    if (myline[i]=='"' && startSub == 0){
      startSub = i+1;
    }
    if (startSub<(i+1)){
      if (myline[i]=='"'){
        endSub = i;
     }
    }
    if (endSub!=0){
      inputPairs.push_back(myline.substr(startSub, endSub-startSub));
      endSub = 0; //reset start and end substrings
      startSub = 0;
    }
    i++;
  }
  return inputPairs;
}

//function reads the lines from the input file,
//takes even lines as input strings
//takes odd lines as replacement pars and calls the parsing function to convert
vector<string> getStrings(){
  string finalString;
  vector<string> finalStrings;
  vector<string> inputPairs;
  ifstream input("replaceStringsInput.txt");
  string line;
  cout<<line<<endl;
  int i = 0;
  int j=0;
  vector <string> fileInput;
  while(getline( input, line )) {
      if (i%2==0){
        fileInput.push_back(line);
      }
      if (i%2!=0){
        //if line is odd expected replacement pairs, call parser to build into usable data
        inputPairs = parsePairs(line);
        finalStrings.push_back(replaceSubs1(fileInput[j],inputPairs));
        j++;
      }
      i++;
  }

  cout<<finalStrings[1]<<" the final string in all its glory"<<endl;
  finalString = replaceSubs1(fileInput[0],inputPairs);
  return finalStrings;

}

void printVector(vector<string> &myVector){
  cout<<"Here are the updated greeting cards";
  for (int i =0;i<myVector.size();i++){
    cout<<myVector[i]<<endl;
  }
}


int main(){
  vector<string> myFinal;
  myFinal = getStrings();
  printVector(myFinal);

  return 0;
}
