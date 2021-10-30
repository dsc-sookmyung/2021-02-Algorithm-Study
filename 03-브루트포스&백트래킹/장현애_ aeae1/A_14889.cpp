#include <iostream>
#define MAX 21
using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int arr[MAX][MAX];
bool issued[MAX];
int n, count = 0, answer = 1000000000;

void select(int count, int next) {

	if (count >= n / 2) {

		int start = 0, link = 0;

		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				if (issued[i] && issued[j]) start += arr[i][j];
				if (!issued[i] && !issued[j]) link += arr[i][j];
			}
		}
		answer = (answer > abs(start - link)) ? abs(start - link) : answer;

		return;
	}

	for (int i = next; i < n; i++) {
		issued[i] = true;
		select(count + 1, i + 1);
		issued[i] = false;
	}
}

int main()
{
	init();

	cin >> n;

	for (int i = 1; i < n+1; i++) {
		for (int j = 1; j < n + 1; j++) {
			cin >> arr[i][j];
		}
	}

	select(0, 1);

	cout << answer;

	return 0;
}