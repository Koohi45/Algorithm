#include <iostream>

using namespace std;

string makeString(int cnt, bool state){
  string result = "";
  if(state){
    result = "5";
  } else {
    result = "1";
  }
  while(cnt--){
    result += "0";
  }
  return result;
}

pair<string, string> getMaxMinNumber(string input){
  string result_max = "", result_min = "";
  int cnt = 0;
  for(int i = 0; i < input.length(); i++){
    if(input[i] == 'M'){
      cnt++;
      continue;
    }
    if(cnt){
      result_max += makeString(cnt, true);
      result_min += makeString(cnt - 1, false) + "5";
      cnt = 0;
    } else {
      result_max += "5";
      result_min += "5";
    }
  }
  
  if(cnt){
    for(int i = 0; i < cnt; i++){
      result_max += "1";
    }
    result_min += makeString(cnt - 1, false);
  }
  
  return {result_max, result_min};
}

int main(){
  string input;
  cin >> input;

  auto answer = getMaxMinNumber(input);
  cout << answer.first << '\n' << answer.second;
  return 0;
}