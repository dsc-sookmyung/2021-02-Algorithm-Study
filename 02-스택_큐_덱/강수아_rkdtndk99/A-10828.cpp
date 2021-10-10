// 10828 스택
#include <iostream>
#include <stack> 
#include <string>

using namespace std; 

int main(void){
	cin.tie(0);cout.tie(0);
    ios_base::sync_with_stdio(false);

	stack<int> s; 
	int N;
	cin >> N;

    for (int i=0; i<N; i++){
        string command ;
        cin >> command;
        
        if (command == "push"){
            int n; 
            cin >> n; 
            s.push(n);
        } else if (command == "pop"){
            if(s.empty()) cout << -1 << "\n";
            else{
                cout << s.top() << "\n";
                s.pop();
            }
        } else if (command == "size") cout << s.size() << "\n";
        else if (command == "empty"){
            if (s.empty()) cout << 1 << "\n";
            else cout << 0 << "\n"; 
        } else if (command == "top"){
            if(s.empty()) cout << -1 << "\n";
            else{
                cout << s.top() << "\n";
            }
        }
    }	
}