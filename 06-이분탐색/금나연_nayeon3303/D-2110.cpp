#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
int arr[200000];
int dist(0);


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N>>C;
    for (int i=0;i<N;i++) {
        cin>>arr[i];
    }
    
    sort(arr, arr + N);
 
    int high = arr[N-1], low (0);
    int p, mid, count;

    while (low <= high) {
        mid = (low + high)/2;
        p=0;
        count=1;

        for (int i=1;i<N;i++) {
            if (arr[i]-arr[p] >= mid) {
                p=i;
                count++;
            }
        }
        if (count>=C) {
            if (dist<mid)
                dist=mid;
            low=mid+1;
        }
        else
            high=mid-1;
    }
    
    cout<<dist;

    return 0;
}