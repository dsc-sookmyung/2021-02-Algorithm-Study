// 10799 쇠막대기 
#include <iostream>
#include <stack> 
#include <string>

using namespace std; 

int main(void){
	cin.tie(0);cout.tie(0);
    ios_base::sync_with_stdio(false);

	stack<char> s; 
	string str; 
	int sum=0; 
	
	cin >> str; 
	for(int i =0; i< str.length(); i++){
	    if(str.at(i) == '(') {
	        s.push(str.at(i));
	    }
	    else{
	        if(str.at(i-1) == '('){
	            s.pop();
	            sum += s.size();
	        } else{
	            s.pop();
	            sum +=1; 
	        }
	    }
	}
	cout << sum; 
}