#include <iostream>

using namespace std;

int n;
int board[15];
int answer;

bool possible(int line)                 // 해당 행에 퀸을 놓을 수 있는지 확인
{
    for(int i = 0 ; i < line ; i++)     // 이전 행들의 퀸의 자리와 비교하면서 검사
    {
        if(board[line] == board[i]) return false;               // 같은 열에 있으면 불가능
        if(line - i == board[line] - board[i]) return false;    // 좌상향 ( \ ) 방향에 있으면 불가능
        if(line + board[line] == i + board[i]) return false;    // 우상향 ( / ) 방향에 있으면 불가능
    }

    return true;
}

void dfs(int line)                  // 각 행 별로 퀸을 놓을 위치를 결정하는 재귀함수
{
    if(line == n)                   // 모든 줄을 다 채웠으면 +1
    {
        answer++;
        return;
    }

    for(int i = 0 ; i < n ; i++)    // 해당 행에서 퀸을 놓을 수 있는 n 개의 자리를 모두 검사
    {
        board[line] = i;            // 해당 행의 i 번째 열에 퀸을 놓았다고 치고
        if(possible(line))          // 그 위치가 가능한 위치면
        {
            dfs(line + 1);          // 다음 위치를 검사
        }
    }
}

int main(void)
{
    cin >> n;
    
    dfs(0);     // 첫번째 줄부터 시작
    
    cout << answer << endl;
}
