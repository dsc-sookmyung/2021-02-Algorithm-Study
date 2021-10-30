#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1001
using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

vector <int> v;
vector <int> DP;

int main()
{
	int N;
	init();

	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	DP.push_back(1);
	for (int i = 1; i < N; i++) {
		DP.push_back(1);
		for (int j = i; j >= 0; j--) {
			if (v[j] < v[i]) DP[i] = max(DP[i], DP[j] + 1);
		}
	}
	sort(DP.begin(), DP.end(), greater<int>());
	cout << DP[0];



}