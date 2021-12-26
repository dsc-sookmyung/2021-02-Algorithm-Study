#include <iostream>
#include <vector>

using namespace std;

struct node
{
public:
    char left;
    char right;
};

vector<node> v(27);

void preOrder(char node)
{
    if (node == '.')
        return;
    printf("%c", node);
    preOrder(v[node].left);
    preOrder(v[node].right);
}

void inOrder(char node)
{
    if (node == '.')
        return;
    inOrder(v[node].left);
    printf("%c", node);
    inOrder(v[node].right);
}

void postOrder(char node)
{
    if (node == '.')
        return;
    postOrder(v[node].left);
    postOrder(v[node].right);
    printf("%c", node);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char p, l, r;
        cin >> p >> l >> r;
        v[p].left = l;
        v[p].right = r;
    }

    preOrder('A');
    cout << endl;

    inOrder('A');
    cout << endl;

    postOrder('A');
    return 0;
}
