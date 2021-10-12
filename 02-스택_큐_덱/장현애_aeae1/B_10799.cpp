#include <stack>
#include <iostream>

using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}
int main()
{
	stack<char> s;
	string answer;
	int result = 0;

	init();

	cin >> answer;

	for (int i = 0; i < answer.length(); i++) {
		if (answer.at(i) == ')') {
			if (answer.at(i - 1) == ')') {
				s.pop();
				result++;
			}
			else {
				s.pop();
				result += s.size();
			}
		}
		else {
				s.push(answer.at(i));
		}
	}
	cout << result;
}