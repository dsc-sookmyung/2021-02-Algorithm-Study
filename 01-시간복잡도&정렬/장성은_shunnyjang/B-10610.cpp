#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int compare(int i, int j)
{
    return j < i;
}

int main()
{
    string N;
    cin >> N;

    bool isSuccess = false;
    int sum = 0;
    for (int i = 0; i < N.size(); i++)
    {
        int ntoint = N[i] - '0';
        if (ntoint == 0)
            isSuccess = true;
        sum += ntoint;
    }

    if (isSuccess && sum % 3 == 0)
    {
        sort(N.begin(), N.end(), compare);
        cout << N;
        return 0;
    }

    cout << "-1";
    return 0;
}
