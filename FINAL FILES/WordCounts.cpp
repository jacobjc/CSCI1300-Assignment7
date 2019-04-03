// Author: Jacob Christiansen
// Recitation: 104 – Vipra Gupta
//
// Assignment 7
#include <iostream>
#include "WordCounts.h"
#include <sstream>
#include <fstream>

using namespace std;

//constructor that fills the master string and int arrays with null characters and zeros, respectively
WordCounts::WordCounts(){
 index = 0;

 for (int i = 0; i < 10000; i++){
   words[i] = "";
   counts[i] = 0;
 }
}
//destructor
WordCounts::~WordCounts(){
}

//Originally I used my split function again to run this method, however COG didn't like that so I had to switch to a string
//stream which also works.
//Firstly, it removes all punctuation and uppercase letters from the string that it took in.
//Then it will parse the array of words to check if it already exists.
//If it does exist, then it will take that index#, and add one to the value at the index# of counts array.
//If it doesn't exist, then it add it to the array at index# (which would be the next available space). Then it will add one to the value at the index# of counts array. Then it will increment index#.
//Since it is void, it doesn't return any values. However, the scope of the arrays is in the entire function, so the arrays are changed outside of the function.
void WordCounts::tallyWords(string sent){

stringstream myStream(sent); //using string stream instead of split
    string word;
    bool wordExists;
    while(myStream >> word){
    string newWord = "";
    for(int i=0; i < word.length(); i++){
        if(word[i] >= 'A' && word[i] <= 'z'){
        newWord += tolower(word[i]);
        }
    }

    wordExists = false;
    for(int i=0; i<index; i++){
        if (words[i] == newWord){
            counts[i]++;
            wordExists = true;
            }
        }
        if(wordExists == false){
            words[index] = newWord;
            counts[index] = 1;
            index++;
        }
    }
}

//this function spools through the global "words" string array, and checks if any of those words match the given words
//when it finds a match, it returns the number from equivalent index in the "counts" int array(the number of times the given word was used)
int WordCounts::getTally(string word){
    for(int i = 0; i < index; i++){
        if(words[i] == word){
            return counts[i];
        }
    }
     return 0;
}

//this functions spools through the "counts" int array and sets every word's tally of the number of times it was used back to zero
void WordCounts::resetTally(){
    for(int i=0; i<index; i++){
        counts[i]=0;
    }
}

//this function adds to empty new string and int arrays by copying the first "n" characters of the bubble-sorted master arrays
int WordCounts::mostTimes(string cWords[], int cCounts[], int n){
    sortArrays();
    int temp = 0;
    for(int i=0; i<n; i++){
        if (words[i]==""){
        break;
        }
    cWords[i] = words[i];
    cCounts[i] = counts[i];
    temp++;
    }
 return temp;
}

//this function bubble-sorts the "words" string array and "counts" int array
void WordCounts::sortArrays(){
    int cSwap;
    string wSwap;
    for (int i = 0; i < index - 1; i++){
        for (int j = 0; j < index - i - 1; j++){
            if (counts[j] < counts[j + 1]){
            wSwap = words[j];
            words[j] = words[j + 1];
            words[j + 1] = wSwap;
            cSwap = counts[j];
            counts[j] = counts[j + 1];
            counts[j + 1] = cSwap;
            }
        }
    }
}
