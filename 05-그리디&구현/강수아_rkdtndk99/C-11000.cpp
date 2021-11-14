#include <iostream>
#include <utility>
#include <queue> 
#include <algorithm>
using namespace std;

int main(){
    cin.tie(0), cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    priority_queue<int,vector<int>,greater<int>> pq;
    vector<pair<int, int>> v;
    
    int n; 
    cin >> n; 
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x,y}); 
    }
    sort(v.begin(), v.end());

    pq.push(v[0].second);

    int answer = 1;
    for (int i = 1; i < v.size(); i++) {
    while (!pq.empty() && pq.top() <= v[i].first)
        pq.pop();
        pq.push(v[i].second);
        answer = max(answer, (int)pq.size());
    }
    cout << answer;
}

