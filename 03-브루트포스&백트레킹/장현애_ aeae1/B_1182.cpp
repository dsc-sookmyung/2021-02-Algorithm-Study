#include <iostream>

using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int arr[20];
int n, s, result = 0;

void select(int next, int temp) {
	if (next >= n) return;

	if (temp + arr[next] == s) result++;

	select(next + 1, temp);
	select(next + 1, temp + arr[next]);
}

int main()
{
	init();

	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	select(0, 0);

	cout << result;

	return 0;
}