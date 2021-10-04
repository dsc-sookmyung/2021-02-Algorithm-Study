#include<iostream>
#include<algorithm>

using namespace std;

bool cmp(int a, int b) {
	if (a > b)
		return a > b;
	return b < a;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n;
	cin >> n;

	int arr[1000001];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n, cmp);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}
}