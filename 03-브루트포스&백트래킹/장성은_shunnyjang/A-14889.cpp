#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> combis;

void combination(string combi, int N, int M, int target)
{
    if (combi.size() == M)
    {
        combis.push_back(combi);
        return;
    }
    else if (target == N)
    {
        return;
    }
    else
    {
        combination(combi, N, M, target + 1); //target이 뽑히지 않는 경우
        combi += (target + '0');
        combination(combi, N, M, target + 1); //target이 뽑히는 경우
    }
}

void solve(const vector<vector<int> > &stats)
{
    int size = combis.size();
    int min = 2147483647;

    int n = combis[0].size();

    for (int i = 0; i < size / 2; i++)
    {
        int team_a = 0;
        int team_b = 0;

        for (int j = 0; j < n; j++)
        {
            int a_player1 = combis[i][j] - '0';
            int b_player1 = combis[size - i - 1][j] - '0';

            for (int k = 0; k < n; k++)
            {
                if (k == j)
                    continue;
                int a_player2 = combis[i][k] - '0';
                int b_player2 = combis[size - i - 1][k] - '0';

                team_a += stats[a_player1][a_player2];
                team_b += stats[b_player1][b_player2];
            }
        }
        if (min > abs(team_a - team_b))
            min = abs(team_a - team_b);
    }

    cout << min;
}

int main()
{
    int N;
    cin >> N;
    vector<vector<int> > stats(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> stats[i][j];

    combination("", N, N / 2, 0);
    solve(stats);
}