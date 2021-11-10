#include <stdio.h>


int main(void) {
	int coins[10];
	int n, k, num, coin, count;

	count = 0;
	scanf_s("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &num);
		coins[i] = num;
	}

	while (k != 0) {
		for (int j = 0; j < n; j++) {
			if (coins[j] <= k) {
				coin = coins[j];
			}
		}
		count += (k / coin);
		k = k % coin;
	}
	printf("%d", count);
}