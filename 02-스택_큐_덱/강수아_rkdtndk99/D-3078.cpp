// 3078 좋은 친구 
#include <iostream>
#include <queue> 
#include <array> 

using namespace std; 

int main(void){
	cin.tie(0);cout.tie(0);
    ios_base::sync_with_stdio(false);

	int n, k;
	long long sumNum=0; 
	int outNum;
	string name; 
	queue<int> q;
	int arr[21] = {};   //큐 내에 있는 이름 길이 배열 
	
	cin >> n >> k; 
	
	//큐 초기화 
	for(int i=0; i<k; i++){
	    q.push(1);
	}

	for(int j=0; j<n; j++){
	    cin >> name; 
	    
	    int length1 = name.length(); 
	    sumNum += arr[length1];
	    
	    outNum = q.front();
	    q.pop();
	    q.push(length1);
	    arr[outNum]--;
	    arr[length1]++;
	}
	cout << sumNum; 
}