#include <iostream>
#include <vector>

using namespace std;

int simulateOneDay(int n, vector<vector<int>> &park){
	int dr[4] = {-1, 1, 0, 0};
	int dc[4] = {0, 0, -1, 1};
	
	vector<vector<int>> prev_park = park;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(prev_park[i][j])	continue;
			for(int k = 0; k < 4; k++){
				int r = i + dr[k];
				int c = j + dc[k];
				if(r < 0 || r >= n || c < 0 || c >= n || !park[r][c])	continue;
				park[r][c]--;
				if(!park[r][c])	cnt++;
			}
		}
	}
	return cnt;
}

int solution(int n, int cnt, vector<vector<int>> &park){		
	int day = 0;

	while(cnt > 0){
		day++;
		cnt -= simulateOneDay(n, park);
	}
	return day;
}

int main() {
	int n;
	cin >> n;
	
	vector<vector<int>> park(n, vector<int>(n));
	int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> park[i][j];
			if(park[i][j]){
				cnt++;
			}
		}
	}
	
	cout << solution(n, cnt, park);
	return 0;
}