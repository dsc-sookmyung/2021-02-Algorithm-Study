#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int N;
	cin >> N;

    int arr[1024][1024];
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> arr[i][j];
		}
	}

	while (N != 1){
		vector<vector<int>> temp(N/2, vector<int>(N/2, 0));
		for (int y = 0; y < N; y += 2){
			for (int x = 0; x < N; x += 2){
				int tempY = y;
				int tempX = x;
				
				vector<int> v(4);
				v[0] = arr[tempY][tempX];
				v[1] = arr[tempY+1][tempX];
				v[2] = arr[tempY][tempX+1];
				v[3] = arr[tempY+1][tempX+1];
				sort(v.begin(), v.end());
				temp[y/2][x/2] = v[2];
			}
		}
		N /= 2;

		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				arr[i][j] = temp[i][j];
			}
		}
	}
	cout << arr[0][0];
}