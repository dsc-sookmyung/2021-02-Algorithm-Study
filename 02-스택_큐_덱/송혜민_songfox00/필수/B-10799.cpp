#include<iostream>
#include<string>
#include<stack>

using namespace std;

stack<char> s;

int main() {
	string str;
	cin >> str;

	int res = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			s.push(str[i]);
		}
		else {
			s.pop();
			if (str[i - 1] == '(') {
				res += s.size();
			}
			else {
				res ++;
			}
		}
	}
	cout << res;
}