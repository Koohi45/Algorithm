#include <iostream>
#include <vector>

using namespace std;

int getMinColor(int n, vector<char> &question){
    int cnt = 0;
    int left = 0, right = n - 1;

    while(left <= right){
        while(left < n && question[left] == question[left + 1]){
            left++;
        }
        while(right >= 0 && question[right] == question[left]){
            right--;
        }
        cnt++;
        left++;
    }
    return cnt;
}

int main(){
    int n;
    string input;
    
    cin >> n >> input;
    vector<char> question(n);
    for(int i = 0; i < n; i++){
        question[i] = input[i];
    }

    cout << getMinColor(n, question);
    return 0;
}