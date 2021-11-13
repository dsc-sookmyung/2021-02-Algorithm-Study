#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    int bs[100000];
    cin>>N;

    for (int i = 0; i < N; i++)
        cin>>bs[i];

    cin>>M;

    sort(bs, bs + N);

    int t;
    for (int i=0; i<M; i++) {
        cin>>t;
        cout<<binary_search(bs, bs+N, t) << '\n';
    }

    return 0;
}