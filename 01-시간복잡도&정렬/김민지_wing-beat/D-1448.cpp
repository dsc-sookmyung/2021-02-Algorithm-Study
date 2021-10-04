#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int N, input;
    vector<int> v;
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end(), greater<>());
    
    int i=0;
    while(1){
        if (v[i] < v[i+1]+v[i+2]){
            cout << v[i]+v[i+1]+v[i+2] << '\n';
            break;
        }
        i++;
        if (i+2 >= N) {
            cout << -1 <<'\n';
            break;
        }
    }
}
