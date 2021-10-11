#include<iostream>
#include<queue>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	queue<int>q;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	
	int cnt = 0;
	cout << "<";

	while (q.size()>1) {
		cnt++;
		if (cnt%k == 0)
			cout << q.front() << ", ";
		else
			q.push(q.front());
		q.pop();
	}
	
	cout << q.front() << ">";
	return 0;
}