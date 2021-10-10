#include <deque>
#include <iostream>

using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main()
{
	init();

	deque<pair<int,int>> q;
	int n, input, count = 1;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input;
		pair<int, int> p = make_pair(i+1, input);
		q.push_back(p);
	}

	while (true) {
		cout << q.front().first << " ";

		int num = q.front().second;
		q.pop_front();

		if (q.empty()) break;
		
		if (num < 0) {
			while (num++ < 0) {
				q.push_front(q.back());
				q.pop_back();
			}
		}
		else {
			num--;
			while (num-- > 0) {
				q.push_back(q.front());
				q.pop_front();
			}
		}
	}

	return 0;
}