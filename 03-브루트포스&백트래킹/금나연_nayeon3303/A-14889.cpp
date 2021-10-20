#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> status(n, vector<int>(n));
    
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            int s;
            cin >> s;
            status[i][j]=s;
        }   
    }
    // idx용
    vector<int> mem_num;
    for (int i=0;i<n;i++) {
        mem_num.push_back(i);
    } 

    // 조합용
    vector<int> v(n/2, 1);
    v.insert(v.end(), n/2, 0);
    sort(v.begin(), v.end());


    int min_diff=100;
    
    do {
        // mem_num 조합
        int total1(0), total2(0);
        vector<int> total1_vec;
        vector<int> total2_vec;

        // 조합 택
        for (int k = 0; k < n; k++) {
            if (v[k]==1) total1_vec.push_back(mem_num[k]);
            else total2_vec.push_back(mem_num[k]);
        }
        
        // 점수 계산
        for (int i=0;i<n/2;i++){
            for (int j=0;j<n/2;j++){
                if (i==j) continue;
                else{
                    total1+=status[total1_vec[i]][total1_vec[j]];
                    total2+=status[total2_vec[i]][total2_vec[j]];
                }
            }
        }

        min_diff = min(min_diff, abs(total1-total2));

	} while (next_permutation(v.begin(), v.end()));

    // 아스키 코드 때문에..
    min_diff-=48;
    cout << min_diff+'0'<< "\n";

    return 0;

}