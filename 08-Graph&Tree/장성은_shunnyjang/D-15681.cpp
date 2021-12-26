#include <iostream>
#include <vector>

using namespace std;

int N, R, Q, u, v;

int subtree[100001];
bool visited[100001];
vector<int> tree[100001];

int countSubtree(int cur)
{
    bool check = false;
    int sum = 0;

    for (int i = 0; i < tree[cur].size(); i++)
    {
        int next = tree[cur][i];
        if (!visited[next])
        {
            visited[next] = 1;
            sum += countSubtree(next);
            check = true;
        }
    }

    if (!check)
        return 1;

    subtree[cur] = sum;
    return subtree[cur] + 1;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> R >> Q;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    visited[R] = 1;
    countSubtree(R);

    for (int i = 0, x; i < Q; i++)
    {
        cin >> x;
        cout << subtree[x] + 1 << '\n';
    }
    return 0;
}