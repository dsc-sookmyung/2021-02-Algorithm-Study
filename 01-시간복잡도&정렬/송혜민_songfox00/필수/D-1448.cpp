#include<iostream>
#include<algorithm>

using namespace std;

int arr[1000001];

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	for (int i = n-1; i >= n-3; i--) {
		if (arr[i] < arr[i -1] + arr[i-2]) {
			cout << arr[i] + arr[i - 1] + arr[i - 2];
			break;
		}
		else if (i == n-3)
			cout << -1;
	}

	return 0;
}