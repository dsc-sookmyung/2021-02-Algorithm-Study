#include <iostream>
#include <algorithm>

using namespace std;
int arr[1000000];

void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int main() {
    init();
    
    int n, result;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for (int k = n-1; k >= 2; k--) {
        if (arr[k] < (arr[k - 1] + arr[k - 2])) {
            cout << arr[k] + arr[k - 1] + arr[k - 2];
            return 0;
        }
    }
    cout << -1;

}