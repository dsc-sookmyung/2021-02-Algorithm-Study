#include <queue>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

vector<int> tree[50];
int dist[50];

int main(void) {
    cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n, root;
	cin >> n;
	memset(dist, -1, sizeof(dist));
	queue<int> q;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x == -1) {
			root = i;
			q.push(i);
			dist[i] = 0;
		}
		else {
			tree[x].push_back(i);
		}
	}

	int m;
	cin >> m;
	if (root == m) {
		cout << 0 << '\n';
		return 0;
	}

	int range = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < tree[i].size(); j++) {
			if (tree[i][j] == m && tree[i].size() == 1) {
				range = i;
			}
		}
	}

	int ans = 0;
	dist[m] = 1e5;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int k = 0; k < tree[x].size(); k++) {
			int y = tree[x][k];
			if (dist[y] != -1) continue;
			dist[y] = dist[x] + 1;
			q.push(y);
		}
	}

	for (int i = 0; i < n; i++) {
		if ((tree[i].size() == 0 && dist[i] != -1 && i != m) || (i == range)) {
			ans += 1;
		}
	}

	cout << ans << '\n';
	return 0;
}
