#include <iostream>
#include <set>

using namespace std;
int main() {
	int n, m, k;
	set<int> card;
	
	cin >> n >> m;

	int answer = -1;
	for(int i = 1; i <= m; i++){
		cin >> k;
		card.insert(k);
		if(card.size() == n && answer == -1){
			answer = i;
		}
	}
	
	cout << answer;
	return 0;
}