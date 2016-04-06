#include<iostream>
#include<stack>
#include<string>
#include<cmath>
using namespace std;
int main() {
	stack<char> opening;
	string str;
	char symbol;
	bool is_match = true;
	string count;
		int flag = 0;
		int num = 0;
	getline(cin, count);
	int i = 0, a = count.size()-1;
	while (a) {
		num = num + pow(10,a) * (count[i++]-'0');
		a--;
	}
	num += count[i] - '0';
	while (num--) {
		getline(cin, str);
		for (int i = 0; i < str.size() && is_match; i++) {
			symbol = str[i];
			if (str[0] == ')' || str[0] == '}' || str[0] == ']') flag = 1;
			if (symbol == '(' || symbol == '[' || symbol == '{')
				opening.push(symbol);
			if (symbol == ')' || symbol == ']' || symbol == '}') {
				if (opening.empty()) is_match = false;
				else {
					char match;
					match = opening.top();
					opening.pop();
					is_match = (match == '{'&&symbol == '}') || (match == '['&&symbol == ']') || (match == '('&&symbol == ')');
				}
			}
		}
		if (opening.empty() && flag == 0 && is_match == true) cout << "True\n";
		else {
			while (!opening.empty()) opening.pop();
			cout << "False\n";
			flag = 0;
		}
		is_match = true;
	}
}                                 
