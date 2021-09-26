#include<iostream>
#include<algorithm>

using namespace std;

int arr[300000];

int main() {
	int n, k;
	cin >> n>>k;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n-1; i++) {
		arr[i] = arr[i + 1] - arr[i];
	}

	sort(arr, arr + n-1);
	int res = 0;
	for (int i = 0; i < n - k; i++) {
		res += arr[i];
	}

	cout << res;

	return 0;
}