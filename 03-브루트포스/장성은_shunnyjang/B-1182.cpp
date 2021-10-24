#include <iostream>
#include <vector>

using namespace std;

int n, s;
vector<int> nums;

void dfs(int sum, int idx, int leng, int &count)
{
    if (idx >= n)
        return;

    sum += nums[idx];

    if (sum == s && leng >= 1)
        count++;

    dfs(sum, idx + 1, leng + 1, count);
    dfs(sum - nums[idx], idx + 1, leng, count);
}

int main()
{
    cin >> n >> s;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        nums.push_back(t);
    }

    dfs(0, 0, 1, count);

    cout << count << endl;
}