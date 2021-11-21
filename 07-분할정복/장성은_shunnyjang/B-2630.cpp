#include <iostream>

using namespace std;

int len, white=0, blue=0;
int board[129][129];

void result(int x, int y, int n) {
    int blue_count=0;
    for (int i=x; i<x+n; i++) {
        for (int j=y; j<y+n; j++) {
            if (board[i][j])
                blue_count++;
        }
    }

    if (!blue_count)
        white++;
	else if (blue_count == n*n)
        blue++;
	else {
		result(x, y, n/2);
		result(x, y + n/2, n/2);
		result(x + n/2, y, n/2);
		result(x + n/2, y + n/2, n/2);
	}
	return;
}

int main(int argc, const char** argv) {
    cin >> len;
    for (int i=0; i<len; i++) {
        for (int j=0; j<len; j++) {
            cin >> board[i][j];
        }
    }

    result(0, 0, len);
    cout << white << endl << blue << endl;

    return 0;
}