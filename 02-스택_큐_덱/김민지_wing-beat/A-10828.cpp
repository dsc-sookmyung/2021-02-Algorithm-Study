#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int N, num;
    cin >> N;
    
    string input;
    stack<int> s;
    
    for(int i=0; i<N; i++){
        cin >> input;
        
        if(input=="push"){
            cin >> num;
            s.push(num);
        } else if (input == "pop"){
            if(s.empty()==true){ 
                cout << "-1" << '\n';
            } else {
                cout << s.top() << '\n';
                s.pop();   
            }
        } else if (input == "size"){
            cout << s.size() <<'\n';
        } else if (input == "empty"){
            cout << s.empty() << '\n';
        } else if (input=="top"){
            if(s.empty() == true){
                cout << "-1" << '\n';
            } else{
                cout << s.top() << '\n';
            }
        }
    }
}
