#include <iostream>
#include <vector>

#define MAX 100001

using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

vector<int> tree[MAX];
bool visited[MAX];
int parent[MAX];
int N;


void find_parent(int index) {

	visited[index] = true;

	for (int i = 0; i < tree[index].size(); i++) {
		int next = tree[index][i];

		if (!visited[next]) {
			parent[next] = index;
			find_parent(next);
		}
	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int node1, node2;
		cin >> node1 >> node2;

		tree[node1].push_back(node2);
		tree[node2].push_back(node1);
	}

	find_parent(1);

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << "\n";
	}

	return 0;
}