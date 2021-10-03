//치킨 TOP N
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sorted[1048576];
int N;
int stu;
int array[1048576];

void merge(int a[], int m, int middle, int n){
    if((n-m)>(N/stu)) return;
    int i = m;
    int j = middle + 1;
    int k = m;

    while (i<=middle & j<=n){
        if(a[i]<=a[j]){
            sorted[k++] = a[i++];
        }
        else{
            sorted[k++]=a[j++];
        }
    }

    while(i<=middle) sorted[k++] = a[i++];
    while(j<=n) sorted[k++] = a[j++];
    for(int i=m; i<=n; i++) a[i] = sorted[i];

}

void mergeSort(int a[], int m, int n){
    if(m<n){
        int middle = (m+n)/2;
        mergeSort(a, m, middle);
        mergeSort(a, middle+1, n);
        merge(a, m, middle, n);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i< N; i++){
        cin >> array[i];
    }
    cin >> stu;
    mergeSort(array,0, N-1);

    for(int i=0 ;i<N;i++){
        cout << array[i] << ' ';
    }
}


