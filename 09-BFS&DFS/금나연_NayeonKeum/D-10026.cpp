#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
 
int N;
char map[100][100];
bool visited[100][100];
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
 

void BFS(int a, int b)
{
    queue <pair<int, int>> que;
    que.push(make_pair(a, b));
    visited[a][b] = true;
 
    while (que.empty() == 0)
    {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
 
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && ny >= 0 && nx < N && ny < N)
            {
                if (visited[nx][ny] == false)
                {
                    if (map[nx][ny] == map[x][y])
                    {
                        visited[nx][ny] = true;
                        que.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }

    int result1, result2;
    result1 = result2 = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (visited[i][j] == false){
                BFS(i, j);
                result1++;
            }
        }
    }
 
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (map[i][j] == 'G') map[i][j] = 'R';
        }
    }
 
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (visited[i][j] == false){
                BFS(i, j);
                result2++;
            }
        }
    }
 
    cout << result1 << " " << result2 << "\n";

    return 0;
}