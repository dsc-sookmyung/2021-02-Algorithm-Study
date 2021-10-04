#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}
int main()
{
    init();
    
    vector<int> v;
    string n;
    int sum = 0;
    bool flag = false;
    cin >> n;
    
    for (int i = 0; i < n.length(); i++) {
        v.push_back(n.at(i) - '0');
        sum += v.back();
        if (v.back() == 0) flag = true;
    }

    if (flag == false || (sum % 3) != 0) {
        cout << -1;
        return 0;
    }
    else {
        sort(v.begin(), v.end());

        for (int i = 0; v.size() != 0; i++) {
            cout << v.back();
            v.pop_back();
        }
        return 0;
    }
    return -1;
}