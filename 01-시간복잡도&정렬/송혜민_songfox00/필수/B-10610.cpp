#include <iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

bool cmp(char a, char b) {
	if (a > b)
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string n;
	cin >> n;

	long long sum = 0;
	bool zero = false;
	for (int i = 0; i< n.size(); i++) {
		sum += (n[i] - '0');

		if (!(n[i] - '0'))	//0ÀÌ ÀÖÀ½
			zero = true;
	}

	if (sum % 3 || !zero)
		cout << -1 << '\n';
	else {
		sort(n.begin(), n.end(), cmp);
		cout << n << '\n';
	}
}


