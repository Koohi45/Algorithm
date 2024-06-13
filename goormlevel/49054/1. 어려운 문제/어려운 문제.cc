#include <iostream>
#include <vector>

using namespace std;

void multiply(vector<int> &num, int n){
	int carry = 0;
	for(int i = 0; i < num.size(); i++){
		int curr = num[i] * n + carry;
		num[i] = curr % 10;
		carry = curr / 10;
	}
	if(carry){
		num.push_back(carry);
	}
}

long long sum(long long curr){
	int result = 0;
	while(curr){
		result += curr % 10;
		curr /= 10;
	}
	return result;
}

int solution(int n){
	vector<int> num;
	num.push_back(1);
	
	for(int i = 2; i <= n; i++){
		multiply(num, i);
	}

	int result = 0;
	for(int i = 0; i < num.size(); i++){
		result += num[i];
	}
	
	while(result / 10){
		result = sum(result);
	}
	
	return result;
}

int main() {
	int n;
	cin >> n;
	if(n > 5){
		cout << 9;
	} else {
		cout << solution(n);
	}
	
	return 0;
}