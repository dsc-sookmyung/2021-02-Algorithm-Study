#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numList[1000000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    // ����
    int n;
    cin>>n;

    // �Է�
    for (int i=0;i<n;i++){
        cin>>numList[i];
    }

    // ����
    sort(numList, numList+n, greater<int>());

    //���
    for (int i=0;i<n;i++){
        cout<<numList[i]<<'\n';
    }

    return 0;
}