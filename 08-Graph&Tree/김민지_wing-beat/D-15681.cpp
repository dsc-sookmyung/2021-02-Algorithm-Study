#include <iostream>
using namespace std;

int N, r, c;

    int x, y, ans;
void Z(int x, int y, int n) {
    if (x==r && y==c) {
        cout << ans;
        return;
    }

    if (r < x + n && r >= x && c < y + n && c >= y) {
        Z(x, y, n / 2);
        Z(x, y + n / 2, n / 2);
        Z(x + n / 2, y, n / 2);
        Z(x + n / 2, y + n / 2, n / 2);
    }
    else ans += n* n;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> r >> c;

    Z(0, 0, (1 << N));
}