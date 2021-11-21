#include <iostream>
#include <vector>

using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main()
{
	init();
	int N, K, M, L, P = -1;
	int mid, l = 1, r = 1000000000;
	vector<int> v;

	cin >> N >> K >> M;

	for (int i = 0; i < N; i++) {
		cin >> L;
		if (L <= K) continue;
		else {
			if (L < 2 * K) v.push_back(L - K);
			else v.push_back(L - (2 * K));
		}
	}

	while (l <= r) {
		int count = 0;
		mid = (l + r) / 2;
		
		for (int gb : v) {
			count += (gb / mid);
		}
		if (count >= M) {
			P = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}

	cout << P;
	return 0;
}