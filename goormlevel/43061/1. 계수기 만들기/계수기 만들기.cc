#include <iostream>
#include <vector>
using namespace std;

void solution(int n, int k, vector<int> &max_value, vector<int> &curr_num){
	int carry = k;
	for(int i = n - 1; i >= 0; i--){
		int sum = curr_num[i] + carry;
		curr_num[i] = sum % (max_value[i] + 1);
		carry = sum / (max_value[i] + 1);
	}
}

int main() {
	int n, k;
	cin >> n;
	vector<int> max_value(n);
	vector<int> curr_num(n);
	for(int i = 0; i < n; i++){
		cin >> max_value[i];
	}
	for(int i = 0; i < n; i++){
		cin >> curr_num[i];
	}
	
	cin >> k;
	
	solution(n, k, max_value, curr_num);
	for(int i = 0; i < n; i++){
		cout << curr_num[i];
	}
	return 0;
}