#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int compare(int a, int b) {
	return a > b;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K, num(0);
	cin>>N>>K;

	vector<int> v(N);

	for (int i=0;i<N;i++) {
		cin>>v[i];
	}
	sort(v.begin(), v.end(), compare);
	for (int i=0; i<N; i++) {
		while (K-v[i]>=0) {
			num++;
			K-=v[i];
		}
	}
	cout<<num<<'\n';

    return 0;
}