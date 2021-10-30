#include <iostream>

using namespace std;

int dp[1001];
int arr[1001];

int lis(int n) {
    int i,j;
    int max = 1;
    for(i=1;i<=n;i++){
        dp[i] = 1;
        for(j=1;j<=i;j++){
            if(arr[j] < arr[i] && dp[j]+1 > dp[i]){
                dp[i] = dp[j]+1;
                if(max < dp[i])
                    max = dp[i];
            }
        }
    }
    return max;
}

int main(int argc, const char** argv) {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> arr[i];
    }

    cout << lis(n) << endl;
    return 0;
}
