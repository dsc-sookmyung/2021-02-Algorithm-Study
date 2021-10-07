#include <iostream>
#include <stack>
#include <string>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    // 개수
    int n;
    cin>>n;

    stack<int> stack; 
    
    // 명령어별 기능
    for(int i=0; i<n; i++) {
        string str; 
        cin >> str;

        if (str == "push") { 
            int n;
            cin >> n;
            stack.push(n);
 
        } 
        else if (str == "pop") { 
 
            if (stack.empty()) {
                cout <<-1<<endl;
            } 
            else {
                cout << stack.top() << endl;
                stack.pop();
            }
        } 
        else if (str == "size") {
            cout << stack.size() << endl;
        } 
        else if (str == "empty") {
            if (stack.empty()) {
                cout << "1" << endl;
            } 
            else {
                cout << "0" << endl;
            }
        } 
        else if (str == "top") {
            if (stack.empty()) {
                cout << "-1" << endl;
            } 
            else {
                cout << stack.top() << endl;
            }
 
        }
 
    }
    return 0;

}