#include <iostream>
#include <algorithm>

using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int N, M, temp, result;
int A[100000], B[100000];

int main()
{
	init();

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	sort(A, A + N);

	cin >> M;
	for (int i = 0; i < M; i++)
		cin >> B[i];

	for (int i = 0; i < M; i++) {
		int l = 0, r = N - 1, mid;
		result = 0;
		
		while (l <= r) {
			mid = (l + r) / 2;
			if (B[i] == A[mid]) {
				result = 1;
				break;
			}
			else if (B[i] < A[mid]) r = mid - 1;
			else if (B[i] > A[mid]) l = mid + 1;
		}

		cout << result << "\n";
	}
}