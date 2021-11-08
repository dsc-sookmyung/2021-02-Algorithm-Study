#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];
int arr[1001][1001];

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n, m; 
    cin >> n >> m; 
    
    for(int i=1; i<=n;i++){
        for(int j=1; j<=m; j++){
            cin >> arr[i][j]; 
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int rUp, cUp, rcUp; 
            
            cUp = dp[i-1][j];
            
            rUp = dp[i][j-1]; 
            
            rcUp = dp[i-1][j-1]; 
            
            dp[i][j] = arr[i][j] + max({cUp, rUp, rcUp});
        }
    }
    cout << dp[n][m];
}

