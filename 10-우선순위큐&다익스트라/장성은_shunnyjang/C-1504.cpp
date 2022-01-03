#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>

#define MAX 801
#define INF 987654321

using namespace std;
typedef pair<int, int> P;

int n, e, v1, v2, answer;
vector<pair<int, int> > adj[MAX];
priority_queue<P, vector<P>, greater<P> > pq;

int dijkstra(int start, int end)
{
    vector<int> d(n + 1, INF);
    d[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty())
    {
        int current = pq.top().second;
        int c_dist = pq.top().first;
        pq.pop();

        for (int i = 0; i < adj[current].size(); i++)
        {
            int next = adj[current][i].first;
            int n_dist = c_dist + adj[current][i].second;

            if (d[next] > n_dist)
            {
                d[next] = n_dist;
                pq.push(make_pair(n_dist, next));
            }
        }
    }
    return d.at(end);
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    bool check1 = true;
    bool check2 = true;

    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    cin >> v1 >> v2;

    int a1 = dijkstra(1, v1);
    int a2 = dijkstra(v1, v2);
    int a3 = dijkstra(v2, n);

    if (a1 == INF || a2 == INF || a3 == INF)
        check1 = false;

    int b1 = dijkstra(1, v2);
    int b2 = dijkstra(v2, v1);
    int b3 = dijkstra(v1, n);

    if (v1 == INF || b2 == INF || b3 == INF)
        check2 = false;

    if (check1 && check2)
    {
        int case1 = a1 + a2 + a3;
        int case2 = b1 + b2 + b3;
        answer = min(case1, case2);
    }
    else
    {
        answer = -1;
    }

    cout << answer;

    return 0;
}
