#include <iostream>
#include <cstring>

using namespace std;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
int map[50][50] = { 0 };
int M, N;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

void dfs(int x, int y) {
	map[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M)
			if (map[nx][ny] == 1) dfs(nx, ny);
	}
}

int main() {
	init();

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int K, answer = 0;
		memset(map, 0, sizeof(map));

		cin >> M >> N >> K;
		for (int j = 0; j < K; j++) {
			int X, Y;
			cin >> X >> Y;
			map[Y][X] = 1;
		}

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (map[j][k] == 1) {
					answer++;
					dfs(j, k);
				}
			}
		}

		cout << answer << "\n";
	}
}