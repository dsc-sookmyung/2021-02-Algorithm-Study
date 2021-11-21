#include <iostream>

using namespace std;

int number, answer = 0, x, y, nextX, nextY;
int board[101][101] = { 0 };
int dx[4] = { 0, 0, -1, 1 }; // 위, 아래, 왼쪽, 오른쪽
int dy[4] = { -1, 1, 0, 0 }; // 위, 아래, 왼쪽, 오른쪽

void paste(int x, int y) {
    for (int i=x; i<x+10; i++) {
        for (int j=y; j<y+10; j++) {
            board[i][j] = 1;
        }
    }
}

int main(int argc, const char** argv) {
    cin >> number;
    for (int i=1; i<=number; i++) {
        cin >> x >> y;
        paste(x, y);
    }

    for (int i=1; i<=100; i++) {
        for (int j=1; j<=100; j++) {
            if (board[i][j]==1) {
                for (int k=0; k<4; k++) {
                    nextX=i+dx[k];
                    nextY=j+dy[k];
                    if (board[nextX][nextY]==0)
                        answer++;
                }
            }
        }
    }

    cout << answer << endl;

    return 0;
}
