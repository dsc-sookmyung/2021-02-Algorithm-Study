#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int a[100001], b[100001];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);

    sort(a, a + n);

    for (int i = 0; i < m; i++)
    {
        int start = 0, end = n, mid;
        int target = b[i];
        int flag = false;
        while (start <= end)
        {
            mid = (start + end) / 2;
            if (target > a[mid])
                start = mid + 1;
            else if (target < a[mid])
                end = mid - 1;
            else
            {
                printf("1\n");
                flag = true;
                break;
            }
        }
        if (!flag)
            printf("0\n");
    }
    return 0;
}
