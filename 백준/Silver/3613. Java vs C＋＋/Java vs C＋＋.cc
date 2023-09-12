#include <iostream>
#include <cctype>

using namespace std;

bool isJava(string str){
  if(isupper(str[0])){
    return false;
  }
  for(int i = 0; i < str.length(); i++){
    if(str[i] == '_'){
      return false;
    }
  }
  return true;
}

bool isCpp(string str){
  if(str[0] == '_' || str[str.length() - 1] == '_'){
    return false;
  }
  for(int i = 0; i < str.length(); i++){
    if(isupper(str[i])){
      return false;
    }
    if(str[i] == '_' && str[i - 1] == '_'){
      return false;
    }
  }
  return true;
}

string changeToJava(string str){
  string new_str = "";
  for(int i = 0; i < str.length(); i++){
    if (str[i] == '_'){
      new_str += toupper(str[i + 1]);
      i++;
      continue;
    }
    new_str += str[i];
  }
  return new_str;
}

string changeToCpp(string str){
  string new_str = "";
  for(int i = 0; i < str.length(); i++){
    if(isupper(str[i])){
      new_str += '_';
    }
    new_str += tolower(str[i]);
  }
  return new_str;
}

string makeVariableName(string name){
  string new_name = "";
  bool is_java = isJava(name);
  bool is_cpp = isCpp(name);

  if(is_java && is_cpp){
    return name;
  } else if(is_java){
    return changeToCpp(name);
  } else if(is_cpp){
    return changeToJava(name);
  } else {
    return "Error!";
  }
}

int main(){
  string str;
  cin >> str;

  cout << makeVariableName(str);
  return 0;
}