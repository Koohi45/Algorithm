#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int main(){
    int cnt = 0;
    string tree;
    set<string> tree_names;
    map<string, double> tree_count;
    
    while(getline(cin, tree)){
        cnt++;
        tree_names.insert(tree);
        tree_count[tree]++;
    }

    cout << fixed;
    cout.precision(4);
    for(auto iter: tree_names){
        cout << iter << " " << tree_count[iter] / cnt * 100 << '\n';
    }
    return 0;
}