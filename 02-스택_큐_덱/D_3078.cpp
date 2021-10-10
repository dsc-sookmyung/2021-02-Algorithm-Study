#include <queue>
#include <iostream>

using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main()
{
	init();
	
	queue<int> q[21];
	int n = 0, k = 0;
	long long count = 0;
	string name;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> name;

		int leng = name.length();
		while (!q[leng].empty()) {
			int front = q[leng].front();

			if (i - front <= k) {
				count += q[leng].size();
				break;
			}
			else q[leng].pop();
		}

		q[leng].push(i);
	}

	cout << count;
	return 0;
}