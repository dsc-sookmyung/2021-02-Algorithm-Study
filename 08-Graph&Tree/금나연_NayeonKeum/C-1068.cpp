#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, cut;
vector<int> v[51];

int tree(int curr){
	int val = 1;
	int child = 0;
	for (auto cur: v[curr]){
		if(cur==cut) continue;
		child += tree(cur);
	}
	if(child) return child;
	else return val;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    int r;
    for (int i=0; i<N; ++i){
        int parent;
        cin>>parent;
        
        if(parent==-1) r=i;
        else v[parent].push_back(i);
    }
    cin >> cut;

    if(r!=cut) cout<<tree(r)<<'\n';
    else cout<<0<<'\n';

    return 0;
}