#include <iostream>
#define MAX 1000000000
using namespace std;

int n;
int maxResult = -MAX, minResult = MAX;
int oper[4];		// 0: +, 1: -, 2: x, 3: /
int num[11];

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

void calc(int sum, int index) {
	if (index == n) {
		if (maxResult < sum) maxResult = sum;
		if (minResult > sum) minResult = sum;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (oper[i] > 0) {
			oper[i]--;
			switch (i) {
			case 0:
				calc(sum + num[index], index + 1);
				break;
			case 1:
				calc(sum - num[index], index + 1);
				break;
			case 2:
				calc(sum * num[index], index + 1);
				break;
			case 3:
				calc(sum / num[index], index + 1);
				break;
			}
			oper[i]++;
		}
	}

	return;
}

int main()
{
	init();

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	}

	calc(num[0], 1);

	cout << maxResult << "\n";
	cout << minResult << "\n";

	return 0;
}