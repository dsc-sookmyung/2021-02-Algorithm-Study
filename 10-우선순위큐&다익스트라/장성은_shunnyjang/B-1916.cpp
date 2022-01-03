#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321

int n, m, start, dest;
vector<pair<int, int> > vec[10001];
int d[1001];

void dijkstra()
{
    priority_queue<pair<int, int> > pq;
    d[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty())
    {
        int current = pq.top().second;
        int c_dist = -pq.top().first;
        pq.pop();

        if (d[current] < c_dist)
            continue;

        for (int i = 0; i < vec[current].size(); i++)
        {
            int next = vec[current][i].first;
            int n_dist = vec[current][i].second + c_dist;
            if (n_dist < d[next])
            {
                d[next] = n_dist;
                pq.push(make_pair(-n_dist, next));
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        d[i] = INF;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        vec[u].push_back(make_pair(v, w));
    }

    cin >> start >> dest;
    dijkstra();

    cout << d[dest];

    return 0;
}
