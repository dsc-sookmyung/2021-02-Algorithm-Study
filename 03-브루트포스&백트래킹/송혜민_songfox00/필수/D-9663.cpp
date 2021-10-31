#include<iostream>
using namespace std;
#define MAX 40

int n;
bool arr1[MAX]; 
bool arr2[MAX]; 
bool arr3[MAX]; 
int cnt = 0; 

void solve(int level) {
	if (level == n) {
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (arr1[i] || arr2[i + level] || arr3[level - i + n - 1])
			continue;
		arr1[i] = true;
		arr2[i + level] = true;
		arr3[level - i + n - 1] = true;
		solve(level + 1);
		arr1[i] = false;
		arr2[i + level] = false;
		arr3[level - i +  n- 1] = false;
	}
}

int main() {
	cin >> n;
	solve(0);
	cout << cnt;
}