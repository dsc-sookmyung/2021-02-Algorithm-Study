#include <iostream>
#include <string>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

int n, m;
vector<pair<int, int>> v[1001];
int s, d;
int dist[1001];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
    }
    cin >> s >> d;
    for(int i = 1; i <= n; i++){
        dist[i] = INF;
    }

    priority_queue<pair<int, int>> pq;

    pq.push(make_pair(0, s));
    dist[s] = 0;

    while( !pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(dist[cur]<cost) continue;

        for(int i = 0; i < v[cur].size(); i++){
            int next = v[cur][i].first;
            int nc = cost+v[cur][i].second;
            
            if(dist[next] > nc){
                dist[next] = nc;
                pq.push(make_pair(-nc, next));
            }
        }
    }
    cout << dist[d] << "\n";


    return 0;
}