#include <iostream>

using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int arr[101][101];
int N, x, y, cnt = 0;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

int main()
{
	init();

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x;
		cin >> y;
		for (int j = x; j < x + 10; j++) {
			for (int k = y; k < y + 10; k++) {
				arr[j][k] = 1;
			}
		}
	}

	for (int i = 1; i < 101; i++) {
		for (int j = 1; j < 101; j++) {
			if (arr[i][j] == 1) {
				for (int k = 0; k < 4; k++) {
					if (arr[i + dx[k]][j + dy[k]] == 0) cnt++;
				}
			}
		}
	}

	cout << cnt;
}