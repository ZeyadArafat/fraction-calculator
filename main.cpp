# include <bits/stdc++.h>
# include <string>
# include <cmath>
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

void summation(int sign1,int sign2,string nomi_1, string denomi_1,string nomi_2,string denomi_2){
    int nomi, deno ;
    nomi = ((stoi(nomi_1) * stoi(denomi_2)*sign1)) + ((stoi(nomi_2) * stoi(denomi_1)*sign2));
    deno = (stoi(denomi_1) * stoi(denomi_2));
    if (deno == 0) {
        cerr << "Error: Division by zero" << endl;
    }
    // Find the greatest common divisor
    int gcd = __gcd(nomi, deno);

    // Simplify the fraction
    nomi /= gcd;
    deno /= gcd;

    cout << "result is  : "<< nomi << "/" << deno << endl;
}

void subtraction(int sign1,int sign2,string nomi_1, string denomi_1,string nomi_2,string denomi_2){
    int nomi, deno ;
    nomi = ((stoi(nomi_1) * stoi(denomi_2)*sign1)) - ((stoi(nomi_2) * stoi(denomi_1)*sign2));
    deno = (stoi(denomi_1) * stoi(denomi_2));
    if (deno == 0) {
        cerr << "Error: Division by zero" << endl;
    }
    // Find the greatest common divisor
    int gcd = __gcd(nomi, deno);

    // Simplify the fraction
    nomi /= gcd;
    deno /= gcd;

    cout << "result is  : "<< nomi << "/" << deno << endl;
}


int main(){
    int fTermSign = 1, sTermSign = 1;
    string operation, fTerm, sTerm, fNominator, fDenominator, sNominator, sDenominator;
    string operand;

    cout << "|| FRACTION CALCULATOR ||" << endl << endl;

    while (true){
        cout << "Please enter a rational number operations or (exit)" << endl;
        cout << "->";
        getline(cin, operand);

        if (operand == "exit"){
            break;
        }
        else{
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

        }
        if (operation == "*"){
            int resultNominator, resultDinominator;
            resultNominator = fTermSign * stoi(fNominator) * stoi(sNominator);
            resultDinominator = sTermSign * stoi(fDenominator) * stoi(sDenominator);
            for (int i = min(abs(resultNominator), abs(resultDinominator)); i > 1; i--){
                if ((resultNominator % i == 0) and (resultDinominator % i == 0)){
                    resultNominator = resultNominator / i;
                    resultDinominator = resultDinominator / i;
                    break;
                }
            }
            cout << "result: " << resultNominator << "/" << resultDinominator << endl;

        }
        else if (operation == "/"){
            int resultNominator, resultDinominator;
            resultNominator = fTermSign * stoi(fNominator) * stoi(sDenominator);
            resultDinominator = sTermSign * stoi(fDenominator) * stoi(sNominator);
            for (int i = min(abs(resultNominator), abs(resultDinominator)); i > 1; i--){
                if ((resultNominator % i == 0) and (resultDinominator % i == 0)){
                    resultNominator = resultNominator / i;
                    resultDinominator = resultDinominator / i;
                    break;
                }
            }
            cout << "result: " << resultNominator << "/" << resultDinominator << endl;

        }
        else if (operation == "+"){
            summation(fTermSign,sTermSign,fNominator,fDenominator,sNominator,sDenominator);

        }
        else if (operation == "-"){
            subtraction(fTermSign,sTermSign,fNominator,fDenominator,sNominator,sDenominator);
            
        }
        else
        continue;

    }

    return 0;
}
