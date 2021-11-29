#include <iostream>
#include <string>
#include <vector>

using namespace std;
int N; 

pair<int,int> nodes[26]; 

void pre(char cur) { 
    if (cur == '.') return; 

    cout << cur; 

    pre(nodes[cur - 'A'].first); 
    pre(nodes[cur - 'A'].second); 
} 

void in(char cur) { 
    if (cur == '.') return; 

    in(nodes[cur - 'A'].first); 

    cout << cur; 

    in(nodes[cur - 'A'].second); 
} 

void post(char cur) { 
    if (cur == '.') return; 

    post(nodes[cur - 'A'].first); 
    post(nodes[cur - 'A'].second); 

    cout << cur; 
} 

int main() { 
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    cin >> N; 

    for (int i = 0; i < N; i++) { 
        char parent, left, right; 
        cin >> parent >> left >> right; 
        nodes[parent - 'A'] = {left, right}; 
    } 

    pre('A'); 
    cout << '\n'; 
    in('A'); 
    cout << '\n'; 
    post('A'); 

    return 0; 
}

