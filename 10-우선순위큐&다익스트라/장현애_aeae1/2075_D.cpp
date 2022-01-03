#include <iostream>
#include <queue>

using namespace std;

int N, num;
priority_queue<long long> q;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num;
			q.push(-num);
			if (q.size() > N) q.pop();
		}
	}

	cout << -q.top();
	return 0;
}