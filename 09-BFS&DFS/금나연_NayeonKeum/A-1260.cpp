#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;


int N, M, V;
int map[1001][1001];
bool visited[1001];
queue<int> que;
 
void reset() {
    for (int i=1; i<=N; i++) {
        visited[i]=0;
    }
}
 
void DFS(int v) {
    visited[v]=true;
    cout<<v<<" ";
    
    for (int i=1; i<=N; i++) {
        if (map[v][i]==1 && visited[i]==0) DFS(i);
    }
}
 
void BFS(int v) {
    que.push(v);
    visited[v]=true;
    cout<<v<<" ";
 
    while (!que.empty()) {
        v = que.front();
        que.pop();
        
        for (int w = 1; w <= N; w++) {
            if (map[v][w] == 1 && visited[w] == 0) {
                que.push(w);
                visited[w]=true;
                cout<<w<<" ";
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N>>M>>V;
 
    for (int i=0; i<M; i++) {
        int a, b;
        cin>>a>>b;
        map[a][b]=1;
        map[b][a]=1;
    }
 
    reset();
    DFS(V);
    
    cout<<'\n';
    
    reset();
    BFS(V);

    return 0;
}