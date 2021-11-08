#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int dp[1001];
int arr[1001];

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n; 
    cin >> n; 
    for(int i=0; i<n; i++){
       cin >> arr[i];  
       dp[i]=1;
    }
    
    //LIS 사용
    int result = 1; 
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[i]>arr[j]){
                dp[i] = max(dp[i], dp[j] + 1); 
            }
        }
        result = max(result, dp[i]);
    }
    
    cout << result; 
}

