#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int r, c;
int result;

void solve(int x, int y, int n) {
    
    if(x == r && y == c) {
        cout<< result;
        return; 
    }

    if(r <= x+n-1 && c <= y+n-1);
    else {
        result += n*n;
        return;
    }
    
    solve(x, y, n/2);
    solve(x + n/2, y, n/2); 
    solve(x, y + n/2, n/2); 
    solve(x + n/2, y + n/2, n/2); 
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    cin >> r >> c;

    solve(0, 0, pow(2, N));

    return 0;
}