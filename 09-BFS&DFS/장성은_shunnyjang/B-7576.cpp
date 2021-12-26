#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int n, m, count;

int farm[1001][1001];
bool visited[1001][1001];
queue<pair<pair<int, int>, int> > location;

void findRipeTomato(int isRipe, int y, int x)
{
    if (isRipe == 1)
    {
        visited[y][x] = true;
        location.push(make_pair(make_pair(y, x), 0));
    }
}

void bfs()
{
    while (!location.empty())
    {
        int y = location.front().first.first;
        int x = location.front().first.second;
        count = location.front().second;
        location.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            if (farm[ny][nx] == 0 && !visited[ny][nx])
            {
                visited[ny][nx] = true;
                location.push(make_pair(make_pair(ny, nx), count + 1));
            }
        }
    }
}

int checkAllTomatoIsRipeAndGetResult()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (farm[i][j] == 0 && !visited[i][j])
                return -1;
    return count;
}

int main(int argc, char const *argv[])
{
    cin >> m >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> farm[i][j];
            findRipeTomato(farm[i][j], i, j);
        }

    bfs();
    cout << checkAllTomatoIsRipeAndGetResult() << '\n';

    return 0;
}
