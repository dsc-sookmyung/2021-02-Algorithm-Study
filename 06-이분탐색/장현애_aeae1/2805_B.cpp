#include <iostream>
#include <vector>

using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main()
{
	init();

	int N, M, H = 0, input, count;
	int mid, l = 1, r = 1;
	vector<int> trees;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> input;
		trees.push_back(input);
		if (input > r) r = input;
	}

	while (l <= r) {
		count = 0;
		mid = (l + r) / 2;
		
		for (int tree : trees) {
			if (tree > mid)
				count += (tree - mid);
		}

		if (count >= M) {
			if (H < mid) H = mid;
			l = mid + 1;
		} 
		else r = mid - 1;
	}

	cout << H << "\n";
	return 0;
}