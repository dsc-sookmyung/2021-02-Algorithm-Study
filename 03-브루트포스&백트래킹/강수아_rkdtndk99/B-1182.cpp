#include <iostream>

using namespace std;

int arr[20];
int n, s;
int cnt = 0;

void init_arr(int input) {
	for (int i = 0; i < input; i++) {
		arr[i] = 0;
	}
}

void dfs(int sum, int input) {
	
	if (sum == s and input !=0) {
		cnt++;
	}

	if (input == n) return;

	for (int i = input; i < n; i++) {
		dfs(sum + arr[i], i + 1);
	}
}

int main(void) {
	cin >> n >> s;
	init_arr(n);
	

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dfs(0, 0);
	cout << cnt << endl;
}
