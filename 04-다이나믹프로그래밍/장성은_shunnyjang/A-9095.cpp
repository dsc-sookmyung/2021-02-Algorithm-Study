#include <iostream>

using namespace std;

int main(int argc, const char** argv) {
    int t;
    cin >> t;
    int dp[12] = { 0, 1, 2, 4 };

    for (int i=4; i<11; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    for (int i=0; i<t; i++) {
        int num;
        cin >> num;
        cout << dp[num] << endl;
    }

    return 0;
}
