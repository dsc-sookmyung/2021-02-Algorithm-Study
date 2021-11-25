#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    
    int N, K, ans=0;
    cin >> N >> K;
    vector<int> v(N);
    
    for(int i=0; i<N; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < N; i++) {
		while (K - v[i] >= 0) {
			ans++;
			K -= v[i];
		}
	}
	cout << ans << '\n';
}