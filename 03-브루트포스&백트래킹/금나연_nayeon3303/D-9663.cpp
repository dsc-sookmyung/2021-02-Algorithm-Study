#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int col[15];
int n, total = 0;

bool check(int level)
{
    for(int i=0; i< level; i++)
        // 불가능(같은라인|대각선)
        if(col[i] == col[level] || abs(col[level] - col[i]) == level - i) return false;
    return true;
}

void canQueen(int x)
{
    if(x == n) total++;
    else{
        for(int i = 0; i < n; i++){
            col[x] = i; 
            if(check(x))
                canQueen(x+1);
        }
    }
}
int main() {
    cin >> n;
    canQueen(0);
    cout << total<<'\n';
}