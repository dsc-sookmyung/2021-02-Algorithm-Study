#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;  
 
#define INF 987654321
int N, E;
vector<map<int, int>> edge_vec;
 
int dijkstra(int _start, int _end) { 
    vector<int> distance(N + 1, INF); 
    priority_queue<int, vector<int>, greater<int> > pq;
 
    distance.at(_start) = 0;
 
    pq.push(_start);
    while (!pq.empty()) {
        int now_node_ = pq.top();  pq.pop(); 
 
        for (auto edge_ : edge_vec.at(now_node_)) {
            int to_ = edge_.first;
            int weight_ = edge_.second;
 
            if (weight_ + distance.at(now_node_) < distance.at(to_)) {
                distance.at(to_) = weight_ + distance.at(now_node_);
                pq.push(to_);
            }
        }
    }
    return distance.at(_end);
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> E;
    edge_vec.resize(N+1);
 
    for (int e_idx = 0; e_idx < E; e_idx++) {
        int node_1_, node_2_, weight_;
        cin >> node_1_ >> node_2_ >> weight_;
 
        if (edge_vec.at(node_1_)[node_2_] == 0) {
            edge_vec.at(node_1_)[node_2_] = weight_;
		} else if (weight_ < edge_vec.at(node_1_)[node_2_])
            edge_vec.at(node_1_)[node_2_] = weight_;
 
        if (edge_vec.at(node_2_)[node_1_] == 0) {
            edge_vec.at(node_2_)[node_1_] = weight_;
		} else if (weight_ < edge_vec.at(node_2_)[node_1_]) {
            edge_vec.at(node_2_)[node_1_] = weight_;
        }
    }
 
    int start = 1, end = N;
    int a, b;
    cin >> a>> b;
     
    int start_a = dijkstra(start, a);
    int a_b = dijkstra(a, b);
    int b_N = dijkstra(b, N);
    int is_possible_1 = 0 ;
 
    if (start_a == INF || a_b == INF || b_N == INF) {
    	is_possible_1 = 0; 
	} else {
		is_possible_1 = 1;	
	}
 
    int start_b = dijkstra(start, b);
    int b_a = dijkstra(b, a);
    int a_N = dijkstra(a, N);
    int is_possible_2 = 0;
 
    if (start_b == INF || b_a == INF || a_N == INF) {
    	is_possible_2 = 0;
	} else {
    	is_possible_2 = 1;	
	}
 
    if (is_possible_1 == 0 && is_possible_2 == 0) {
    	cout << "-1";	
	} else {
		cout << min({ start_a + a_b + b_N , start_b + b_a + a_N });
	}
}

