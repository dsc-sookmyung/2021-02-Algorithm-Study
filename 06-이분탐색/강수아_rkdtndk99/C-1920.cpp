#include<iostream>
#include<algorithm>
 
using namespace std;
 
int arr[100001];
int arr2[100001];
 
void binarySearch(const int & n, const int & k) {
    int first = 0;
    int last = n - 1;
    int mid = 1;
    while (first <= last) {
        mid = (first + last) / 2;
        if (arr[mid] == k) {
            cout << "1\n";
            return;
        }
        else {
            if (arr[mid] > k)
                last = mid - 1;
            else
                first = mid + 1;
        }
    }
    cout << "0\n";
    return;
}
 
int main() {
	cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
 
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }
 
    sort(arr, arr + n);
    for (int i = 0; i < m; i++) {
        binarySearch(n, arr2[i]);
    }
 
}
