#include <iostream>
#include <vector>
#include <queue>

#define VEC 300001
#define MAX 100000000

using namespace std;

int V, E, K;
int dis[VEC];
vector<pair<int, int>> adj[VEC];

void dijkstra(int S) {
	fill(dis, dis + VEC, MAX);
	priority_queue<pair<int, int>> pq;
	
	dis[S] = 0;
	pq.push({ 0, S });
	
	while (!pq.empty()) {
		int d = -pq.top().first;
		int u = pq.top().second;
		pq.pop();

		if (d > dis[u]) continue;
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].first;
			int c = adj[u][i].second;
			if (dis[v] > d + c) {
				dis[v] = d + c;
				pq.push(make_pair(-dis[v], v));
			}
		}
	}
}

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
}

int main() {

	cin >> V >> E >> K;

	for (int i = 0; i < E; i++) {
		int u, v, w;

		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
	}

	dijkstra(K);

	for (int i = 1; i < V+1; i++) {
		if (dis[i] == MAX) {
			cout << "INF" << "\n";
		}
		else
		{
			cout << dis[i] << "\n";
		}
	}

	return 0;
}