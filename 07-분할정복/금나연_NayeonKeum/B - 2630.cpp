#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int paper[128][128];
int N;
int b, w;

void solve(int y, int x, int size){
    int ck = paper[y][x];

    for (int i = y; i < y + size; i++){
        for (int j = x; j < x + size; j++){

            if (ck == 0 && paper[i][j] == 1){
                ck = 2;
            }
            else if (ck == 1 && paper[i][j] == 0){
                ck = 2;
            }
            if (ck == 2){
                solve(y, x, size/2);
                solve(y, x + size/2, size/2);
                solve(y + size/2, x, size/2);
                solve(y + size/2, x + size/2, size/2);

                return;
            }
        }
    }
    if (ck == 0) w++;
    else b++;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> paper[i][j];

    solve(0, 0, N);
    cout << w << '\n' << b << '\n';

    return 0;
}