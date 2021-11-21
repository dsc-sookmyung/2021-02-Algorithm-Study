#include <cmath>
#include <iostream>

using namespace std; 

int Index(int n, int r, int c);

int main() {
	int n, r, c;
	cin >> n >> r >> c;
	cout << Index(pow(2, n), r, c);
}

int Index(int n, int r, int c) {
	if (n == 2) return r * 2 + c;

	const int blockWidth = n / 2;
	const int blockArea = blockWidth * blockWidth;
	return Index(blockWidth, r % blockWidth, c % blockWidth) + blockArea * Index(2, r / blockWidth, c / blockWidth);
}
