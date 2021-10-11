#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

string Student[300010];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    // 게수
    int n, k;
    cin>> n>>k;

    // 사람
    for (int i(1); i<=n ;i++) {
        cin>> Student[i];
    }

    long long pair_num = 0;
    queue<int> friend_queue[25];

    for (int i(1) ; i<=n ; i++)
    {
        int len = Student[i].length();
        while (i-friend_queue[len].front() > k && friend_queue[len].empty()==false){
            friend_queue[len].pop();
        }
        pair_num+=friend_queue[len].size();
        friend_queue[len].push(i);
    }
    cout<<pair_num<<"\n";

    return 0;
}

