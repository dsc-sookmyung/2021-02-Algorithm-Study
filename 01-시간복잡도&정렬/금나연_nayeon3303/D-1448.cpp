#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numList[1000000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    // ����
    int n;
	cin>>n;
	
    // �ʱ�ȭ �� ����
	for (int i=0; i<n;i++)
		cin>>numList[i];
	sort(numList, numList+n);	
	
    // ������ �� �� �� ���ϱ�
	for (int i=n-1;i>=2;i--) {
		int a=numList[i];	
		int b=numList[i-1];
		int c=numList[i-2];
		if (a<b+c) {
			cout<<a+b+c<<'\n';
			return 0;
		}
	}
	cout<<-1<<'\n';

    return 0;
}