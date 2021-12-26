#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;


int r,c;
int field[50][50];

void BFS(int x, int y){

    queue<pair<int,int>> que;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    que.push(make_pair(x,y));    

    field[x][y] = 0;

    while(!que.empty()){

        int x = que.front().first;
        int y = que.front().second;

        que.pop();

        for (int i=0; i<4; ++i){

            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0<=nx && nx<r && 0<=ny && ny<c){

                if (field[nx][ny]==1){

                    field[nx][ny] = 0;
                    que.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test, x,y, count;

    cin >> test;

    for (int i=0 ; i<test; ++i){
        cin >> r >> c >> count;
        for (int i=0; i<count; ++i){
            cin >> x >> y;
            field[x][y] = 1;
        }

        int worm(0);
        for (int i=0; i<r; ++i){
            for (int j=0; j<c; ++j){
                if (field[i][j]==1){
                    BFS(i,j);
                    worm++;
                }
            }
        }

        cout << worm << endl;
    }

    return 0;
}