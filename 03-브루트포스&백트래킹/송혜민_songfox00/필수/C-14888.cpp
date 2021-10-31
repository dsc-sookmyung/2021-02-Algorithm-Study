#include<iostream>
#include<algorithm>

using namespace std;

int n;
int arr[12];
int operand[4];
int MAX = -1000000000, MIN = 1000000000;
int visited[4] = { 0,0,0,0 };

void dfs(int i, int res, int plus, int minus, int mul, int div) {
	if (i == n) {
		MAX = max(MAX, res);
		MIN = min(MIN, res);
		return;
	}

	if (plus > 0)
		dfs(i+1, res + arr[i], plus-1, minus, mul, div);
	if (minus > 0)
		dfs(i + 1, res - arr[i], plus, minus-1, mul, div);
	if (mul > 0)
		dfs(i + 1, res * arr[i], plus, minus, mul-1, div);
	if (div > 0)
		dfs(i + 1, res / arr[i], plus, minus, mul, div-1);
}

int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> operand[i];
	}

	dfs(1, arr[0], operand[0], operand[1], operand[2], operand[3]);

	cout << MAX << '\n' << MIN;
	return 0;
}