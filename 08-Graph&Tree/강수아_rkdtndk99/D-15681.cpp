#include <bits/stdc++.h>

using namespace std;

int N, R, Q, l[100005], r[100005], num;
vector<int> vt[100005];

void go(int n) {
	l[n] = ++num;
	for (int nn : vt[n]) {
		if (l[nn] == 0) {
			go(nn);
		}
	}
	r[n] = num;
}

int main() {
    cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
    
	cin >> N >> R >> Q;
	for (int i = 1, a, b; i < N; ++i) {
		cin >> a >> b;
		vt[a].push_back(b);
		vt[b].push_back(a);
	}
	go(R);
	while (Q--) {
		int a;
		cin >> a;
		cout << r[a] - l[a] + 1 << "\n";
	}
}
