#include <iostream>
#include <string>
#include <map>

using namespace std;

int n, count=0;
string expression, num, answer;
char opt = ' ';
bool output = false;

string calculation(int a, int b, char c) {
    if (c == 'S') return to_string(a-b);
    if (c == 'M') return to_string(a*b);
    if (c == 'P') return to_string(a+b);
    if (a > 0) return to_string(a/b);
    return to_string(((a*-1) / b)*-1);
}

int main(int argc, const char** argv) {
    cin >> n >> expression;

    for (int i=0; i<expression.size(); i++) {
        if (expression[i] < 65) {
            if (opt != ' ')
                num.push_back(expression[i]);
            else
                answer.push_back(expression[i]);
        }
        else {
            if (opt != ' ' && opt != 'C') {
                answer = calculation(stoi(answer), stoi(num), opt);
                num = ' ';
            }
            if (expression[i] == 'C') {
                output=true;
                cout << stoi(answer) << " ";
            }
            opt = expression[i];
        }
    }

    if (!output)
        cout << "NO OUTPUT" << endl;

    return 0;
}
