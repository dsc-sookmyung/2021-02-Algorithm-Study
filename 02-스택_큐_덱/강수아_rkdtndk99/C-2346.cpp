// 2346 풍선 터뜨리기
#include <iostream>
#include <deque> 

using namespace std; 

typedef pair<int, int> pairs; 
deque<pairs> dq; 

int main(void){
	cin.tie(0);cout.tie(0);
    ios_base::sync_with_stdio(false);

	int n; 
	cin >> n; 
	for(int i=0; i<n; i++){
	    int x; 
	    cin >> x; 
	    dq.push_back(make_pair(i+1, x));
	}
	while(!dq.empty()){
	    pairs poped = dq.front();
	    cout << poped.first<< ' ';
	    dq.pop_front(); 
	    
	   for(int j=1; j<poped.second; j++){
	       dq.push_back(dq.front());
	       dq.pop_front();
	   }
	   
	   for(int j=0; j>poped.second ; j--){
	       dq.push_front(dq.back());
	       dq.pop_back();
	   }
	}
}