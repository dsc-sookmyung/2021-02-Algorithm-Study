#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, a;
	cin >> n;
	vector<pair<int,int>>v;

	for (int i = 1; i <= n; i++) {
		cin >> a;
		v.push_back({a,i});
	}
	
	int pos = 0;
	while (true) {
		cout << v[pos].second << ' ';
		int nxt = v[pos].first;
		v.erase(v.begin() + pos);

		if (v.empty())
			break;
		if(nxt>0)
			pos = (pos + nxt - 1) % v.size();
		else {
			pos += nxt;
			while (pos < 0)
				pos += v.size();
		}
	}
	return 0;
}