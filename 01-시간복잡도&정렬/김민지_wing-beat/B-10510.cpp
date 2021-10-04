#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    string N;
    long long sum=0;
    bool flag = false;
    
    cin >> N;
    
    for(int i=0; i<N.length(); i++){
        int n = N[i]-'0';
        if (n == 0) flag = true;
        sum += n;
    }
    
    if (!flag || (sum % 3 != 0)) cout << "-1";
    else {
        sort(N.begin(), N.end(), greater<>());
        for(auto& i :N){
            cout << i;
        }
    }
}