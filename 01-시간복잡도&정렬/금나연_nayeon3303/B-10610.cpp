#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//정렬
bool sort_desc(char a, char b)
{
    if (a > b)
        return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    // 개수
    string str;
    cin>>str;

    // 0의 존재와 3의 배수 파악
    int total(0);
    bool isZero=false;
    for (int i=0;i<str.size();i++){
        total+=(str[i]-'0');
        if ((str[i]-'0')==0){
            isZero=true;
        }
    }

    if (!isZero || total%3!=0){
        cout<<-1<<'\n';
    }
    else{
        sort(str.begin(), str.end(), sort_desc);
        cout<<str<<'\n';
    }

    return 0;
}