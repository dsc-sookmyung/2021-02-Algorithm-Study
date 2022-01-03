#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, input;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    priority_queue<int, vector<int>, greater<int> > pq;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> input;
            pq.push(input);
            if (pq.size() > n)
                pq.pop();
        }
    }

    cout << pq.top();
    return 0;
}
