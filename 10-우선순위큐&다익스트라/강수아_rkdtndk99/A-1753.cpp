#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v[20001];
priority_queue<pair<int,int>> pq;
bool visited[20001];
int dist[20001];
int V, E,K;
int INF = INT_MAX;

void dijk(int start){
    pq.push({0,start});
    dist[start] = 0;
    
    while(!pq.empty()){
        int weight=pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if(visited[node] ==true) continue;
        
        visited[node] = true;

        for(int i = 0; i< v[node].size(); i++){
            int nn = v[node][i].first; 
            int nw = v[node][i].second; 

            if(visited[nn] ==false && dist[nn] > dist[node]+nw){
                dist[nn] = dist[node] +nw; 
                pq.push({-(dist[node] +nw),nn}); 
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> V >> E >> K;
    for(int i = 1; i<=V; i++){
        dist[i] = INF;
    }
    
    for(int i = 0; i< E; i++){
        int s, e, w;
        cin >> s >> e >> w;
        v[s].push_back({e,w});
    }
    dijk(K);
    
    for(int i = 1; i<= V; i++){
        if(dist[i] == INF) cout << "INF\n";
        else{
            cout << dist[i]<<'\n';
        }
    }
}
