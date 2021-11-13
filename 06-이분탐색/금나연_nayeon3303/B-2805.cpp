#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;


vector<int> tree;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin>>N>>M; 
    for(int i=0; i<N; i++) { 
        int x; 
        cin>>x; 
        tree.push_back(x); 
    } 

    int start(0), result(0); 
    int end= *max_element(tree.begin(),tree.end()); 

    while(start<=end) { 
        long long int total(0); 
        int mid=(start+end)/2; 
        for (int i=0;i<N;i++) { 
            if (tree[i]>mid) {
                total += tree[i]-mid; 
            }
        } 
        if (total<M) { 
            end=mid-1; 
        } else { 
            result=mid; 
            start=mid+1; 
        } 
    } 
    
    cout<<result;

    return 0;
}
