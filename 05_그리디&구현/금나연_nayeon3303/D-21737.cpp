#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stdlib.h>

char inputs[500000];

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int N, c_ck(0), idx(0);
	string str;
	cin>>N>>str;

	for(int i=0; i<str.size(); i++){
		if(str[i]=='C') c_ck = 1;
	}

	if(!c_ck){
		cout << "NO OUTPUT";
		return 0;
	}

	int isNum(0), num(0);
	vector<int> v;
	char chars[N+1];

	for(int i=0; i<str.size(); i++){
		if(str[i]>='0' &&  str[i]<='9'){
			if(isNum == 1){
				num=num*10;
				num=num+str[i]-48;
			}
			else{
				num=str[i]-48;
			}
			isNum= 1;
		}
		else{
			if(isNum == 1){
				v.push_back(num);
				num = 0;	
			}
			chars[idx++] = str[i]; 
			isNum = 0;
		}
	}
	int ans = v[0];
	int num_idx = 1;

	for(int i=0; i<idx; i++){
		if(chars[i] == 'S'){
			ans -= v[num_idx++];
		}
		else if(chars[i] == 'M'){
			ans *= v[num_idx++];
		}
		else if(chars[i] == 'U'){
			ans /= v[num_idx++];
		}
		else if(chars[i] == 'P'){
			ans += v[num_idx++];
		}
		else if(chars[i] == 'C'){
            cout<<ans<<" ";
		}
	}

    return 0;
}