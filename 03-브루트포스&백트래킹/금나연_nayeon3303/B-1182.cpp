#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, s;
    cin >> n>>s;

    vector<int> nums;
    string str;
    getline(cin, str);
    getline(cin, str);
    
    istringstream ss(str);
    ss.str(str);

    // 공백 분할
    string buffer;
    while (getline(ss,buffer,' ')) {
        int value = atoi(buffer.c_str());
        nums.push_back(value);
    }

    int count(0);
    // 공집합 제외
	for (int i = 0; i < n; i++) {
		vector<bool> v(n - i, 1);
		v.insert(v.end(), i, 0);
        sort(v.begin(), v.end());

        // 원소 합과 s 같으면 count+=1
		do {
            int total(0);
			for (int k = 0; k < n; k++) {
				if (v[k]==1) total+= nums[k];
			}
			if (total==s)  count+=1;
		} while (next_permutation(v.begin(), v.end()));
	}

    cout<<count;
    return 0;

}