#include <iostream>
#include <vector>

using namespace std;

vector<char> necessary = {'a', 'c', 'i', 'n', 't'};
vector<bool> alphabet(26, false);
vector<string> words;
int n, k, answer = 0;

int cntWord(){
  int cnt = 0;
  for(int i = 0; i < n; i++){
    bool check = true;
    for(int j = 0; j < words[i].length(); j++){
      if(!alphabet[words[i][j] - 'a']){
        check = false;
        break;
      }
    }
    if(check){
      cnt++;
    }
  }
  return cnt;
}

void backtracking(int cnt, int start){
  if(cnt == k){
    answer = max(answer, cntWord());
    return;
  }

  for(int i = start; i < 26; i++){
    if(alphabet[i]){
      continue;
    }
    alphabet[i] = true;
    backtracking(cnt + 1, i + 1);
    alphabet[i] = false;
  }
}

int main(){
  string word;

  cin >> n >> k;
  for(int i = 0; i < n; i++){
    cin >> word;
    words.push_back(word.substr(4, word.length() - 8));
  }
  
  if(k < necessary.size()){
    cout << "0";
    return 0;
  }

  for(int i = 0; i < necessary.size(); i++){
    alphabet[necessary[i] - 'a'] = true;
  }
  k -= necessary.size();

  backtracking(0, 0);
  cout << answer;
  return 0;
}