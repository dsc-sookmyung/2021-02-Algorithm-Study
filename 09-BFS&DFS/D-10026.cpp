#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int n;

void BFS(int row, int col, vector<vector<char>> &graph, int seq) {
    char color = graph[row][col];
    queue<pair<int, int>> q;
    q.push({row, col});
    graph[row][col] = 'O';
    
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
        for (int i=0; i<4; i++) {
            int next_r = r + dir[i][0];
            int next_c = c + dir[i][1];
            if (seq == 0 || color=='B') {
                if (next_r >= 0 && next_r < n && next_c >= 0 && next_c < n && graph[next_r][next_c] == color) {
                    q.push({next_r,next_c});
                    graph[next_r][next_c] = 'O';
                }
            }
            else {
                if (next_r >= 0 && next_r < n && next_c >= 0 && next_c < n && (graph[next_r][next_c] == 'R'|| graph[next_r][next_c] == 'G')) {
                    q.push({ next_r,next_c });
                    graph[next_r][next_c] = 'O';
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    vector<vector<char>> graph(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    int count;
    for (int seq = 0; seq < 2; seq++) { 
        vector<vector<char>> graph_copy(graph);
        count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph_copy[i][j] != 'O') {
                    BFS(i, j, graph_copy, seq);
                    count++;
                }
            }            
        }
        cout << count << ' ';
    }
}
