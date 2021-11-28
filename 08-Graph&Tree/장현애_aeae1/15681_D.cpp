#include<iostream>
#include<vector>
using namespace std;

int dp[100001];
bool visited[100001];
vector<int> v[100001];
bool isleaf;
int N, R, Q;

void dfs(int node, int parent)
{
    visited[node] = true;
    for (int i = 0; i < v[node].size(); i++)
    {
        int next = v[node][i];
        if (visited[next])
            continue;
        dfs(next, node);
    }
    if (parent != -1)
    {
        dp[parent] += dp[node];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fill_n(dp, 100001, 1);
    cin >> N >> R >> Q;
    int a, b;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(R, -1);
    for (int i = 0; i < Q; i++)
    {
        int q;
        cin >> q;
        cout << dp[q] << '\n';
    }
    return 0;
}
