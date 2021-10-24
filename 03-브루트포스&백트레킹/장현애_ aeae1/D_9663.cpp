#include <iostream>
using namespace std;
#define MAX 40

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int N;
bool isused1[MAX];		// ���� ���� ���� �����ϴ��� ����
bool isused2[MAX];		// ��� �밢���� ���� �����ϴ��� ����
bool isused3[MAX];		// �»� �밢���� ���� �����ϴ��� ����
int cnt = 0;

void play(int level) {
	if (level == N) {
		cnt++;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (isused1[i] || isused2[i + level] || isused3[level - i + N - 1]) continue;
		isused1[i] = true;
		isused2[i + level] = true;
		isused3[level - i + N - 1] = true;
		
		play(level + 1);

		isused1[i] = false;
		isused2[i + level] = false;
		isused3[level - i + N - 1] = false;
	}
}

int main()
{
	init();

	cin >> N;
	play(0);
	cout << cnt;

	return 0;
}