#include <queue>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int parent[100001];
vector<int> a[100001];

int main(void) {
    cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}

	memset(parent, -1, sizeof(parent));
	queue<int> q;
	q.push(1);
	parent[1] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int y : a[x]) {
			if (parent[y] == -1) {
				parent[y] = x;
				q.push(y);
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}
	return 0;
}
