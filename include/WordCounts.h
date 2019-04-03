// Author: Jacob Christiansen
// Recitation: 104 – Vipra Gupta
//
// Assignment 7
#ifndef WORDCOUNTS_H
#define WORDCOUNTS_H
#include <iostream>
using namespace std;


class WordCounts{
    public:
        WordCounts();
        ~WordCounts();

        //methods
        void tallyWords(string);
        int getTally(string);
        void resetTally();
        int mostTimes(string[], int[], int);

        //variables


    private:
        //methods
        void sortArrays();

        //variables
        int index;
        string words[10000];
        int counts[10000];

};

#endif // WORDCOUNTS_H
