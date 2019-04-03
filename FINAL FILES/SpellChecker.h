// Author: Jacob Christiansen
// Recitation: 104 – Vipra Gupta
//
// Assignment 7
#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H
#include <iostream>
using namespace std;


class SpellChecker{

    public:
        SpellChecker();
        SpellChecker(string);
        SpellChecker(string, string, string);
        ~SpellChecker();

        //methods
        bool readValidWords(string);
        bool readCorrectedWords(string);
        bool setStartMarker(char);
        bool setEndMarker(char);
        char getStartMarker();
        char getEndMarker();
        string repair(string);
        int split(string, char, string[]);





        //variables
        string language;
        string correct;
        string incorrect;
        string valArr[10000];
        string incArr[10000];
        string corArr[10000];


    private:
        //methods
        bool check(string);
        bool fixable(string);
        string wordFix(string);
        string wordMark(string);
        string removePunct(string);


        //variables
        int index = 0;
        char start_marker;
        char end_marker;

};

#endif // SPELLCHECKER_H
