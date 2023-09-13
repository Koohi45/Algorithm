#include <iostream>
#include <vector>

using namespace std;

vector<int> cntAlphabet(string str){
  vector<int> alphabet(26, 0);
  for(int i = 0; i < str.length(); i++){
    alphabet[str[i] - 'A']++;
  }
  return alphabet;
}

bool isSimilar(string str1, string str2){
  int len1 = str1.length(), len2 = str2.length();
  int diff_len = abs(len1 - len2);
  if(diff_len >= 2){
    return false;
  }

  int cnt_diff = 0;
  vector<int> cnt1 = cntAlphabet(str1);
  vector<int> cnt2 = cntAlphabet(str2);
  for(int i = 0; i < 26; i++){
    if(cnt1[i] == cnt2[i]){
      continue;
    }
    if(abs(cnt1[i] - cnt2[i]) >= 2){
      return false;
    } else {
      cnt_diff++;
    }
  }

  if(diff_len == 0 && cnt_diff <= 2){
    return true;
  } else if(diff_len == 1 && cnt_diff == 1){
    return true;
  }
  return false;
}

int main(){
  int n, answer = 0;
  string str1, str2;

  cin >> n >> str1;
  while(--n){
    cin >> str2;
    if(isSimilar(str1, str2)){
      answer++;
    }
  }

  cout << answer;
  return 0;
}