#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;


int V, E, s;
int dist[20010];
vector<pair<int, int>> v[20010];
 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> V >> E >> s;

    for (int i = 0; i < E; i++){
        int a, b, c; 
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
    }

    for (int i = 1; i <= V; i++) dist[i] = INF;

    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, s));

    dist[s] = 0;
 
    while (pq.empty() == 0){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
 
        for (int i = 0; i < v[cur].size(); i++){
            int Next = v[cur][i].first;
            int nCost = v[cur][i].second;
 
            if (dist[Next] > cost + nCost){
                dist[Next] = cost + nCost;
                pq.push(make_pair(-dist[Next], Next));
            }
        }
    }
 
    for (int i = 1; i <= V; i++){
        if (dist[i] == INF) cout << "INF" << "\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}