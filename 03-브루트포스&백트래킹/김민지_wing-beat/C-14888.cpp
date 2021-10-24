#include<iostream>
#include<algorithm>
using namespace std;

int N;
int number[12];
int operators[4];
int maxNum = INT32_MIN;
int minNum = INT32_MAX;

void Calculator(int plus, int minus, int mul, int div, int count, int sum) {
	if (count == N) {
		maxNum = max(maxNum, sum);
		minNum = min(minNum, sum);
	}

	if (plus>0){
	    Calculator(plus-1, minus, mul, div, count+1, sum+number[count]);
	} 
	if (minus>0){
	    Calculator(plus, minus-1, mul, div, count+1, sum-number[count]);
	}
	if (mul>0){
	    Calculator(plus, minus, mul-1, div, count+1, sum*number[count]);
	} 
	if (div>0){
	    Calculator(plus, minus, mul, div-1, count+1, sum/number[count]);
	}
}

int main(void) {
	ios::sync_with_stdio(false); 
	cin.tie(NULL);

	cin >> N;
	for (int i=0; i<N; i ++) {
		cin >> number[i];
	}
	for (int i=0; i<4; i++) {
		cin >> operators[i];
	}
	Calculator(operators[0], operators[1], operators[2], operators[3], 1, number[0]);

	cout << maxNum << '\n' << minNum;
}