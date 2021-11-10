#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main(){
    cin.tie(0), cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n, k, x;
    int count = 0; 
    
    cin >> n >> k; 
    
    for(int i=0; i<n; i++){
        cin >> x ;
        v.push_back(x);
    }
    
    sort(v.begin(), v.end(), greater<int>());
    
    for(int i=0; i<n; i++){
        while(k-v[i] >= 0){   
            k = k-v[i];
            count++; 
        }
    }
    cout << count; 
}

