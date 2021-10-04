#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    // 개수
	int n;
	cin >> n;
	
    // 초기화 및 정렬
	for (int i=0; i<n; i++) {
		int k;
		cin>>k;
		v.push_back(k);
	}
	sort(v.begin(),v.end());

    // 총 합 계산(그리디)
	int total=0;
	for (int i=0;i<n; i++) {
		total+= v[i]*(n-i);
	}
	cout<<total;

    return 0;
}