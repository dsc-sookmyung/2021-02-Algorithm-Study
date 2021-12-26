#include <iostream>
#include <vector>
#include <queue>


const int MAX = 1001;
using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int box[MAX][MAX];
int M, N, answer = 0;

queue<pair<int, int>> q;

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (box[nx][ny] == 0) {
					box[nx][ny] = box[x][y] + 1;
					q.push({ nx, ny });
				}
			}
		}
	}
}

int main() {
	cin >> M >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) {
				q.push({ i, j });
			}
		}

	bfs();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (box[i][j] == 0) {
				cout << "-1\n";
				return 0;
			}

			if (answer < box[i][j]) answer = box[i][j];
		}
	}
	cout << answer - 1 << "\n";
	return 0;
}