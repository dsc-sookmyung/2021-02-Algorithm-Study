#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    
    long long sum=0, N;
    cin >> N;
    
    long long dist[N-1], price[N];
    for(int i=0; i<N-1; i++){
        cin >> dist[i];
    }
    for(int i=0; i<N; i++){
        cin >> price[i];
    }
    long long max = 1000000000;
    
    for(int i=0; i<N-1; i++){
        if(price[i]<max) max=price[i];
        sum += max*dist[i];
    }
    cout << sum;
}