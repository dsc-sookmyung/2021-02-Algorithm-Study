#include <iostream>
#include <utility>
#include <vector>
#include <ctype.h>   //isalpha함수 헤더파일

using namespace std;

string str, temp; 
int answer=0; 
char op='+';
bool c_exist = false; 

int main(){
    cin.tie(0), cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n; 
    cin >> n >> str; 
    
    for(int i=0; i<str.size(); i++){
        if(str[i]>='0' && str[i]<='9'){
            temp += str[i]; 
        } else{
            switch(op){
                case '+':
                    answer += stoi(temp);
                    break;
                case '-':
                    answer -= stoi(temp);
                    break;
                case '*':
                    answer *= stoi(temp);
                    break;
                case '/':
                    answer /= stoi(temp);
                    break;
            } 
            temp = "0";
            
            if(str[i]=='P') op='+';
            else if(str[i]=='S') op='-';
            else if(str[i]=='M') op='*';
            else if(str[i]=='U') op='/';
            else{
                c_exist = true; 
                op='+';
                cout << answer << " ";
            }
        }
    }
    if(!c_exist) cout << "NO OUTPUT";
}

