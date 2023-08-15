#include <iostream>
#include <vector>

using namespace std;

int LSC(string &str1, string &str2){
    int len1 = str1.length();
    int len2 = str2.length();
    vector<vector<int>> dp(len1 + 1, vector<int> (len2 + 1, 0));

    for(int i = 1; i <= len1; i++){
        for(int j = 1; j <= len2; j++){
            if(str1[i - 1] == str2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else{
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[len1][len2];
}

int main(){
    string str1, str2;
    cin >> str1 >> str2;

    cout << LSC(str1, str2);

    return 0;
}