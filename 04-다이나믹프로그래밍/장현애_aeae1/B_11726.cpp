#include <iostream>
#define MAX 1001
using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main()
{
	init();
	int N;
	int arr[MAX] = {0};

	arr[1] = 1;
	arr[2] = 2;

	cin >> N;

	for (int i = 3; i <= N; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
	}

	cout << arr[N];

}