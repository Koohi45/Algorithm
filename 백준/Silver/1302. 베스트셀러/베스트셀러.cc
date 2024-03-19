#include <iostream>
#include <map>

using namespace std;

int main(){
    int n;
    string book;
    map<string, int> count;

    cin >> n;
    while(n--){
        cin >> book;
        count[book]++;
    }

    int max_count = 0;
    string max_book = "";
    for(auto iter: count){
        if(iter.second > max_count){
            max_book = iter.first;
            max_count = iter.second;
        }
    }

    cout << max_book;
    return 0;
}
