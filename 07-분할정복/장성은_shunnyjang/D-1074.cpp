#include <iostream>
#include <math.h>
using namespace std;


int answer=0;

int result(int n, int r, int c) {
    if (n < 1)
        return 0;

    int mid = (int)pow(2, n-1);
    if (r < mid && c < mid)
        return result(n-1, r, c);
    else if (r < mid && c >= mid)
        return mid * mid + result(n-1, r, c-mid);
    else if (r >= mid && c < mid)
        return mid * mid * 2 + result(n-1, r-mid, c);
    else
        return mid * mid * 3 + result(n-1, r-mid, c-mid);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, r, c;
    scanf("%d %d %d", &n, &r, &c);
    int answer = result(n, r, c);
    printf("%d\n", answer);
    return 0;
}
