#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(int i, int j)
{
    return j < i;
}

int main(void)
{
    int N;
    scanf("%d", &N);
    vector<int> number;

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &number[i]);
    }

    sort(number.begin(), number.end(), compare);
    unique(number.begin(), number.end());

    for (int i = 0; i < N; i++)
    {
        printf("%d\n", number[i]);
    }
    return 0;
}