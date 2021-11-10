#include <iostream>
#include <string>
#include <map>

using namespace std;

int n, count=0, answer;
string expression, num, num2;
char opt = ' ';
bool output = false;

int calculation(int a, int b, char c) {
    if (c == 'S') return a-b;
    if (c == 'M') return a*b;
    if (c == 'P') return a+b;
    if (a > 0) return a/b;
    return ((a*-1) / b)*-1;
}

int main(int argc, const char** argv) {
    cin >> n >> expression;

    for (int i=0; i<expression.size(); i++) {
        if (expression[i] < 65) {
            if (opt != ' ')
                num.push_back(expression[i]);
            else
                num2.push_back(expression[i]);
        }
        else {
            if (opt != ' ' && opt != 'C') {
                answer = calculation(stoi(num2), stoi(num), opt);
                num = ' ';
            }
            if (expression[i] == 'C') {
                output=true;
                cout << answer << " ";
            }
            opt = expression[i];
        }
    }

    if (!output)
        cout << "NO OUTPUT" << endl;

    return 0;
}
