#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > tree(100001);
vector<bool> visited(100001, false);
vector<int> parent(100001, 0);

void findParentNode(int start)
{
    for (int i = 0; i < tree[start].size(); i++)
    {
        int now = tree[start][i];
        if (!visited[now])
        {
            visited[now] = true;
            parent[now] = start;
            findParentNode(now);
        }
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    findParentNode(1);

    for (int i = 2; i <= n; i++)
    {
        printf("%d\n", parent[i]);
    }
    return 0;
}
