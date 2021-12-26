#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, v;
bool visited[1001];
vector<int> drum[1001];

void dfs(int u)
{
    cout << u << ' ';
    visited[u] = true;
    for (int i = 0; i < drum[u].size(); i++)
    {
        if (!visited[drum[u][i]])
            dfs(drum[u][i]);
    }
}

void bfs(int v)
{
    queue<int> q;
    q.push(v);
    cout << v << ' ';
    visited[v] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int n : drum[u])
        {
            if (!visited[n])
            {
                visited[n] = true;
                cout << n << ' ';
                q.push(n);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        drum[a].push_back(b);
        drum[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
        sort(drum[i].begin(), drum[i].end());

    dfs(v);
    cout << '\n';

    memset(visited, 0, sizeof(visited));

    bfs(v);
    return 0;
}
