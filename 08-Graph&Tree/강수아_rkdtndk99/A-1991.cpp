#include <iostream>

using namespace std;

struct Node{
    int parent;
    int left;
    int right;
};

Node nodes[27];
char p, r, l;
int n;

void func(int idx, int dir)                
{
    if(idx < 0) return;                     

    if(dir == 0) cout << char(idx + 65);    
    func(nodes[idx].left, dir);             
    if(dir == -1) cout << char(idx + 65);
    func(nodes[idx].right, dir);            
    if(dir == 1) cout << char(idx + 65);
}

int main(void){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> p >> l >> r;
        nodes[p-65].left = l - 65;          
        nodes[p-65].right = r - 65;
        nodes[l-65].parent = p - 65;
        nodes[r-65].parent = p - 65;
    }
    func(0, 0);                              
    cout << '\n';
    func(0, -1);                             
    cout << '\n';
    func(0, 1);                              
    cout << '\n';
}
