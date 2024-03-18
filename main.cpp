/*
File: CS112_A2_T3_21_20230161_20230109_20230476.cpp
Purpose: Fraction Calculator
Authors:
    Zeyad Mohamed Arafat - 20230161   s21   zeyadarafat833@gmail.com
    John Ayman Demian    - 20230109   s21   johnayman03@gmail.com
    Youssef Ahmed Beshir - 20230476   s21   youssefahmedbeshir@gmail.com

20230161 - Multiplication, division functions
20230109 - Summation, subtraction functions
20230476 - Regex expression, separated each term in the operand expression
 */

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


void summation(int sign1, int sign2, const string& nominator1, const string& denominator1,
               const string& nominator2, const string& denominator2){

    int nominator, denominator;
    if (denominator1 == "0" || denominator2 == "0"){
        cout << "Error: Division by zero." << endl << endl;
        return;
    }

    nominator = ((stoi(nominator1) * stoi(denominator2) * sign1)) +
                ((stoi(nominator2) * stoi(denominator1) * sign2));
    denominator = (stoi(denominator1) * stoi(denominator2));

    // Find the greatest common divisor
    int comn_factor = __gcd(nominator, denominator);

    // Simplify the fraction
    nominator /= comn_factor;
    denominator /= comn_factor;

    if (denominator == 1){
        cout << "result is: " << nominator << endl << endl;
    }
    else{
        cout << "result is: " << nominator << "/" << denominator << endl << endl;
    }
}


void subtraction(int sign1, int sign2, const string& nominator1, const string& denominator1,
                 const string& nominator2, const string& denominator2){
    int nominator, denominator ;

    if (denominator1 == "0" || denominator2 == "0"){
        cout << "Error: Division by zero." << endl;
        return;
    }

    nominator = ((stoi(nominator1) * stoi(denominator2) * sign1)) -
                ((stoi(nominator2) * stoi(denominator1) * sign2));
    denominator = (stoi(denominator1) * stoi(denominator2));

    // Find the greatest common divisor
    int comn_factor = __gcd(nominator, denominator);

    // Simplify the fraction
    nominator /= comn_factor;
    denominator /= comn_factor;

    if (denominator == 1){
        cout << "result is: " << nominator << endl << endl;
    }
    else{
        cout << "result is: " << nominator << "/" << denominator << endl << endl;
    }
}


void multiplication(int sign1, int sign2, const string& nominator1, const string& denominator1,
                    const string& nominator2, const string& denominator2){
    int nominator, denominator;

    if (denominator1 == "0" || denominator2 == "0"){
        cout << "Error: Division by zero." << endl << endl;
        return;
    }

    nominator = sign1 * stoi(nominator1) * stoi(nominator2);
    denominator = sign2 * stoi(denominator1) * stoi(denominator2);

    for (int i = min(abs(nominator), abs(denominator)); i > 1; i--){
        if ((nominator % i == 0) and (denominator % i == 0)){
            nominator = nominator / i;
            denominator = denominator / i;
            break;
        }
    }

    if (denominator == 1){
        cout << "result: " << nominator << endl << endl;
    }
    else {
        cout << "result: " << nominator << "/" << denominator << endl << endl;
    }
}


void division(int sign1, int sign2, const string& nominator1, const string& denominator1,
              const string& nominator2, const string& denominator2){
    int nominator, denominator;

    if (denominator1 == "0" || denominator2 == "0"){
        cout << "Error: Division by zero." << endl << endl;
        return;
    }

    nominator = sign1 * stoi(nominator1) * stoi(denominator2);
    denominator = sign2 * stoi(denominator1) * stoi(nominator2);

    for (int i = min(abs(nominator), abs(denominator)); i > 1; i--){
        if ((nominator % i == 0) and (denominator % i == 0)){
            nominator = nominator / i;
            denominator = denominator / i;
            break;
        }
    }

    if (denominator == 1){
        cout << "result: " << nominator << endl << endl;
    }
    else {
        cout << "result: " << nominator << "/" << denominator << endl << endl;
    }
}


int main(){
    int stTermSign = 1, ndTermSign = 1;
    string operation, nominator1, denominator1, nominator2, denominator2;
    cout << "|| FRACTION CALCULATOR ||" << endl << endl;

    while (true){
        operation = "", nominator1 = "", denominator1 = "", nominator2 = "", denominator2 = "";
        string operand;

        cout << "Please enter a rational number operations or (exit)" << endl;
        cout << "->";
        getline(cin, operand);

        if (operand == "exit"){
            cout << "Thank you for using rational number calculator." << endl;
            break;
        }

        else{
            regex calcRegex(R"([-+]?[0-9]+[/]?[-+]?[0-9]*\s{1}[\+\-\*\/]{1}\s{1}[-+]?[0-9]+[/]?[-+]?[0-9]*)");

            if (not regex_match(operand, regex(calcRegex))){
                cout << "Invalid operand, Try again." << endl << endl;
                continue;
            }

            operand = strip(operand);

            // First nominator sign
            int i = 0;
            if (operand[0] == '-'){
                stTermSign = -1;
                i++;
            }
            else if (operand[0] == '+'){
                stTermSign = 1;
                i++;
            }

            // First nominator
            while (isdigit(operand[i])){
                nominator1 += operand[i];
                i++;
            }

            // first denominator
            if (operand[i] == '/'){
                i++;
                if (operand[i] == '-'){
                    if (stTermSign == -1){
                        stTermSign = 1;
                    }
                    else{
                        stTermSign = -1;
                    }
                    i++;
                }
                else if(operand[i] == '+'){
                    if (stTermSign == -1){
                        stTermSign = -1;
                    }
                    else {
                        stTermSign = 1;
                    }
                    i++;
                }

                while(isdigit(operand[i])){
                    denominator1 += operand[i];
                    i++;
                }
            }
            else{
                denominator1 = "1";
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
                ndTermSign = -1;
                i++;
            }
            else if (operand[i] == '+'){
                ndTermSign = 1;
                i++;
            }

            // Second nominator
            while (isdigit(operand[i])){
                nominator2 += operand[i];
                i++;
            }

            // second denominator
            if (operand[i] == '/'){
                i++;
                if (operand[i] == '-'){
                    if (ndTermSign == -1){
                        ndTermSign = 1;
                    }
                    else{
                        ndTermSign = -1;
                    }
                    i++;
                }
                else if (operand[i] == '+'){
                    if (ndTermSign == -1){
                        ndTermSign = -1;
                    }
                    else{
                        ndTermSign = 1;
                    }
                    i++;
                }

                while(isdigit(operand[i])){
                    denominator2 += operand[i];
                    i++;
                }
            }
            else{
                denominator2 = "1";
            }
        }

        if (operation == "*"){
            multiplication(stTermSign, ndTermSign, nominator1, denominator1, nominator2, denominator2);
        }
        else if (operation == "/"){
            division(stTermSign, ndTermSign, nominator1, denominator1, nominator2, denominator2);
        }
        else if (operation == "+"){
            summation(stTermSign, ndTermSign, nominator1, denominator1, nominator2, denominator2);

        }
        else if (operation == "-"){
            subtraction(stTermSign, ndTermSign, nominator1, denominator1, nominator2, denominator2);
        }
        else
            continue;
    }

    return 0;
}
