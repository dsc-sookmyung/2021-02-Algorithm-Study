#include <iostream>
#include <algorithm>
using namespace std;

int N;
char P, L, R;
int parent[26][2];

void preOrder(char root) { // 전위순회
    if (root == '.') return;
    else {
        cout << root;
        preOrder(parent[root - 'A'][0]);
        preOrder(parent[root - 'A'][1]);
    }
}

void inOrder(char root) { // 중위순회
    if (root == '.') return;
    else {
        inOrder(parent[root - 'A'][0]);
        cout << root;
        inOrder(parent[root - 'A'][1]);
    }
}

void postOrder(char root) { // 후위순회
    if (root == '.') return;
    else  {
        postOrder(parent[root - 'A'][0]);
        postOrder(parent[root - 'A'][1]);
        cout << root;
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P >> L >> R;
		parent[P - 'A'][0] = L;
		parent[P - 'A'][1] = R;
	}

    preOrder('A');
    cout << '\n';
    inOrder('A'); 
    cout << '\n';
    postOrder('A');
}