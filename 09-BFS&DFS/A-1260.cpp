#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int n, m, v; 
vector<vector<int>> graph(1001);
bool checked[1001];

void DFS(int v) {
	if (checked[v]) return;

	checked[v] = true;
	cout << v << " ";
	for (int i = 0; i < graph[v].size(); i++) {
		DFS(graph[v][i]);
	}
}

void BFS(int v){
	queue<int> q;
	checked[v] = true;
	q.push(v);

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << " ";

		for (int i = 0; i < graph[x].size(); i++) {
			if (!checked[graph[x][i]]) {
				checked[graph[x][i]] = true;
				q.push(graph[x][i]);
			}
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	for (int i = 1; i < n + 1; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	DFS(v);
	cout << "\n";

	for (int i = 1; i < n + 1; i++) {
		checked[i] = false;
	}

	BFS(v);
}
