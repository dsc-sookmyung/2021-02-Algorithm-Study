#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321 
#define MAX_VERTEX 20001
#define MAX_EDGE 300001 

using namespace std;

int dist[MAX_VERTEX];

vector<pair<int, int> > edge[MAX_EDGE];

void dijkstra(int start_node){
    dist[start_node] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start_node));

    while(!pq.empty()){
        int current=pq.top().second;
        int start_to_current_distance = -pq.top().first;
        pq.pop();
		
		if (dist[current] < start_to_current_distance) {
            continue;
        }
        
        for (int i=0; i<edge[current].size(); ++i){
            int next = edge[current][i].second;
            int start_to_next_distance = start_to_current_distance + edge[current][i].first;
            if (dist[next] > start_to_next_distance){
                dist[next] = start_to_next_distance;
                pq.push(make_pair(-start_to_next_distance, next));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int v, e;
    cin >> v >> e;

    int start_node;
    cin >> start_node;

    for (int i=1; i<v+1; ++i){
        dist[i] = INF;
    }

    for (int i=0; i<e; ++i){
        int start, end, cost;
        cin >> start >> end >> cost;

        edge[start].push_back(make_pair(cost, end));
    }

    dijkstra(start_node);

    for (int i=1; i<v+1; ++i){
        if (dist[i] == INF){
            cout << "INF" << "\n";    
        } else{
            cout << dist[i] << "\n";
        }
    }
}
