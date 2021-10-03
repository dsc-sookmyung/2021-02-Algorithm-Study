#include <iostream>

using namespace std;

void init() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int temp[1048575];
int arr[1048575];
int n, k;

void merge(int start, int end) {
    int mid = (start + end) / 2;
    int i = start, j = mid + 1, k = 0;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j])
            temp[k] = arr[i++];
        else
            temp[k] = arr[j++];
        k++;
    }

    if (i > mid)
        for (int a = j; a <= end; a++)
            temp[k++] = arr[a];
    else
        for (int a = i; a <= mid; a++)
            temp[k++] = arr[a];

    for (int a = start; a <= end; a++)
        arr[a] = temp[a - start];
}

void merge_sort(int start, int end) {
    if (start >= end) return;

    int mid = (start + end) / 2;
    merge_sort(start, mid);
    merge_sort(mid + 1, end);

    if (end - start > n / k) return;
    merge(start, end);
}

int main()
{
    init();

    int j;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> j;
        arr[i] = j;
    }

    cin >> k;

    merge_sort(0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
}