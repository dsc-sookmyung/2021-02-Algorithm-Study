#include <iostream>
#include <vector>

using namespace std;

int n, k, m;
vector<int> l;

int binary_search()
{
    int start = 1, end = 1000000000, mid;
    int answer = -1;
    while (start <= end)
    {
        mid = (start + end) / 2;
        int sum = 0;
        for (int i : l)
            sum += (i / mid);
        if (sum >= m)
        {
            answer = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    return answer;
}

int main(int argc, char const *argv[])
{
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++)
    {
        int l_;
        cin >> l_;
        if (l_ < 2 * k && l_ > k)
            l.push_back(l_ - k);
        if (l_ > 2 * k)
            l.push_back(l_ - 2 * k);
    }

    cout << binary_search() << endl;

    return 0;
}
