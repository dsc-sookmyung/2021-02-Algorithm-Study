#include <iostream>
#include <algorithm>

using namespace std;

int temp[1048577];
int arr[1048577];
int N, k, bundle;

void merge(int start, int end)
{
    if (end - start > bundle)
        return;

    int mid = (start + end) / 2;
    int i = start, j = mid + 1, k = start;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    if (i > mid)
    { //i가 먼저 데이터를 모두 넣어서 j가 남았을 경우
        for (int a = j; a <= end; a++)
        {
            temp[k] = arr[a];
            k++;
        }
    }
    else
    { //j가 먼저 데이터를 모두 넣어서 i가 남았을 경우
        for (int a = i; a <= mid; a++)
        {
            temp[k] = arr[a];
            k++;
        }
    }

    for (int a = start; a <= end; a++) //정렬된 배열을 원래의 배열에 복사
        arr[a] = temp[a];
}

void merge_sort(int start, int end)
{
    if (start >= end) // 개수가 1개일 때
        return;
    int mid = (start + end) / 2;
    merge_sort(start, mid);
    merge_sort(mid + 1, end);
    merge(start, end);
}

int main(void)
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    cin >> k;

    bundle = N / k;

    merge_sort(0, N - 1);
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}