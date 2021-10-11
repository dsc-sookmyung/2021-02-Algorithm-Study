#include<iostream>
#include<deque>

using namespace std;

deque<int> d[2], g[2];

int n, m, a, b;

int main() {
	cin >> n >> m;

	for (int i = 0; i<n; ++i) {
		cin >> a >> b;
		d[0].push_front(a);
		d[1].push_front(b);
	}

	int idx = 0;
	for (int i = 0; i<m; ++i) {
		g[idx].push_front(d[idx].front());
		d[idx].pop_front();

		if (d[idx].empty()) {
			if(idx)
				cout<<"do";
			else
				cout<<"su";
				
			return 0;
		}

		int check = -1;
		if ((g[0].size() && g[0].front() == 5) || g[1].size() && g[1].front() == 5)
			check = 0;
		else if (g[0].size() && g[1].size() && g[0].front() + g[1].front() == 5)
			check = 1;

		if (check != -1) {
			int l = 1 - check;
			while (g[l].size()) {
				d[check].push_back(g[l].back());
				g[l].pop_back();
			}
			while (g[check].size()) {
				d[check].push_back(g[check].back());
				g[check].pop_back();
			}
		}
		idx = 1 - idx;
	}

	if (d[0].size() > d[1].size()) 
		cout << "do" << '\n';
	else if (d[0].size() < d[1].size()) 
		cout << "su" << '\n';
	else 
		cout << "dosu" << '\n';

	return 0;
}