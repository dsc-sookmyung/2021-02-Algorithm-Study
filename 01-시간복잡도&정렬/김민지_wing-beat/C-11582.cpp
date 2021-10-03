#include <iostream>
using namespace std;
#define MAX_SIZE 1048576
int sorted[MAX_SIZE];
int n, person;

void merge(int list[], int left, int mid, int right){
    if( (right-left) > (n/person) ) return;
    
    int i, j, k;
    i = left;
    j = mid+1;
    k = 0;
    
    /* 분할 정렬된 list의 합병 */
    while(i<=mid && j<=right){
        if(list[i]<=list[j])
          sorted[k++] = list[i++];
        else
          sorted[k++] = list[j++];
    }
    
    // 남아 있는 값들을 일괄 복사
    while(i <= mid){ 
        sorted[k++] = list[i++];
    }
    // 남아 있는 값들을 일괄 복사
    while (j <= right) {
        sorted[k++] = list[j++];
    }
    // 배열 sorted[](임시 배열)의 리스트를 배열 list[]로 재복사
    for(int l=left; l<=right; l++){
        list[l] = sorted[l-left];
    }
}

void merge_sort(int list[], int left, int right){
    if(left == right) return;
    int mid = (left+right)/2; 
    merge_sort(list, left, mid); // 앞쪽 부분 리스트 정렬 -정복(Conquer)
    merge_sort(list, mid+1, right); // 뒤쪽 부분 리스트 정렬 -정복(Conquer)
    merge(list, left, mid, right); // 정렬된 2개의 부분 배열을 합병하는 과정 -결합(Combine)
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
    
    // 합병 정렬 수행(left: 배열의 시작 = 0, right: 배열의 끝 = 7)
    merge_sort(list, 0, n-1);
    
    // 정렬 결과 출력
    for(int i=0; i<n; i++){
        cout << list[i] << ' ';
    }
}