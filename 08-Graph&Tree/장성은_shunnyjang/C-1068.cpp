#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > tree(51);
int erase, answer;
int N, parent, root;

void search(int node)
{
    int child = 0;
    int size = tree[node].size();
    for (int i = 0; i < size; i++)
    {
        int x = tree[node][i];
        if (x == erase)
            continue;
        search(x);
        child++;
    }
    if (!child)
        answer++;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> parent;
        if (parent == -1)
        {
            root = i;
            continue;
        }
        tree[parent].push_back(i);
    }
    cin >> erase;
    if (root == erase)
        cout << "0";
    else
    {
        search(root);
        cout << answer;
    }
}
