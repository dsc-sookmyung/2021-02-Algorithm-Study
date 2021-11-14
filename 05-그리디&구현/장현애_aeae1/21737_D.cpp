#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main() {
	init();

	int N, result = 0;
	string S, temp;
	char oper = '+';
	bool isC = false;

	cin >> N >> S;
	
	for (int i = 0; i < S.length(); i++) {
		if (S[i] >= '0' && S[i] <= '9')
			temp += S[i];
		else {
			switch (oper) {
			case '+':
				result += stoi(temp);
				break;
			case '-':
				result -= stoi(temp);
				break;
			case '*':
				result *= stoi(temp);
				break;
			case '/':
				result /= stoi(temp);
				break;
			}
			temp = "0";

			if (S[i] == 'P') oper = '+';
			else if (S[i] == 'M') oper = '*';
			else if (S[i] == 'S') oper = '-';
			else if (S[i] == 'U') oper = '/';
			else {
				isC = true;
				oper = '+';
				cout << result << " ";
			}
		}
	}

	if (!isC) cout << "NO OUTPUT";
}
