#include <iostream>
using namespace std;

int getMax(int n1, int n2, int n3){
    int max = 0;
    if (max < n1) max = n1;
    if (max < n2) max = n2;
    if (max < n3) max = n3;
    return max;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    
    int M, N, val, max;
    cin >> N >> M;
    
    int dp[1001][1001];
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> val;
            max = getMax(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]);
            dp[i][j] = max + val;
        }
    }
    cout << dp[N][M];
}