#include <iostream>
#include <queue>

#define VEC 100001
#define MAX 9876543210

using namespace std;

int N, M;
int dis[VEC];
vector<pair<int, int>> adj[VEC];

void dijkstra(int S) {
	fill(dis, dis + VEC, MAX);
	priority_queue<pair<int, int>> pq;

	dis[S] = 0;
	pq.push({ 0,S });

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
	int start, end;

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int bus_start, bus_end, bus_cost;
		cin >> bus_start >> bus_end >> bus_cost;
		adj[bus_start].push_back(make_pair(bus_end, bus_cost));
	}

	cin >> start >> end;

	dijkstra(start);

	int answer = dis[end];
	cout << answer;

	return 0;
}