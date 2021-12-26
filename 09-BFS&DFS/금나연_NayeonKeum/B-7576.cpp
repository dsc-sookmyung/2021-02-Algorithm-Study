#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int M, N;

int map[1001][1001];
bool visited[1001][1001];
int path[1001][1001];

int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

queue<pair<int,int>> que;

void BFS() {
    while (!que.empty()) {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();
 
        for (int i=0; i<4; i++) {
            int ny=y+dy[i];
            int nx=x+dx[i];
 
            if (ny<0 || nx<0 || ny>=N || nx>=M)
                continue;
            if (map[ny][nx]==0 && visited[ny][nx]==0) {
                visited[ny][nx]=true;
                que.push(make_pair(ny, nx));
                path[ny][nx]= path[y][x]+1;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;
 
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin>>map[i][j];
        }
    }
 
    for (int i = 0; i < N; i++) {
        for (int j=0; j<M; j++) {
            if (map[i][j] == 1) {
                que.push(make_pair(i, j));
            }
        }
    }
    BFS();

    for (int i = 0; i < N; i++) {
        for (int j=0; j<M; j++) {
            if (map[i][j]==0 && path[i][j]==0) { 
                cout << -1;
                return 0;
            }
        }
    }
 
    int ans = -1;
    for (int i = 0; i < N; i++) {
        for (int j=0; j<M; j++) {
            if (path[i][j] > ans) {
                ans = path[i][j];
            }
        }
    }
    cout << ans;
    return 0;
}