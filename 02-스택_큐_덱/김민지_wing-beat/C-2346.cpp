#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    
    deque<int> deq;
    vector<int> result;
    int N, ballonValue[1001];
    cin >> N;
    
    for(int i=0; i<N; i++){
        deq.push_back(i+1);
        cin >> ballonValue[i];
    }
    
    for(int i=0; i<N; i++){
        result.push_back(deq.front());
        int val = ballonValue[deq.front()-1];
        deq.pop_front();
        
        if(val>0){
            for(int j=0; j<(val-1); j++){
                deq.push_back(deq.front());
                deq.pop_front();
            }
        } else{
            for(int j=0;  j<(-val); j++){
                deq.push_front(deq.back());
                deq.pop_back();
            }
        }
    }
    for(auto& i :result) cout<<i<<' ';
}
