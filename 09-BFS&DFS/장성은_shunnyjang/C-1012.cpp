#include <iostream>
#include <string.h>

using namespace std;

int n, m, k;
int array[51][51] = {0};
bool visited[51][51];

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

void dfs(int y, int x)
{
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m)
            continue;

        if (array[ny][nx] && !visited[ny][nx])
        {
            visited[ny][nx] = true;
            dfs(ny, nx);
        }
    }
}

void reset()
{
    memset(array, 0, sizeof(array));
    memset(visited, 0, sizeof(visited));
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        reset();

        cin >> n >> m >> k;
        for (int i = 0; i < k; i++)
        {
            int y, x;
            cin >> y >> x;
            array[y][x] = 1;
        }

        int answer = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (array[i][j] && !visited[i][j])
                {
                    answer++;
                    visited[i][j] = true;
                    dfs(i, j);
                }
        cout << answer << '\n';
    }

    return 0;
}
