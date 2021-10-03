#include <iostream>
#define MAX_SIZE 1048576
using namespace std;
int sorted[MAX_SIZE];
int n, person;

void merge(int list[], int left, int mid, int right){
    if((right-left) > (n/person)) return;
    
    int i = left, j = mid+1, k = 0;
    
    while(i<=mid && j<=right){
        if(list[i]<=list[j])
          sorted[k++] = list[i++];
        else
          sorted[k++] = list[j++];
    }
    while(i <= mid){ 
        sorted[k++] = list[i++];
    }
    while (j <= right) {
        sorted[k++] = list[j++];
    }
    for(int l=left; l<=right; l++){
        list[l] = sorted[l-left];
    }
}

void merge_sort(int list[], int left, int right){
    if(left == right) return;
    int mid = (left+right)/2; 
    merge_sort(list, left, mid); 
    merge_sort(list, mid+1, right);
    merge(list, left, mid, right); 
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    int list[n];
    for(int i=0; i<n; i++){
      cin >> list[i];
    }
    cin >> person;
    
    merge_sort(list, 0, n-1);
    
    for(int i=0; i<n; i++){
        cout << list[i] << ' ';
    }
}
