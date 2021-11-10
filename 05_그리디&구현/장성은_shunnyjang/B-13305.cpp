#include <iostream>
#include <vector>

using namespace std;


int main(int argc, const char** argv) {
    long long distance[99999], gas[100000];
    long long n, price;

    cin >> n;
    for (int i=0; i<n-1; i++)
        cin >> distance[i];
    for (int i=0; i<n; i++)
        cin >> gas[i];

    long long lower_cost=gas[0];
    price = lower_cost*distance[0];
    for (int i=1; i<n; i++) {
        if (gas[i] < lower_cost)
            lower_cost = gas[i];
        price += lower_cost * distance[i];
    }
    cout << price << endl;
    return 0;
}
