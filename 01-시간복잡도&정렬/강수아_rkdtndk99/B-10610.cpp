//30
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string str;
    cin >> str;
    vector<int> v;

    //더해서 3의 배수인지 보기
    int total =0;
    for (int i=0; i<str.size();i++){
        total += str[i] - '0';
        v.push_back(str[i]-'0');
    }

    sort(v.begin(), v.end(), greater<int>());

    if(total%3==0 && v[str.size()-1]==0){
        for(auto i : v)
            cout << i;
    } else{
        cout << -1;
    }
}


