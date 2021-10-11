#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main() {
	int n, a;
	cin >> n;

	stack<int>s;

	while (n--) {
		string str;
		cin >> str;

		if (str == "push") {
			cin >> a;
			s.push(a);
		}
		else if (str == "top") {
			if (s.empty())
				cout << -1 << "\n";
			else
				cout << s.top() << '\n';
		}
		else if (str == "size")
			cout << s.size() << '\n';
		else if (str == "empty") {
			if (s.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else {
			if (!s.empty()) {
				cout << s.top() << '\n';
				s.pop();
			}
			else
				cout << -1 << '\n';
		}
	}
}