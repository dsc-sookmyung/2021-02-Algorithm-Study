#include <iostream>

using namespace std;

int n, k;
int types[12];
int main(int argc, const char** argv) {
    int count = 0;
    cin >> n >> k;
    for (int i=n; i>0; i--)
        cin >> types[i];

    for (int i=1; i<=n; i++) {
        if (k < types[i]) continue;
        if (k == 0) break;
        count += k/types[i];
        k %= types[i];
    }
    cout << count << endl;
    return 0;
}