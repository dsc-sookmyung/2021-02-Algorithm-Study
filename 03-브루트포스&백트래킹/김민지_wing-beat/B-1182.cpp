#include <iostream>
using namespace std;

int arr[21];
int N, S, cnt=0;

void backTracking(int start, int sum) {
	if (start >= N) return;
	int tmp = sum;
	tmp += arr[start];
	if (tmp == S) cnt++;
	for (int i=start+1; i<N; i++){
		backTracking(i, tmp);
	}
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
    
	int tmp;
	cin >> N >> S; 
	for (int i=0; i<N; i++){
	    cin >> arr[i];
	}
	for (int i=0; i<N; i++) {
		tmp = 0;
		backTracking(i, tmp);
	}
    cout << cnt;
}