#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numList[1000000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    // 개수
    int n;
    cin>>n;

    // 입력
    for (int i=0;i<n;i++){
        cin>>numList[i];
    }

    // 정렬
    sort(numList, numList+n, greater<int>());

    //출력
    for (int i=0;i<n;i++){
        cout<<numList[i]<<'\n';
    }

    return 0;
}