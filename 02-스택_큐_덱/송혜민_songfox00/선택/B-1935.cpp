#include<iostream>
#include<string>
#include<stack>

using namespace std;

string str;
double num[26];

int main() {
	cout << fixed;
	cout.precision(2);

	int n;
	cin >> n;
	cin >> str;

	for (int i = 0; i < n; i++)
		cin >> num[i];
	stack<double>s;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-') {
			double a = s.top();
			s.pop();
			double b = s.top();
			s.pop();
			if (str[i] == '*')
				s.push((1.0)*b*a);
			else if (str[i] == '/')
				s.push((1.0)*b / a);
			else if (str[i] == '+')
				s.push(a + b);
			else if (str[i] == '-')
				s.push(b - a);
		}
		else
			s.push(num[str[i] - 'A']);
	}
	cout << s.top();
}