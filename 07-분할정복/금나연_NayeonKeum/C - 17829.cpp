#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int p[1024][1024];
int N, sum;

int solve(int y, int x)
{
    vector<int>a;
    for (int i = x; i < x + 2; i++)
        for (int j = y; j < y + 2; j++)
            a.push_back(p[i][j]);
    sort(a.begin(), a.end());
    return a[2];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> p[i][j];
        }
    }
    while (N > 1)
    {
        for (int i = 0; i < N; i+=2)
            for (int j = 0; j < N; j+=2)
                p[i/2][j/2] = solve(j, i);
        N /= 2;
    }
    cout << p[0][0] << '\n';

    return 0;
}