#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<int, int> ci;
typedef pair<string, int> si;

bool cmpGenres(const si &a, const si &b){
    return a.second > b.second;
}

bool cmpSongs(const ci &a, const ci &b){
    if(a.first != b.first){
        return a.first > b.first;
    }
    return a.second < b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    unordered_map<string, int> streaming_count;
    unordered_map<string, vector<ci>> genre_songs;
    
    for(int i = 0; i < genres.size(); i++){
        streaming_count[genres[i]] += plays[i];
        genre_songs[genres[i]].push_back({plays[i], i});
    }
    
    vector<si> vec(streaming_count.begin(), streaming_count.end());
    sort(vec.begin(), vec.end(), cmpGenres);
    
    for(int i = 0; i < vec.size(); i++){
        vector<ci> songs = genre_songs[vec[i].first];
        sort(songs.begin(), songs.end(), cmpSongs);
        answer.push_back(songs[0].second);
        if(songs.size() == 1){
            continue;
        }
        answer.push_back(songs[1].second);        
    }

    return answer;
}