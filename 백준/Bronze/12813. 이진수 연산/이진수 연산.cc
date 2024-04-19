#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 100000;

string AND(string A, string B){
    string result = "";
    for(int i = 0; i < SIZE; i++){
        result += A[i] & B[i];
    }
    return result;
}

string OR(string A, string B){
    string result = "";
    for(int i = 0; i < SIZE; i++){
        result += A[i] | B[i];
    }
    return result;
}

string XOR(string A, string B){
    string result = "";
    for(int i = 0; i < SIZE; i++){
        result += A[i] == B[i]? '0' : '1';
    }
    return result;
}

string NOT(string A){
    string result = "";
    for(int i = 0; i < SIZE; i++){
        result += A[i] == '1'? '0' : '1';
    }
    return result;
}

int main(){
    string A, B;
    cin >> A >> B;

    cout << AND(A, B) << '\n';
    cout << OR(A, B) << '\n';
    cout << XOR(A, B) << '\n';
    cout << NOT(A) << '\n' << NOT(B);
    return 0;
}