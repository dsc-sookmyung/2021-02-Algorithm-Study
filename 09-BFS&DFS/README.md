# 그래프 탐색

- 그래프의 한 정점으로부터 출발해서 모든 정점을 1번씩 방문하여 그래프에 대한 정보를 얻는 것
- 정점 방문 순서에 따라 크게 두 방식으로 나뉨
  - 깊이 우선 탐색 Depth First Search (DFS)
  - 넓이 우선 탐색 Breath First Search (BFS)

## 깊이 우선 탐색 DFS

- 다음 분기(brunch)로 넘어가기 전에 현재 분기를 완전히 탐색하는 방법
- 트리의 전위 (preorder) 탐색이 그래프로 확장된 개념
- `재귀 함수` 또는 `스택`으로 구현한다
- 방법
  ```
  1. 정점 1개를 선택한다
  2. 현재 정점과 이웃한 정점 중 아직 방문하지 않은 정점 중 하나를 방문한다
  3. 더 이상 방문할 수 있는 정점이 없는 경우, 현재 정점의 이전 정점으로 돌아간다.
  4. 모든 정점을 방문할 때까지 2~3을 바복한다.
  ```
- 코드

  ```cpp
  #include <iostream>
  #include <vector>

  const int MAX = 10000;
  using namespace std;

  bool visited[MAX];
  vector<int> adj[MAX];

  void dfs(int u) {
      visited[u] = true;
      for (int i=0; i<adj[u].size(); i++)
          if (!visited[adj[u][i])
              dfs(adj[u][i]);
  }
  ```

## 넓이 우선 탐색 BFS

- 인접한 정점들을 먼저 탐색하는 방법
- 가까운 정점을 먼저 탐색하고 먼 정점을 나중에 탐색
- `큐`로 구현
- 방법
  ```
  1. 정점 1개를 선택한다
  2. 현재 정점(u)과 이웃한 정점(v) 중 방문하지 않은 정점을 모두 방문한다.
  3. v중 가장 먼저 방문한 이웃한 정점으로 이동한다.
  4. 모든 정점을 방문할 때까지 2~2을 반복한다.
  ```
- 코드

  ```cpp
  #include <iostream>
  #include <vector>
  #include <queue>
  const int MAX = 10000;
  using namespace std;

  bool visited[MAX];
  vector<int> adj[MAX];

  int main(void) {
      queue<int> q;
      q.push(root);
      visited[root] = true;
      while (!q.empty()) {
          int u = q.front();
          q.pop()

          for (int v : adj[u]) {
              if (!visited[v]) {
                  visited[v] = true;
                  q.push(v);
              }
          }
      }
  }
  ```

## DFS와 BFS의 공통점과 차이점

### 공통점

1. 그래프의 모든 정점을 1번씩 방문할 수 있음
2. 시간 복잡도가 동일함
   - 인점 행렬 : O(N^2)
   - 인접 리스트 : O(N + E)

### 차이점

| DFS                                  | BFS                                     |
| ------------------------------------ | --------------------------------------- |
| 재귀호출 또는 스택                   | 큐                                      |
| 재귀호출로 인한 시간 소모            | 다음에 방문할 정점 저장으로 메모리 소모 |
| 지나온 경로를 알아야 할 때 주로 사용 | 최단 거리를 구할 때 주로 사용           |
