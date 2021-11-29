#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> v[100001];
bool visit[100001] = {false, };
int num[100001];
int node, q, s, e;

int tree(int n) {
	if (num[n] != 0) return num[n];

	visit[n] = true;
	int ret = 1;

	for (int i=0; i<v[n].size(); i++) {
		int next = v[n][i];
        
		if (visit[next]) continue;
		ret += tree(next);
	}

	num[n] = ret;

	return ret;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r;
	cin>>node>>r>>q;

	for (int i = 0; i < node - 1; i++) {
		cin>>s>>e;
		v[s].push_back(e);
		v[e].push_back(s);
	}

	num[r] = tree(r);

	for (int i=0; i<q; i++) {
		cin>>s;
		cout<<num[s]<<'\n';
	}

    return 0;
}