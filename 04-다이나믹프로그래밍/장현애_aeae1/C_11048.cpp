#include <iostream>
#include <algorithm>

#define MAX 1001
using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int N, M;
int arr[MAX][MAX];
int dp[MAX][MAX];

int main()
{
	init();

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> arr[i][j];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = arr[i][j] + max({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
		}
	}

	cout << dp[N][M];

}