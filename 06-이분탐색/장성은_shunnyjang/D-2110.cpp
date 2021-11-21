#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int n, c;
    int x[200001];
    int start = 1, end = 1, mid;
    int distance = 0, answer = 0;

    cin >> n >> c;
    for (int i = 0; i < n; i++)
        cin >> x[i];

    sort(x, x + n);
    end = x[n - 1] - x[0];

    while (start <= end)
    {
        mid = (start + end) / 2;
        int first_house = x[0];
        int count = 1;
        for (int i = 1; i < n; i++)
        {
            distance = x[i] - first_house;
            if (mid <= distance)
            {
                count++;
                first_house = x[i];
            }
        }

        if (count >= c)
        {
            answer = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
    }

    cout << answer << endl;
    return 0;
}