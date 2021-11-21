#include <iostream>
#include <algorithm>

using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main()
{
	init();

	int N, C, d, result = -1;
	int houses[200000];

	cin >> N >> C;

	for (int i = 0; i < N; i++)
		cin >> houses[i];

	sort(houses, houses + N);

	int l = 1 , r = houses[N-1] - houses[0], mid;

	while (l <= r) {
		int cnt = 1, start = 0;

		mid = (l + r) / 2;
		for (int i = 1; i < N; i++) {
			d = houses[i] - houses[start];
			if (d >= mid) {
				cnt++;
				start = i;
			}
		}

		if (cnt >= C) {
			result = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	cout << result << "\n";
	return 0;
}