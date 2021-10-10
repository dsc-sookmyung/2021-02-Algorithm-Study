#include <iostream>
#include <stack>

using namespace std;

stack<int> s;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;
        if (input == "push")
        {
            int num;
            cin >> num;
            s.push(num);
        }
        else if (input == "pop")
        {
            if (s.empty())
                cout << "-1\n";
            else
            {
                cout << s.top() << '\n';
                s.pop();
            }
        }
        else if (input == "size")
            cout << s.size() << '\n';
        else if (input == "empty")
            cout << s.empty() << '\n';
        else if (input == "top")
        {
            if (s.empty())
                cout << "-1\n";
            else
                cout << s.top() << '\n';
        }
    }

    return 0;
}
