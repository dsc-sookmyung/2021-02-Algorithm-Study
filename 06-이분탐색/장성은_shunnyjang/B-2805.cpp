#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    long long start = 0, end = 0, mid;
    vector<int> tree;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int height;
        cin >> height;
        tree.push_back(height);
        if (tree[i] > end)
            end = tree[i];
    }

    long long sum = 0, answer = 0;
    while (start <= end)
    {
        mid = (start + end) / 2;
        sum = 0;
        for (int i = 0; i < n; i++)
            if (tree[i] > mid)
                sum += tree[i] - mid;

        if (sum >= m)
        {
            start = mid + 1;
            if (answer < mid)
                answer = mid;
        }
        else
            end = mid - 1;
    }

    cout << answer << endl;
    return 0;
}
