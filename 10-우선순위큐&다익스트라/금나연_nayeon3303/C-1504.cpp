#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define INF 987654321

using namespace std;

int N, E, v1, v2, res = INF;
int sv1, sv2, v1v2, v1n, v2n;
vector<pair<int, int>> v[801];
int dist[801];


void dijkstra(int s)
{
	for (int i = 0; i <= N; i++) dist[i] = INF;
	dist[s] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({0, s});

	while (!q.empty()) {
        int cost = q.top().first;
		int cur = q.top().second;
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int nc = v[cur][i].second;

			if (dist[next] > cost + nc) {
				dist[next] = cost + nc;
				q.push({dist[next], next});
			}
		}
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> N >> E;
	while (E--) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({b, c});
		v[b].push_back({a, c});
	}
	cin >> v1 >> v2;

	dijkstra(1);
	sv1 = dist[v1];
	sv2 = dist[v2];

	dijkstra(v1);
	v1v2 = dist[v2];
	v1n = dist[N];

	dijkstra(v2);
	v2n = dist[N];


	res = min(res, sv1 + v1v2 + v2n);
	res = min(res, sv2 + v1v2 + v1n);

	if (v1v2 == INF || res == INF) cout << -1;
	else cout << res;

    return 0;
}