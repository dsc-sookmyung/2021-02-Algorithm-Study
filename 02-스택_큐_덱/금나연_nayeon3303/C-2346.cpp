#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

typedef pair<int, int> pairs;
deque<pairs> balloon_deque;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    // 개수
    int n, argument;
    cin>>n;
	
    // 풍선
    for (int i(0) ; i<n ; i++) {
        cin>>argument;
        balloon_deque.emplace_back(i+1, argument);
    }

    while (!balloon_deque.empty()) {
        pairs balloon=balloon_deque.front();
        cout<<balloon.first<<' ';
        balloon_deque.pop_front();

        // 해당 수 전까지의 다시 push
        // 타겟 풍선은 pop
        for (int i(1) ; i<balloon.second ; i++) {
            balloon_deque.push_back(balloon_deque.front());
            balloon_deque.pop_front();
        }
        
        for (int i(0) ; i>balloon.second ; i--) {
            balloon_deque.push_front(balloon_deque.back());
            balloon_deque.pop_back();
        }
    }

    return 0;

}