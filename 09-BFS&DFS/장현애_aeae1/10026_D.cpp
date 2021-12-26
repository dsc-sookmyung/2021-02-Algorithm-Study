#include <iostream>
#include <cstring>
#define MAX 100
using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

char paint[MAX][MAX];
bool visited[MAX][MAX];

int N, ans_x = 0, ans_o = 0;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
}

void dfs(int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (ny >= 0 && ny < MAX && nx >= 0 && nx < MAX) {
			if (!(visited[nx][ny]) && (paint[x][y] == paint[nx][ny]))
				dfs(nx, ny);
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paint[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				dfs(i, j);
				ans_x++;
			}
		}
	}

	memset(visited, false, sizeof(visited));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (paint[i][j] == 'G') paint[i][j] = 'R';

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				dfs(i, j);
				ans_o++;
			}
		}
	}

	cout << ans_x << " " << ans_o << "\n";
}