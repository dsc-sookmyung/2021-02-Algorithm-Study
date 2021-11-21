#include<iostream>
 
using namespace std;
 
int arr[130][130];
pair<int, int> ret;
 
void calc(const int& here_y, const int& here_x, const int& length) {
    int here_num = arr[here_y][here_x];
 
    if (length == 1) {
        if (arr[here_y][here_x] == 0) {
            ret.first++;
            return;
        }
        else {
            ret.second++;
            return;
        }        
    }
 
    bool check = true;
    for (int y = here_y; y < here_y + length; y++) {
        for (int x = here_x; x < here_x + length; x++) {
            if (arr[y][x] != here_num) {
                check = false;
                break;
            }
        }
        if (!check)
            break;
    }
 
    if(check)
        if (arr[here_y][here_x] == 0) {
            ret.first++;
            return;
        }
        else {
            ret.second++;
            return;
        }
    else {
        int next_lenght = length / 2;
        calc(here_y, here_x, next_lenght);
        calc(here_y + next_lenght, here_x, next_lenght);
        calc(here_y, here_x + next_lenght, next_lenght);
        calc(here_y + next_lenght, here_x + next_lenght, next_lenght);
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int N;
    cin >> N;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> arr[y][x];
        }
    }
 
    calc(0, 0, N);
 
    cout << ret.first << "\n" << ret.second;
}

