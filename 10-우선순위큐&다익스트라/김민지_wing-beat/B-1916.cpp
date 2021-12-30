#include <iostream>
#include <vector>
#include <queue>

#define MAX 1001
#define INF 987654321
 
using namespace std;
 
vector<pair<int,int>> g[MAX]; 
vector<int> dist(MAX,INF);
int src, dst;
 
void dijkstra(){
	priority_queue<pair<int,int>> pq;  
    pq.push({0,src});
    dist[src]=0;
    
    while(!pq.empty()){
        int current=pq.top().second;
        int cost=-pq.top().first;
        pq.pop();
 
        if(dist[current] < cost) continue;
        for(int i=0;i<g[current].size();i++){
            int next=g[current][i].first;
            int nCost=g[current][i].second+cost;
            if(dist[next]>nCost){
                dist[next]=nCost;
                pq.push({-nCost,next});
            }
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	
    int N, M, a, b, c;
    cin >> N >> M;
    
    while(M--) {
        cin >> a >> b >> c;
        g[a].push_back({b,c});
    }
    cin >> src >> dst;
    dijkstra();
    cout << dist[dst];
}
