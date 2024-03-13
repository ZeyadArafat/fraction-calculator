#include <iostream>
#include <string>
using namespace std;

string strip(string sentence){ // to remove the spaces in the text in the route cipher encryption .
    string strippedSentence;
    for(int i = 0; i < sentence.length(); i++){
        if(sentence[i] != ' '){
            strippedSentence += sentence[i];
        }
    }
    return strippedSentence;
}


bool is_number(char z){
    if((z=='0') || (z=='1') || (z=='2') || (z=='3') || (z=='4') || (z=='5') || (z=='6') || (z=='7') || (z=='8') || (z=='9')) {return true;}
    else{return false;}
}


int main(){


    string lineOfOperation, operation, result, currentTerm;
    int firstNominator, secondNominator, firstDinominator, secondDinominator, divisionCounter, termNumber = 0;
    //cin.ignore();
    getline(cin, lineOfOperation);
    lineOfOperation = strip(lineOfOperation) + "$";
    for(int i; i < lineOfOperation.length(); i++){
        if (lineOfOperation[i] == '/') divisionCounter++;
        else if (lineOfOperation[i] == '+') operation = '+';
        else if (lineOfOperation[i] == '-') operation = '-';
        else if (lineOfOperation[i] == '*') operation = '*';
        if (divisionCounter == 3) operation = '/';
        if(is_number(lineOfOperation[i])) currentTerm += lineOfOperation[i];


        else if(!(is_number(lineOfOperation[i]))){
            if (termNumber == 0){
                firstNominator = stoi(currentTerm);
                termNumber++;
                currentTerm = "";
            }
            else if (termNumber == 1){
                firstDinominator = stoi(currentTerm);
                termNumber++;
                currentTerm = "";
            }
            else if (termNumber == 2){
                secondNominator = stoi(currentTerm);
                termNumber++;
                currentTerm = "";
            }
            else if (termNumber == 3){
                secondDinominator = stoi(currentTerm);
            }
        }

    }

    return 0;
}
