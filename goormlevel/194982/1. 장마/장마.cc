#include <iostream>
#include <vector>

using namespace std;
int main() {
	int n, m, s, e;
	cin >> n >> m;
	
	vector<int> height(n + 1);
	vector<bool> is_rainy(n, false);
	for(int i = 1; i <= n; i++){
		cin >> height[i];
	}
	
	for(int i = 1; i <= m; i++){
		cin >> s >> e;
		for(int j = s; j <= e; j++){
			height[j]++;
			is_rainy[j] = true;
		}
		if(i % 3 == 0){
			for(int j = 1; j <= n; j++){
				if(is_rainy[j]){
					height[j]--;
					is_rainy[j] = false;
				}
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		cout << height[i] << ' ';
	}
	
	return 0;
}