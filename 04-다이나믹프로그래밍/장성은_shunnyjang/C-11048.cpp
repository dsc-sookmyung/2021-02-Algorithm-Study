#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
long long candy[1001][1001] = { -1 };
long long check[1001][1001] = { 0 };

int get_max(int a, int b, int c) {
    int result = max(a, b);
    result = max(result, c);
    return result;
}

int main(int argc, const char** argv) {
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin >> candy[i][j];
        }
    }
    
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            check[i][j] = candy[i][j] + get_max(check[i-1][j-1], check[i][j-1], check[i-1][j]);
        }
    }

    cout << check[n][m] << endl;
    return 0;
}
