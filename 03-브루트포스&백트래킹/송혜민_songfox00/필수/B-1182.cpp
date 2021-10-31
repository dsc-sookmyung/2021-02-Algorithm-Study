#include<iostream>
#include<vector>

using namespace std;

vector<int>v;
int n, s, a, result=0;

void dfs(int i, int sum) {
	if (i >= n)
		return;
	if (sum+v[i] == s)
		result++;

	dfs(i + 1, sum);
	dfs(i + 1, sum+v[i]);	
}

int main() {
	cin >> n >> s;
	
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}

	dfs(0, 0);

	cout << result;
	return 0;
}