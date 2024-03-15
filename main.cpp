# include <bits/stdc++.h>

using namespace std;

string strip(const string& calc){
    string stripped;
    for (char i : calc){
        if(not isspace(i)){
            stripped += i;
        }
    }
    return stripped;
}


int main(){
    int fTermSign = 1, sTermSign = 1;
    string operation, fTerm, sTerm, fNominator, fDenominator, sNominator, sDenominator;
    string operand;

    getline(cin, operand);
    regex calcRegex(R"(-?\s*[0-9]+\s*[/]?\s*-?\s*[0-9]*\s*[\+\-\*\/]{1}\s*-?\s*[0-9]+\s*[/]?\s*-?\s*[0-9]*\s*)");

    while (not regex_match(operand, regex(calcRegex))){
        cout << "Invalid operand, Try again." << endl;
        getline(cin, operand);
    }

    operand = strip(operand);

    // First nominator sign
    int i = 0;
    if (operand[0] == '-'){
        fTermSign = -1;
        i++;
    }

    // First nominator
    while (isdigit(operand[i])){
        fNominator += operand[i];
        i++;
    }

    // first denominator
    if (operand[i] == '/'){
        i++;
        if (operand[i] == '-'){
            if (fTermSign == -1){
                fTermSign = 1;
            }
            else{
                fTermSign = -1;
            }
            i++;
        }

        while(isdigit(operand[i])){
            fDenominator += operand[i];
            i++;
        }
    }
    else{
        fDenominator = "1";
    }

    // Operation
    if (operand[i] == '+'){
        operation = "+";
        i++;
    }

    else if (operand[i] == '-'){
        operation = "-";
        i++;
    }

    else if (operand[i] == '*'){
        operation = "*";
        i++;
    }

    else if (operand[i] == '/'){
        operation = "/";
        i++;
    }

    // Second nominator sign
    if (operand[i] == '-'){
        sTermSign = -1;
        i++;
    }

    // Second nominator
    while (isdigit(operand[i])){
        sNominator += operand[i];
        i++;
    }

    // second denominator
    if (operand[i] == '/'){
        i++;
        if (operand[i] == '-'){
            if (sTermSign == -1){
                sTermSign = 1;
            }
            else{
                sTermSign = -1;
            }
            i++;
        }

        while(isdigit(operand[i])){
            sDenominator += operand[i];
            i++;
        }
    }
    else{
        sDenominator = "1";
    }

    cout << fTermSign << " " << fNominator << " " << fDenominator << " " << operation << " " << sTermSign << " " <<
        sNominator << " " << sDenominator << endl;

    return 0;
}
