#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int arr[21][21];
int n;
bool visit[22];
int res = 1000000000;

void dfs(int x, int cnt) {
	if (x == n / 2) {
		int s = 0, l = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (visit[i] && visit[j])
					s += arr[i][j];
				if (!visit[i] && !visit[j])
					l += arr[i][j];
			}
		}
		res = min(res, abs(s - l));
		return;
	}
	for (int i = cnt; i < n; i++) {
		visit[i] = true;
		dfs(x + 1, i + 1);
		visit[i]=false;
	}
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	dfs(0, 1);

	cout << res;
	return 0;
}