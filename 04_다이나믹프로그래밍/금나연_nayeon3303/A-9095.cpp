#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    int T, n;
    cin>>T;

    vector<int> dp(12, 0);
    
    dp.push_back(1);
    dp.push_back(2);
    dp.push_back(4);

    for (int i=4;i<12; i++)
        dp[i] =dp[i-1] +dp[i-2]+dp[i-3];

    for (int i=0; i < T; i++){
        cin>>n;
        cout<<dp[n]<<'\n';
    }

    return 0;
}