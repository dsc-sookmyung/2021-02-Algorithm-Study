#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define MAX 801
#define INF 987654321
#define MIN(A, B) A > B ? B : A
 
using namespace std;
typedef pair<int, int> P;
 
int N, E, A, B, answer;
vector<pair<int, int>> adj[MAX];  
 
int dijkstra(int start, int end) {
    vector<int> dist(N + 1, INF);
    dist[start] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;  
    pq.push(make_pair(0, start));
    while (!pq.empty()) {
        int node = pq.top().second;
        int node_distance = pq.top().first;
        pq.pop();
 
        for (int i = 0; i < adj[node].size(); i++) {
            int next_node = adj[node][i].first;
            int next_node_distance = node_distance + adj[node][i].second;
 
            if (dist[next_node] > next_node_distance) {
                dist[next_node] = next_node_distance;
                pq.push(make_pair(next_node_distance, next_node));
            }
        }
    }
    return dist.at(end);
}
 
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    bool check1 = true;
    bool check2 = true;
 
    cin >> N >> E;
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }
 
    cin >> A >> B;
 
    int start_a = dijkstra(1, A);  
    int a_b = dijkstra(A, B);      
    int b_N = dijkstra(B, N);      
 
    if (start_a == INF || a_b == INF || b_N == INF) check1 = false;  
 
    int start_b = dijkstra(1, B);  
    int b_a = dijkstra(B, A);      
    int a_N = dijkstra(A, N);      
 
    if (start_b == INF || b_a == INF || a_N == INF) check2 = false;  
 
    if (check1 && check2) {
        int case1 = start_a + a_b + b_N;
        int case2 = start_b + b_a + a_N;
        answer = MIN(case1, case2);
    } else {
        answer = -1;
    }
 
    cout << answer;
 
    return 0;
}
