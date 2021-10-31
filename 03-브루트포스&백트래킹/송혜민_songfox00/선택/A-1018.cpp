#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int n, m, ans = 1e9;
	int num1, num2;
	cin >> n >> m;
	char map[51][51];

	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			cin >> map[i][j];
		}
	}

	for (int a = 0; a <= n - 8; a++) {
		for (int b = 0; b <= m - 8; b++) {
			num1 = 0, num2 = 0;
			for (int i = a; i<a + 8; i++) {
				for (int j = b; j<b + 8; j++) {
					if (map[i][j] == 'W') {
						if ((i + j) % 2 == 0)
							num1++;
						else num2++;
					}
					else {
						if ((i + j) % 2 == 0)
							num2++;
						else num1++;
					}
				}
			}
			ans = min({ ans, num1, num2 });
		}
	}
	cout << ans;
}