#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, const char** argv) {
    int n;
    long long s[200000], t[200000];

    cin >> n;
    for (int i=0; i<n; i++)
        cin >> s[i] >> t[i];

    sort(s, s+n);
    sort(t, t+n);

    int count=1, i=1, j=0;
    while (i<n) {
        if (s[i]<t[j]) {
            count++;
            i++;
        }
        else {
            i++;
            j++;
        }
    }

    cout << count << endl;
    return 0;
}
