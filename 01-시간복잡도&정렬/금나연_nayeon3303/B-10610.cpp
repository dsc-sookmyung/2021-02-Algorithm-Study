#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//����
bool sort_desc(char a, char b)
{
    if (a > b)
        return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    // ����
    string str;
    cin>>str;

    // 0�� ����� 3�� ��� �ľ�
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