#include <iostream>
#define MAX 11
using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main()
{
	init();
	int T, N;
	int arr[MAX];
	
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int j = 4; j <= N; j++) {
			arr[j] = arr[j - 1] + arr[j - 2] + arr[j - 3];
		}
		cout << arr[N] << "\n";
	}
}