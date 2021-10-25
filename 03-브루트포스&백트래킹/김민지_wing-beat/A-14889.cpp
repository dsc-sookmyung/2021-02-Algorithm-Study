#include <iostream>
#include <vector>
using namespace std;

int n;
int team[20][20];
int check[20];
int ans = 0x7f7f7f7f; //초기화

int getStat(vector<int> oneTeam){
    int stat = 0;
    int size = oneTeam.size();
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(i!=j){
                stat += team[oneTeam[i]][oneTeam[j]];
            }
        }
    }
    return stat;
}   

void backTracking(int depth, int index){
    if(depth == n/2) {
        vector<int> aTeam;
        vector<int> bTeam;
        for(int i=0; i<n; i++) {
            if(check[i]) aTeam.push_back(i);
            else bTeam.push_back(i);
        }
        
        int aStat = getStat(aTeam);
        int bStat = getStat(bTeam);
        ans = min(ans,abs(aStat - bStat));
        return;
    }

    for(int i=index; i<n; i++){
        if(check[i]) continue;
        check[i] = 1;
        backTracking(depth+1,i+1);
        check[i] = 0;
    }
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) 
            cin >> team[i][j];
    
    backTracking(0, 0);
    cout << ans << '\n';
}