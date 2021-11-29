#include <iostream>

using namespace std;

struct TREE {
	char left;
	char right;
};

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int N;
TREE tree[27];

void preorder(char node) {
	if (node == '.') return;

	printf("%c", node);
	preorder(tree[node].left);
	preorder(tree[node].right);
}

void inorder(char node) {
	if (node == '.') return;

	inorder(tree[node].left);
	printf("%c", node);
	inorder(tree[node].right);
}

void postorder(char node) {
	if (node == '.') return;

	postorder(tree[node].left);
	postorder(tree[node].right);
	printf("%c", node);
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		char node, l, r;
		
		cin >> node >> l >> r;
		tree[node].left = l;
		tree[node].right = r;
	}

	preorder('A');
	cout << "\n";

	inorder('A');
	cout << "\n";

	postorder('A');

	return 0;
}