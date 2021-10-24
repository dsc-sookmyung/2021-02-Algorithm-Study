#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int num;

bool is_possible(const vector<int> &vertical, int curr)
{
    for (int i = 0; i < curr; i++)
    {
        if (abs(vertical[i] - vertical[curr]) == abs(i - curr))
            return false;
        if (vertical[i] == vertical[curr])
            return false;
    }
    return true;
}

void n_queen(int N, vector<int> vertical, int curr)
{
    if (curr == N)
    {
        num++;
        return;
    }

    for (int i = 0; i < N; i++)
    { //현재 y값
        vertical[curr] = i;
        if (!is_possible(vertical, curr))
            continue;
        n_queen(N, vertical, curr + 1);
    }
}

int main()
{
    int N;
    cin >> N;
    num = 0;
    vector<int> vertical(N, -1);

    if (N == 1)
        cout << 1;
    else
    {
        if (N % 2 != 0)
        {
            for (int i = 0; i < N; i++)
            {
                vertical[0] = i;
                n_queen(N, vertical, 1);
            }
        }
        else
        {
            for (int i = 0; i < N / 2; i++)
            {
                vertical[0] = i;
                n_queen(N, vertical, 1);
            }
            num *= 2;
        }

        cout << num << "\n";
    }
}