#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree(100001);
vector<bool> visited(100001, false);
vector<int> parent(100001, 0);

void search(int start){
    for(int i = 0; i < tree[start].size(); i++){
        int now = tree[start][i];
        if(!visited[now]){
            visited[now] = true;
            parent[now] = start;
            search(now);
        }
    }
}

int main(void){
    int N;
    cin >> N;

    for(int i = 0; i < N - 1; i++){
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    search(1); // 루트부터 시작

    for(int i = 2; i <= N; i++){
        cout << parent[i] << "\n";
    }
}