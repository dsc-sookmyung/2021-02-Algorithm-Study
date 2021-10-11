#include <iostream>
#include <deque>
#include <utility>

using namespace std;

int n;
deque< pair<int, int> > dq;

int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int value;
        cin >> value;
        dq.push_back(make_pair(i, value));
    }

    while (!dq.empty()) {
        int key = dq.front().first;
        int value = dq.front().second;
        cout << key << ' ';
        dq.pop_front();

        if (value >= 0) {
            for (int i=0; i<value-1; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } else {
            for (int i=0; i>value; i--) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
    return 0;
}
