#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int priority(char ch) {
	switch (ch) {
		case '*': case '/':
			return 1;
		case '+': case '-':
			return 2;
		case '(': case ')':
			return 3;
	}
}

string infixToPostfix(string str) {
	string ans = "";
	stack<char> oper;
	for (int i = 0; i < str.length(); i++) {
		switch (str[i]) {
			case '(':
				oper.push(str[i]);
				break;
			case')':
				while (!oper.empty() && oper.top() != '(') {
					ans += oper.top();
					oper.pop();
				}
				oper.pop();
				break;
			case '+': case'-': case '*': case'/':
				while (!oper.empty() && priority(oper.top()) <= priority(str[i])) {
					ans += oper.top();
					oper.pop();
				}
				oper.push(str[i]);
				break;
			default:
				ans += str[i];
				break;
		}
	}

	while (!oper.empty()) {
		ans += oper.top();
		oper.pop();
	}

	return ans;
}

int main() {
	string str;
	cin >> str;

	cout << infixToPostfix(str);
	return 0;
}