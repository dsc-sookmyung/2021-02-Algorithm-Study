#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> results;

int operate(int i, int op1, int op2)
{
    switch (i)
    {
    case 0:
        return op1 + op2;
    case 1:
        return op1 - op2;
    case 2:
        return op1 * op2;
    case 3:
        return op1 / op2;
    }
}

void solve(vector<int> &op, const vector<int> &operands, int result, int curr)
{
    if (curr == operands.size())
    {
        results.push_back(result);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (op[i] > 0)
        {
            op[i]--;
            solve(op, operands, operate(i, result, operands[curr]), curr + 1);
            op[i]++;
        }
    }
}

int main()
{
    vector<int> op(4, 0); //operator 연산자
    vector<int> operands; //피연산자
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        operands.push_back(t);
    }

    for (int i = 0; i < 4; i++)
        cin >> op[i];

    solve(op, operands, operands[0], 1);

    int largest = results[0], smallest = results[0];
    for (int i = 0; i < results.size(); i++)
    {
        largest = max(largest, results[i]);
        smallest = min(smallest, results[i]);
    }

    cout << largest << "\n"
         << smallest;
}