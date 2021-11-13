#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v;

    int N, K, M, p;
    int l=1, r=1000000000, mid, count;
    int piece=-1;
    cin>>N>>K>>M;

    for (int i=0; i<N; i++) {
        cin >> p;
        if (p > 2*K)
            v.push_back(p-2*K);
        
        if (2*K>p && p>K)
            v.push_back(p-K);
    }

    while (l <= r) {
        mid = (l+r)/2;
        count=0;

        for (int p:v)
            count += p / mid;

        if (count >= M) {
            piece = mid;
            l = mid+1;
        } else
            r = mid-1;
    }
    cout<<piece<<'\n';

    return 0;
}