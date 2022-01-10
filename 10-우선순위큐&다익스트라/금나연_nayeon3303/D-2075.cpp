#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int> > pq;
    
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        pq.push(data);
    }
 
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int data;
            cin >> data;
            pq.push(data);
        }
        for (int i = 0; i < n; i++) pq.pop();
    }
    cout << pq.top();
    return 0;
}