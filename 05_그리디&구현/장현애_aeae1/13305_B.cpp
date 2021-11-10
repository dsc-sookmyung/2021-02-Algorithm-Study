#include <iostream>
#define MAX 11
using namespace std;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main()
{
	init();
	int N;
	int road[99999];
	int city[100000];
	long long min = 1000000001, cost = 0;
	int temp;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> road[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> city[i];
	}

	for (int i = 0; i < N - 1; i++) {
		if (city[i] < min) min = city[i];
		cost += min * road[i];
	}

	cout << cost;
}
