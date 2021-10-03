#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1048577];

bool compare(int i, int j)
{
    return j < i;
}

bool isTriangle(int a, int b, int c)
{
    bool result = false;
    return a < b + c;
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N, compare);

    for (int i = 0; i < N - 2; i++)
    {
        if (isTriangle(arr[i], arr[i + 1], arr[i + 2]))
        {
            cout << arr[i] + arr[i + 1] + arr[i + 2];
            return 0;
        }
    }

    cout << "-1";
    return 0;
}
