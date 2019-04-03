// Author: Jacob Christiansen
// Recitation: 104 – Vipra Gupta
//
// Assignment 7
#include "SpellChecker.h"
#include <iostream>
#include <fstream>
using namespace std;
//empty constructor
SpellChecker::SpellChecker(){
    //ctor
}

//constructor that takes a string as a language for the object, a string as a file name for the file with the correctly spelled words, and a string as a file
//name for the file with the misspelled words and their corrections
SpellChecker::SpellChecker(string newLang){
    language = newLang;
}

SpellChecker::SpellChecker(string newLang, string rightWords, string wrongWords){
    language = newLang;
    correct = rightWords;
    incorrect = wrongWords;

}


//empty destructor
SpellChecker::~SpellChecker(){
    //dtor
}

//this function uses the given string to open a file and create an object
//if the file opens correctly ->
//it then goes through the file line by line and inputs the data into an array
//once there is no more data to use, the file is closed
//the function returns true
//if the file doesn't open correctly ->
//the function returns false
bool SpellChecker::readValidWords(string filename){
    ifstream fr;
    fr.open(filename.c_str());
    string line;
    int i = 0;
    if(fr.is_open()){
        while(!fr.eof()){
            getline(fr, line);
            valArr[i] = line;
            i++;
        }
        fr.close();
        return true;
    }
    return false;

}


//this function uses the given string to open a file and create an object
//if the file opens correctly ->
//it then goes through the file line by line
//it puts the content before the tab character into the "inc" substring
//it puts the content after the tab character into the "cor" substring
//it then breaks out of that line to protect from any overflowing
//it puts "inc" into the array "incArr"(which holds the incorrectly spelled words), then increases the index by one
//it puts "cor" into the array "corArr"(which holds the correctly spelled words), then increases the index by one
//once there is no more data to use, the file is closed
//the function returns true
//if the file doesn't open correctly ->
//the function returns false
bool SpellChecker::readCorrectedWords(string filename){
    string cor = "";
    string inc = "";
    ifstream fr;
        fr.open(filename.c_str());
        string line;
        int i = 0;
        if(fr.is_open()){
            while(!fr.eof()){
                getline(fr, line);
                for(int i=0; i<line.length(); i++){
                    if(line[i] == '\t'){
                        inc = line.substr(0,i);
                        cor = line.substr(i+1);
                        break;
                    }
                }

//                if(incArr[index] != "" && corArr[index] != ""){
                    incArr[index]=inc;
                    corArr[index]=cor;
                    index++;
//                }
            }
            fr.close();
            return true;
        }
        return false;
}

//this function sets the start_marker character equal to the given character
bool SpellChecker::setStartMarker(char setS){
    start_marker = setS;
    return true;
}
//this function sets the end_marker character equal to the given character
bool SpellChecker::setEndMarker(char setE){
     end_marker = setE;
     return true;
}
//this function returns the start_marker character
char SpellChecker::getStartMarker(){
    return start_marker;
}
//this function returns the end_marker character
char SpellChecker::getEndMarker(){
    return end_marker;
}

//this function checks every word in the array of valid words to see if matches the given word
//if so, it returns true
//if not, it returns false
bool SpellChecker::check(string test){
    for(int i=0; i<10000; i++){
        if(valArr[i] == test){
            return true;
        }
    }
    return false;
}

//this function checks every word in the array of incorrect words to see if matches the given word
//if so, it returns true
//if not, it returns false
bool SpellChecker::fixable(string temp){
    for(int i=0; i<10000; i++){
        if(incArr[i] == temp){
            return true;
        }
    }
    return false;
}

//this function checks every word in the array of incorrect words to see if matches the given word
//if so, it takes the word from that same index in the array of correct words, then returns that word
string SpellChecker::wordFix(string word){
    string newWord;
    for(int i=0; i<10000; i++){
        if(incArr[i] == word){
            newWord = corArr[i];
            return newWord;
        }
    }
}

//this function takes a given word and uses it to create a new string, which contains that word flanked by the start_marker and end_marker characters
string SpellChecker::wordMark(string word){
    string marked;
    marked = start_marker+word+end_marker;
    return marked;
}

//This function will separate each substring of the given string between separator
//characters and place it into an array. The function then returns the number of
//substrings extracted.
int SpellChecker::split(string str, char s, string words[]){
    int arrSize = 0;
    string temp = "";
    int c=0;

        if(str.length() == 0){
        return 0;
    }

    for(int i=0; i<str.length(); i++){

        if(str[i]==s){
            words[c] = temp;
            arrSize++;
            temp = "";
            c++;
        }
        else{
            temp += str[i];
        }

    }
    words[c] = temp;
    arrSize++;
    return arrSize;
}

//this function goes through the given string character by character
//if the character is in lower-case, it is copied to a new string
//if the character is in upper-case, it is copied to that new string
//if the character is a punctuation symbol and surrounded by letters, it is copied to that new string
//if the character is none of the above things, it is ignored
//that new string is then returned
string SpellChecker::removePunct(string sent){
    string temp = "";
    for (int i = 0; i < sent.length(); i++){
        if (sent[i] >= 'a' && sent[i] <= 'z'){
            temp += sent[i];
        }
        else if(sent[i] >= 'A' && sent[i] <= 'Z'){
            temp += tolower(sent[i]);
        }
        else if(sent[i] == ' '){
            temp += sent[i];
        }
        else if(sent[i] == '!' || sent[i] == '?'){
            if(sent[i-1] >= 'a' && sent[i-1] <= 'z'){
                if(sent[i+1] >= 'a' && sent[i+1] <= 'z'){
                    temp += sent[i];
                }
                else if(sent[i+1] >= 'A' && sent[i+1] <= 'Z'){
                    temp += sent[i];
                }
            }
            else if(sent[i-1] >= 'A' && sent[i-1] <= 'Z'){
                if(sent[i+1] >= 'a' && sent[i+1] <= 'z'){
                    temp += sent[i];
                }
                else if(sent[i+1] >= 'A' && sent[i+1] <= 'Z'){
                    temp += sent[i];
                }
            }
        }
    }
    return temp;
}

//this function first uses the removePunct function to edit the given string
//it then creates a new string and string array
//it then uses the split function to create an int variable that represents the total number of words in the edited string(same number as given string)
//it then goes through the array made by split and uses the check, fixable, wordMark, and wordFix functions to do the following;
// -mark the word from the given index if both check and fixable return false
// -replace the word with its correct equivalent if check returns false and fixable returns true
//it then fills the new string with the fixed/marked words, placing a space character after each word
//it then erases the last character in the new string(a space character), and returns that edited new string
string SpellChecker::repair(string sent){
    string temp = removePunct(sent);
    string rtn = "";
    string tempArr[sent.length()];

    int arrSize = split(temp, ' ', tempArr);

    for(int i=0; i<arrSize; i++){
        if(check(tempArr[i])==false){
            if(fixable(tempArr[i])==false){
                tempArr[i] = wordMark(tempArr[i]);
            }
            else{
                tempArr[i] = wordFix(tempArr[i]);
            }
        }
        rtn = rtn + tempArr[i] + ' ';
    }
    rtn.erase(rtn.size() - 1);
    return rtn;

}
