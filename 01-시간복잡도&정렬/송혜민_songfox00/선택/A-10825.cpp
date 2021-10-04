#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

struct student {
	string name;
	int korean, english, math;
};

bool cmp(student a, student b) {
	if (a.korean == b.korean && a.english == b.english && a.math == b.math)
		return a.name < b.name;
	else if (a.korean == b.korean && a.english == b.english)
		return a.math > b.math;
	else if (a.korean == b.korean)
		return a.english < b.english;

	return a.korean > b.korean;
}

int main() {
	int n;
	cin >> n;

	vector<student>v;
	v.resize(n + 1);

	for (int i = 0; i < n; i++) {
		cin >> v[i].name >> v[i].korean >> v[i].english >> v[i].math;
	}
	
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << v[i].name << '\n';
	}

	return 0;
}