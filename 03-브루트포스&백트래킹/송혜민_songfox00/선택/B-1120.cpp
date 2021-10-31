#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main() {
	string str1, str2;
	cin >> str1 >> str2;

	int res = 100;

	for (int i = 0; i <= str2.length() - str1.length(); i++) {
		int cnt = 0;
		for (int j = 0; j < str1.length(); j++) 
			if (str1[j] != str2[j + i])
				cnt++;
			res = min(res, cnt);
	}
	
	cout << res << '\n';
	return 0;
}