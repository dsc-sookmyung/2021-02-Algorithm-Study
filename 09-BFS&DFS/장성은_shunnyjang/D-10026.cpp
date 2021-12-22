#include <iostream>
#include <string.h>

using namespace std;

int n, count = 0;
char array[101][101];
bool visited[101][101];

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

void dfs(int y, int x)
{
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n)
            continue;

        if (array[ny][nx] == array[y][x] && !visited[ny][nx])
        {
            visited[ny][nx] = true;
            dfs(ny, nx);
        }
    }
}

void reset()
{
    memset(visited, 0, sizeof(visited));
    count = 0;
}

void colorWeakness()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (array[i][j] == 'G')
                array[i][j] = 'R';
}

int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> array[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!visited[i][j])
            {
                dfs(i, j);
                count++;
            }
    cout << count << ' ';

    reset();
    colorWeakness();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!visited[i][j])
            {
                dfs(i, j);
                count++;
            }
    cout << count;
    return 0;
}
