#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

const int MAX = 1001;
using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

bool dfs_visited[MAX];
bool bfs_visited[MAX];

vector<int> adj[MAX];

int N, M, V;

void dfs(int u) {
	dfs_visited[u] = true;
	cout << u << " ";
	
	sort(adj[u].begin(), adj[u].end());

	for (int v : adj[u]) {
		if (!dfs_visited[v]) {
			dfs(v);
		}
	}
}

void bfs(int root) {
	queue<int> q;
	q.push(root);
	bfs_visited[root] = true;
	
	while (!q.empty()) {
		int u = q.front(); q.pop();
		sort(adj[u].begin(), adj[u].end());

		for (int v : adj[u]) {
			if (!bfs_visited[v]) {
				bfs_visited[v] = true;
				q.push(v);
			}
		}
		cout << u << " ";
	}

}

int main() {

	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int p1, p2;

		cin >> p1 >> p2;
		adj[p1].push_back(p2);
		adj[p2].push_back(p1);
	}

	dfs(V);

	cout << "\n";

	bfs(V);
}