#include <iostream>
#include <vector>
#define MAX 51

using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

struct TREENODE {
	int parent = -1;
	vector<int> children;
};

struct TREENODE tree[MAX];
int N, root, x_node, leaf_node = 0;


void search_tree(int index) {

	if (index == x_node) {
		int node_par = tree[index].parent;
		if (tree[node_par].children.size() == 1) leaf_node++;

		return;
	}

	int child_size = tree[index].children.size();

	if (child_size == 0) {
		leaf_node++;
		return;
	}
	else {
		for (int i = 0; i < child_size; i++)
			search_tree(tree[index].children[i]);
		return;
	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		int par;
		cin >> par;

		tree[i].parent = par;
		if (par != -1)	tree[par].children.push_back(i);
		else root = i;
	}

	cin >> x_node;

	search_tree(root);

	cout << leaf_node;

	return 0;
}