#include<iostream>
using namespace std;

int N;
int cnt=0;
bool isUsed1[40]; //같은 열에 퀸 존재 여부
bool isUsed2[40]; //우상 대각선에 퀸 존재 여부
bool isUsed3[40]; //좌상 대각선에 퀸 존재 여부

void Queen(int level){
    if(level==N){
        cnt++;
        return;
    }
    for(int i=0; i<N; i++){
        if(isUsed1[i] || isUsed2[i+level] || isUsed3[level-i+N-1]) continue;
        isUsed1[i] = true;
        isUsed2[i+level] = true;
        isUsed3[level-i+N-1] = true;
        
        Queen(level+1);
        isUsed1[i] = false;
        isUsed2[i+level] = false;
        isUsed3[level-i+N-1] = false;
    }
}

int main(void) {
	ios::sync_with_stdio(false); 
	cin.tie(NULL);

	cin >> N;
	Queen(0);
	cout << cnt;
}