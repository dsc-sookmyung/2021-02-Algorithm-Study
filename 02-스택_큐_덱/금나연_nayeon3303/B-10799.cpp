#include <iostream>
#include <stack>
#include <string>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

	stack<char> stack;
	int total(0);

	// 개수
    string str;
	cin >> str;

	for (int i(0); i<str.length(); i++) {
		if (str[i] == '(') {
			stack.push(str[i]);
		}
		// 레이저
		else if(str[i]==')' && str[i-1]=='('){
			stack.pop();
			total += stack.size();
		}
		else {
			total++;
			stack.pop();
		}
	}
	cout<<total<< endl;
    return 0;

}