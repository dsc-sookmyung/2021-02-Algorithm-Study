#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    // ����
	int n;
	cin >> n;
	
    // �ʱ�ȭ �� ����
	for (int i=0; i<n; i++) {
		int k;
		cin>>k;
		v.push_back(k);
	}
	sort(v.begin(),v.end());

    // �� �� ���(�׸���)
	int total=0;
	for (int i=0;i<n; i++) {
		total+= v[i]*(n-i);
	}
	cout<<total;

    return 0;
}