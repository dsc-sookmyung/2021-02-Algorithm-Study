#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int board[1025][1025];

void result(int num) {
    if (num==1)
        return;
    for (int i=0; i<num; i+=2) {
        for (int j=0; j<num; j+=2) {
            vector<int> temp;
            temp.push_back(board[i][j]);
            temp.push_back(board[i][j+1]);
            temp.push_back(board[i+1][j]);
            temp.push_back(board[i+1][j+1]);
            sort(temp.begin(), temp.end());
            board[i/2][j/2]=temp[2];
        }
    }
    result(num/2);
}

int main(void) {
    cin >> n;
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> board[i][j];
        }
    }

    result(n);
    cout << board[0][0] << endl;
    return 0;
    
}
