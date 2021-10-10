#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

stack<char> s;
string bars;
int result = 0;

int main(int argc, char const *argv[])
{
    cin >> bars;
    s.push(bars[0]);
    for (int i = 1; i < bars.length(); i++)
    {
        if (bars[i] == ')')
        {
            s.pop();
            if (bars[i - 1] == '(')
                result += s.size();
            else if (bars[i - 1] == ')')
                result++;
        }
        else
            s.push(bars[i]);
    }
    cout << result << '\n';
    return 0;
}
