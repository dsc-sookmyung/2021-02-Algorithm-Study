#include <iostream>
#include <algorithm>

using namespace std;

long long km[100000];
long long pr[100000]; 

int main(){
    cin.tie(0), cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    long long total = 0; 
    int n;
    cin >> n; 
    for(int i=0; i<n-1; i++){
        cin >> km[i];
    }
    for(int i=0; i<n; i++){
        cin >> pr[i];
    }

    long long pr_now = pr[0]; 
    for (int i=1; i<n; i++){
        if(pr_now > pr[i]){
            total += pr_now * km[i-1];
            pr_now = pr[i];
        } else{
            total += pr_now * km[i-1];
        }
    }
    
    cout << total; 
}

