#include <iostream>
#include <vector>
 
using namespace std;

vector<int> v;
 
int main() {
	cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int n, k, m, gb;
    int l = 1, r = 1000000000, mid, count, p = -1;
    cin >> n >> k >> m;
    
    for (int i = 0; i < n; i++) {
        cin >> gb;
        if (gb > 2 * k)
            v.push_back(gb - 2 * k);
        if (2 * k > gb && gb > k)
            v.push_back(gb - k);
    }
    while (l <= r) {
        mid = (l + r) / 2;
        count = 0;
        for (int gb:v)
            count += gb / mid;
        if (count >= m) {
            p = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }
    cout << p << '\n';
    return 0;
}
