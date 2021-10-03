#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

void init(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int main(){
    int num;
    cin >> num;
    vector<int> v;

    for (int i =0; i<num; i++){
        int input;
        cin>> input;
        v.insert(v.begin() + i, input);
    }

    sort(v.begin(), v.end(), greater<int>());

    for(int i : v){
        cout << i << '\n';
    }
}