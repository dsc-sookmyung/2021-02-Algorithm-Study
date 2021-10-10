#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n, k, len;
queue<int> classmates[21];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

    long long good_friend = 0;
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        string name;
        cin >> name;

        len = name.length();
        while (!classmates[len].empty() && i-classmates[len].front() > k) {
            classmates[len].pop();
        }
        good_friend += classmates[len].size();
        classmates[len].push(i);
    }

    cout << good_friend << endl;

    return 0;
}
