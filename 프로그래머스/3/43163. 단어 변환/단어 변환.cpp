#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> visited;
int m;
int answer;

bool isPossible(string a, string b){
    int cnt = 0;
    for(int i = 0; i < a.length(); i++){
        if(a[i] == b[i]){
            cnt++;
        }
    }
    return cnt >= a.length() - 1;
}

void dfs(int cnt, string curr, string target, vector<string> &words){
    if(cnt == m || curr == target){
        answer = min(answer, cnt);
        return;
    }
    
    for(int i = 0; i < m; i++){
        if(visited[i] || !isPossible(curr, words[i])){
            continue;
        }
        
        visited[i] = true;
        dfs(cnt + 1, words[i], target, words);
        visited[i] = false;
    }
}

int solution(string begin, string target, vector<string> words) {
    if(find(words.begin(), words.end(), target) == words.end()){
        return 0;
    }
    
    m = words.size();
    answer = m;
    visited.assign(m, false);
    dfs(0, begin, target, words);
    return answer;
}