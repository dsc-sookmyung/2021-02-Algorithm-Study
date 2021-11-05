#include <iostream>

using namespace std;

int main(int argc, const char** argv) {
    int n;
    int dp[1001] = { 0, 1, 2 };
    cin >> n;

    for (int i=3; i<=n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }
    cout << dp[n] << endl;

    return 0;
}
