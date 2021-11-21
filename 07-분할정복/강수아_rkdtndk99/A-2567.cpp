
~
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int paper[102][102];

int y_dir[4] = {-1, 0, 1, 0};
int x_dir[4] = {0, -1, 0, 1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    scanf("%d", &N);

    while (N--)
    {
        int x, y;
        scanf("%d %d", &y, &x);
        for (int i = y; i < y + 10; i++)
            for (int j = x; j < x + 10; j++)
                    paper[i][j] ++;
    }

    int sum(0);
    for (int i = 0; i <= 100; i++)
        for (int j = 0; j <= 100; j++)
            if (paper[i][j] == 0)
                for (int k = 0; k < 4; k++){
                    int new_y = i + y_dir[k];
                    int new_x = j + x_dir[k];
                    if ((0 <= new_y && new_y <= 100) && (0 <= new_x && new_x <= 100) && paper[new_y][new_x] >= 1)
                        sum++;
                }

    cout << sum;
    return 0;
}
