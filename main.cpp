// Author: Jacob Christiansen
// Recitation: 104 – Vipra Gupta
//
// Assignment 7
#include <iostream>
#include <string>
#include "SpellChecker.h"
#include "WordCounts.h"

using namespace std;

//this is my main code. It is used to test all the functions making sure that they work
int main(){
    SpellChecker test;
    if(test.readValidWords("validwords.txt")){
        cout << "valid works" << endl;
    }
    if(test.readCorrectedWords("misspelled.txt")){
    cout << "corrected works" << endl;
    }

    test.setStartMarker('~');
    test.setEndMarker('*');

    string rpTest = "oushdfosifsdl";
    rpTest = test.repair(rpTest);
    cout << rpTest << endl;



    WordCounts wcTest;
    string tWTest = "the brown fox jumps!";
    wcTest.tallyWords(tWTest);
    tWTest = "the red fox climbs!";
    wcTest.tallyWords(tWTest);
    tWTest = "the red bear climbs!";
    wcTest.tallyWords(tWTest);

    wcTest.getTally("wifbiglyvbl");

    cout << wcTest.getTally("fox") <<endl;



    string wArr[10000] = {"the","brown","fox","jumps"};
    int nArr[10000] = {0,1,5,3};
    int n = 3;
    wcTest.mostTimes(wArr, nArr, n);

    return 0;
}
