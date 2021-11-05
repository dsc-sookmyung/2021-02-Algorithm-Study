#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int N, M;
int dp[1001][1001];
int sweets[1001][1001];

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);



	cin>>N >>M;
	for (int i=1 ;i<=N; i++){
		for (int j=1; j<=M ;j++){
			cin >>sweets[i][j];
        }
    }

	for (int i=1 ; i<=N ; i++){
		for (int j=1 ; j<=M ; j++){
			dp[i][j] = max(max(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + sweets[i][j];
        }
    }

	cout << dp[N][M];

	return 0;
}
