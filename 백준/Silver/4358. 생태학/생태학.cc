#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    int cnt = 0;
    string tree;
    map<string, double> tree_count;
    
    while(getline(cin, tree)){
        cnt++;
        tree_count[tree]++;
    }

    cout << fixed;
    cout.precision(4);
    for(auto iter: tree_count){
        cout << iter.first << " " << iter.second / cnt * 100 << '\n';
    }
    return 0;
}