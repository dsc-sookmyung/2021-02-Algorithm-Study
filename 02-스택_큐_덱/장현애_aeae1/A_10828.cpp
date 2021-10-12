#include <stack>
#include <iostream>

using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}
int main()
{
	stack<int> s;

	init();
	int n, result;
	string comm;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> comm;

		if (comm == "push") {
			int num;
			cin >> num;

			s.push(num);
		}
		else if (comm == "pop") {
			if (s.empty())
				cout << -1 << "\n";
			else {
				cout << s.top() << "\n";
				s.pop();
			}

		}
		else if (comm == "top") {
			if (s.empty())
				cout << -1 << "\n";
			else
				cout << s.top() << "\n";

		}
		else if (comm == "empty") {
			if (s.empty())
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (comm == "size") {
			cout << s.size() << "\n";

		}
	}

	return 0;
}