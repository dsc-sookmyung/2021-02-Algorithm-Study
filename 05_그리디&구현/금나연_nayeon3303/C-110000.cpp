#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
 
pair<int, int> pairs[200000];

priority_queue<int, vector<int>, greater<int>> p_queue;

int N, count;

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> pairs[i].first>>pairs[i].second;
    }
 
    sort(pairs+1, pairs+N+1);
 
    p_queue.push(pairs[1].second);
 
    for(int i=2; i<=N; i++){
        if(p_queue.top() <= pairs[i].first){
            p_queue.pop();
            p_queue.push(pairs[i].second);
        }
        else{
            p_queue.push(pairs[i].second);
        }
    }
 
    cout<<p_queue.size()<<endl;

    return 0;
}