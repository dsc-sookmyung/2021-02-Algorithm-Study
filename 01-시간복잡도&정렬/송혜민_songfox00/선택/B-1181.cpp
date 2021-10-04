#include <iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

vector<string>v;

bool cmp(string a, string b) {
	if (a.size() == b.size())
		return a < b;
	return a.size()<b.size();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}

	sort(v.begin(), v.end(), cmp);

	string word;
	for (int i = 0; i < n; i++) {
		if (word == v[i])
			continue;
		cout << v[i]<<'\n';
		word = v[i];
	}
}


