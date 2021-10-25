#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
 
    vector<int> numlist, oplist;
    int temp, Min(1000000000), Max(-100000000);
	int n;
	cin >> n;

	for (int i=0; i < n; i++) {
		cin >>temp;
		numlist.push_back(temp);
	}
	for (int i=0; i<4; i++) {
		cin >> temp;
		for (int j=0;j <temp; j++)
			oplist.push_back(i);
	}
 
	do {
		int result = numlist[0];
		for (int i = 0; i < n - 1; i++) {
			if (oplist[i] == 0)
				result+=numlist[i + 1];
			else if (oplist[i] == 1)
				result-=numlist[i + 1];
			else if (oplist[i] == 2)
				result*=numlist[i + 1];
			else if (oplist[i] == 3)
				result/=numlist[i + 1];
		}
		Min = min(Min, result);
		Max = max(Max, result);
	} while (next_permutation(oplist.begin(), oplist.end()));
	cout << Max << '\n' << Min;
 
	return 0;
}