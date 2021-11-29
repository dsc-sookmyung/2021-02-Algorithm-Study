#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> v[100001];
int parent[100001];
bool visited[100001];
int N;
 
void findParent(int x){
    visited[x] = true;
    for(int i = 0; i < v[x].size(); i++){

        int next = v[x][i];

        if(visited[next] == false){
            parent[next] = x;
            findParent(next);
        }
        
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    int a, b;

    for(int i=1;i<N;i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    findParent(1);
    
    for(int i=2;i<=N;i++)
        cout << parent[i] << '\n';
    
    return 0;
}