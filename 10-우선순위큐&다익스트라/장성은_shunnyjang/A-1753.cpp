#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

#define MAX 20010
#define INF 987654321

int v, e, start;
vector<pair<int, int> > a[MAX];
int d[MAX];

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

        for (int i = 0; i < a[current].size(); i++)
        {
            int next = a[current][i].first;
            int n_dist = a[current][i].second;
            if (n_dist + c_dist < d[next])
            {
                d[next] = n_dist + c_dist;
                pq.push(make_pair(-d[next], next));
            }
        }
    }

    for (int i = 1; i <= v; i++)
    {
        if (d[i] == INF)
            cout << "INF" << '\n';
        else
            cout << d[i] << '\n';
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> v >> e >> start;
    for (int i = 1; i <= v; i++)
        d[i] = INF;

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back(make_pair(v, w));
    }

    dijkstra();

    return 0;
}
