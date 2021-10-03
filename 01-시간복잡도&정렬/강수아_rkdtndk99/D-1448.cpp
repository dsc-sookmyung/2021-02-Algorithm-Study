//삼각형 만들기
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    int array[1000000];

    cin >> N;
    for (int i=0; i<N; i++){
        cin >> array[i];
    }

    sort(array, array+N, greater<int>());

    int i=0;
    int total;
    while(i<N-2){
        int biggest = array[i];
        total =0;
        if(array[i+1] + array[i+2] > biggest){
            total = biggest+ array[i+1]+ array[i+2];

            break;
        } else {
            i++;
            total = -1;
        }
    }
    cout << total;


}



