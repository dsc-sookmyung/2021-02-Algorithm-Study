#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MAX = 500001;
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    int N, ans=0, tmpnum;
    string s, tmp;
    char ch = '+';
    bool flag = false;
    
	cin >> N >> s;
    	
	for (int i=0; i<s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			tmp += s[i];
		} else {
			if (ch == '+') {
				ans += stoi(tmp);
			} else if (ch == '-') {
				ans -= stoi(tmp);
			} else if (ch == '*') {
				ans *= stoi(tmp);
			} else if (ch == '/') {
				ans /= stoi(tmp);
			}
			
			tmp = "0";
			
			if (s[i] == 'P') {
				ch = '+';
			} else if (s[i] == 'M') {
				ch = '*';
			} else if (s[i] == 'S') {
				ch = '-';
			} else if (s[i] == 'U') {
				ch = '/';
			} else {
				flag = true;
				ch = '+';
				cout << ans << " ";
			}
		}
	}
	if (!flag) cout << "NO OUTPUT";
}