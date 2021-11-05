#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v;
vector <int> dp;


int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    int N;
	cin>>N;

	for (int i=0; i<N; i++) {
		int temp; 
        cin>>temp;
		v.push_back(temp);
	}

	dp.push_back(1);

	for (int i=1; i<N; i++) {
		dp.push_back(1);
		for (int j=i; j>=0; j--) 
			if (v[j]<v[i]) {
				dp[i]=max(dp[i], dp[j]+1);
			}
	}

	sort(dp.begin(), dp.end(), greater<int>());

	cout << dp[0];

    return 0;
}