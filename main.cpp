#include <iostream>
#include "Point.h"
#include <vector>
#include <cctype>
#include <cstring>

#define boolToString(b) (b ? "true" : "false")

using namespace std;

//Partie 1 :
template<class T> void pointTest(){
    Point<T> p(6.9,2.4);
    p.print();
}

void pointTests(){
    pointTest<int>();
    pointTest<float>();
}

//Partie 2 :
template<class T> void printVectors(vector<T> tab){
    cout << "[";
    for(T i : tab){
        cout << i;
        if(i != tab[tab.size()-1]) {
            cout << ",";
        }
    }
    cout << "]" << endl;
}

void printNumbers(){
    vector<int> numbers = {1,2,3};
    printVectors(numbers);
}

void printLetters(){
    vector<char> letters = {'A','B','C'};
    printVectors(letters);
}

void printVectorTests(){
    printNumbers();
    printLetters();
}

bool isNumber(string str){
    for(int i = 0; i < str.size(); i++){
        if(!isdigit(str[i]))
            return false;
    }
    return true;
}

void isNumberTests(){
    cout << boolToString(isNumber("1") ) << endl;
    cout << boolToString(isNumber("42") ) << endl;
    cout << boolToString(isNumber("6PO") ) << endl;
    cout << boolToString(isNumber("R2D2") ) << endl;
}

void keepNumbersOnly(vector<string>& tab){
    for(vector<string>::iterator it = tab.begin(); it != tab.end(); it++){
        if(!isNumber(*it)){
            tab.erase(it);
            it--;
        }
    }
}

void filterVectorTest(){
    vector<string> values = {"Z", "1", "A", "42", "E", "G", "0"};
    keepNumbersOnly(values);
    printVectors(values);
}

vector<string> splitString(string str1, string str2 = " "){
    for(string::iterator it = str1.begin(); it != str1.end(); it++){
        if(*it == str2[0]){
            str1.erase(it);
            it--;
        }
    }
    vector<string> newStr(str1.size());
    for(int i = 0; i < str1.size(); i++){
        newStr[i].push_back(str1[i]);
    }
    return newStr;
}

void splitTests(){
    vector<string> operators = splitString("+ - / =");
    printVectors(operators);
    vector<string> numbers = splitString("1,2,3,4,5", ",");
    printVectors(numbers);
    vector<string> letters = splitString("A-B-C-D", "-");
    printVectors(letters);
}

int main() {
    //pointTests();
    //printVectorTests();
    //isNumberTests();
    //filterVectorTest();
    splitTests();
    return 0;
}
