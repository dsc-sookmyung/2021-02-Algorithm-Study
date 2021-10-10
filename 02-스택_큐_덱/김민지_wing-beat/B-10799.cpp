#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    stack<char> s;
    int bar = 0;
    string input;
    cin >> input;
    
    for(int i=0; i<input.length(); i++){
        if(input[i] == '('){
            s.push('(');
        } else if (input[i] == ')'){
            if(input[i-1] == '('){
                bar+=s.size()-1;
                s.pop();
            } else{
                bar++;
                s.pop();
            }
        }
    }
    cout << bar;
}
