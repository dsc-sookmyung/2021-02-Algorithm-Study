#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n, m, answer = 0;

vector<long long> v;

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for (long long i = 0; i < n; i++) {
		long long tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	long long l = 0;
	long long r = v[n - 1];

	while (l <= r) {

		long long sum = 0;
		long long mid = (l + r) / 2;
		
		for (int i = 0; i < n; i++) {
			if ((v[i] - mid) > 0)
				sum += (v[i] - mid);
		}

		if (sum < m) {
			r = mid - 1;
		}
		else if (sum >= m) {
			if (answer < mid)
				answer = mid;
			l = mid + 1;
		}
	}
	cout << answer << endl;
	return 0;
}
