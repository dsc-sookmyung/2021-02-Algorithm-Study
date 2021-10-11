#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int N, K, len;
    long long Good=0;
    string input;
    vector<int> v(21);
    queue<int> q;
    
    cin >> N >> K;
    for(int i=0; i<N; i++){
        cin >> input;
        len = input.length();
        Good += v[len];
        
        if( int(q.size()) >= K){
            v[q.front()]--;
            q.pop();
        }
        v[len]++;
        q.push(len);
    }
    cout << Good;
}
