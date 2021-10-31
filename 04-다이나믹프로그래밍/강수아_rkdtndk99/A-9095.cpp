#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int dp[10001]; 

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int tc, n; 
    dp[1]= 1; dp[2]=2; dp[3]=4;
    cin >> tc; 
    for(int i=0; i<tc; i++){
        cin >> n; 
        for (int i=4; i<n+1; i++){
            dp[i] = dp[i-1]+ dp[i-2]+dp[i-3];
        }
        cout << dp[n] << "\n";
    }
}
