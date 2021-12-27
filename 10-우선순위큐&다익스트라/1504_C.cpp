#include <iostream>
#include <vector>
#include <queue>

#define VEC 300001
#define MAX 200000001

using namespace std;

int N, E, K, V1, V2;
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
	bool flag1, flag2;
	flag1 = flag2 = true;

	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		int a, b, c;

		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}

	cin >> V1 >> V2;

	dijkstra(1);
	int result1 = dis[V1];
	int result2 = dis[V2];
	if (dis[V1] == MAX) flag1 = false;
	if (dis[V2] == MAX) flag2 = false;

	dijkstra(V1);
	result1 += dis[V2];
	result2 += dis[V2] + dis[N];
	if (dis[V2] == MAX) flag1 = false, flag2 = false;
	if (dis[N] == MAX) flag2 = false;

	dijkstra(V2);
	result1 += dis[N];
	if (dis[N] == MAX) flag1 = false;
	
	int answer;
	if (result1 < result2) {
		answer = result1;
	}
	else {
		answer = result2;
	}
	
	if (!flag1 && !flag2) answer = -1;

	cout << answer << "";
	return 0;

}