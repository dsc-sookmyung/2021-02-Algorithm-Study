#include <iostream>

using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int arr[129][129];
int N, x, y, blue, white;

void div_conq(int x, int y, int N) {
	int cnt = 0;
	
	for (int i = x; i < x + N; i++) {
		for (int j = y; j < y + N; j++) {
			if (arr[i][j]) {
				cnt++;
			}
		}
	}

	if (!cnt) white++;
	else if (cnt == N * N) blue++;
	else {
		div_conq(x, y, N / 2);
		div_conq(x, y + N / 2, N / 2);
		div_conq(x + N / 2, y, N / 2);
		div_conq(x + N / 2, y + N / 2, N / 2);
	}
	return;
}

int main()
{
	init();

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	div_conq(0, 0, N);

	cout << white << "\n" << blue;
}