#include <string>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

string solution(string new_id) {  
    //1단계: 대문자->소문자
    for(int i = 0; i < new_id.length(); i++){
        if(new_id[i] >= 65 && new_id[i] <= 90){  //대문자
            new_id[i] += 32;    //소문자
        }
    }
    
    //2단계: 불가능한 문자 제거
    string answer = "";
    for(int i = 0; i < new_id.length(); i++){
        if((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9') ||new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.'){
            answer += new_id[i];    
        }
    }
    
    //3단계: 마침표 연속 -> 1개의 마침표
    answer = regex_replace(answer, regex("[.]+"), ".");
    
    //4단계: 처음&끝 마침표 제거
    if(answer[0] == '.'){
        answer.erase(0, 1);
    } 
    if(answer[answer.length() - 1] == '.'){
        answer.erase(answer.length() - 1);
    }
    
    //5단계: 빈 문자열 확인
    if(answer == ""){
        answer = "a";
    }
    
    //6단계: 16자 이상 문자는 제거
    if(answer.length() >= 15){
        answer.erase(15);
        if(answer[14] == '.'){
            answer.erase(14);
        }
    }
    
    //7단계: 2자 이하는 길이가 3이 되도록 마지막 문자를 재사용
    while(answer.length() < 3){
        answer += answer[answer.length() - 1];
    }
    
    return answer;
}