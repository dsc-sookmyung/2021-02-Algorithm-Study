#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long dist[100000];
long long price[100000];
long long N, total;


int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

	long long depth = 1000000000;
    cin>>N;
    
	for (int i=1; i<=N-1; i++)
		cin>>dist[i];
	for (int i=1; i<=N; i++)
		cin>>price[i];
	
	for (int i=1; i<= N-1; i++){
		if (price[i]<depth) depth=price[i];
		total+=depth*dist[i];
	}

	cout << total;

    return 0;
}