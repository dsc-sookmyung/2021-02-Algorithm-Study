#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 2^20
int l[1048576]; 
int r[1048576]; 
int n, cnt, lim; 

// 병합
void merge(int start, int end) {
    if ((end-start)>(n/lim)) return;
	int mid=(start+end)/2;
	int i=start, j=mid+1, k=0;

	while (i<=mid && j<=end) {
		if (l[i]<=l[j]) {
			r[k++]=l[i++];
		}
		else {
			r[k++]=l[j++];
		}
	}
    while (i <= mid) r[k++]=l[i++]; 
    while (j <= end) r[k++]=l[j++]; 
    for (int i=start; i<=end; i++) 
        l[i]=r[i-start]; 
}

// 병합 정렬(재귀)
void merge_sort(int start, int end) {
	if (start == end)
		return;
	int mid=(start+end)/2;
	merge_sort(start, mid);
	merge_sort(mid + 1, end);
	merge(start, end);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin>>n; 
    for (int i=0; i<n; i++) { 
        cin>>l[i];
    } 
    cin>>lim; 
    merge_sort(0, n-1); 
    for (int i=0; i<n; i++) { 
        cout<<l[i]<<' ';
    }

    return 0;
}