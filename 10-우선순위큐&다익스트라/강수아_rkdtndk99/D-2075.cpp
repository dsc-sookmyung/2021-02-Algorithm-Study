#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    priority_queue<int, vector<int>, greater<int>> pq;
    int n, in; cin>>n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>in;
            pq.push(in);
            if(pq.size()>n){
                pq.pop();
            }
        }
    }
    

    cout<<pq.top();
    return 0;
}
