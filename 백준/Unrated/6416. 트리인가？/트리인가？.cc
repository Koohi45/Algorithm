#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

unordered_set<int> nodes;
unordered_map<int, vector<int>> edge; 
unordered_map<int, int> indegree;

bool isTree(){
    int cnt_root = 0;
    int root = -1;
    for(auto node: nodes){
        if(indegree[node] == 0){
            cnt_root++;
            root = node;
        } else if(indegree[node] > 1){
            return false;
        }
    }
    if(cnt_root != 1){
        return false;
    }

    queue<int> q;
    unordered_map<int, bool> visited;
    visited[root] = true;
    q.push(root);
    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(auto next: edge[v]){
            if(visited[next]){
                return false;
            }
            visited[next] = true;
            q.push(next);
        }
    }
    for(auto node: nodes){
        if(!visited[node]){
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int u, v, k = 0;

    while(cin >> u >> v){
        if(u == -1 && v == -1){
            break;
        }
        if(u == 0 && v == 0){
            k++;
            if(nodes.size() == 0 || isTree()){
                cout << "Case " << k << " is a tree.\n";
            } else {
                cout << "Case " << k << " is not a tree.\n";
            }

            nodes.clear();
            edge.clear();
            indegree.clear();
            continue;
        }
        nodes.insert(u);
        nodes.insert(v);
        edge[u].push_back(v);
        indegree[v]++;
    }
    return 0;
}