#include <iostream> 
#include <vector> 
#include <algorithm> 

using namespace std; 
int n ,c; 
vector<int> houses; 

int main() { 
	cin.tie(0); cout.tie(0); 
	ios::sync_with_stdio(false); 
    
    cin >> n >> c;
    for (int i = 0; i < n; i++) { 
    	int temp; 
    	cin >> temp; 
        houses.push_back(temp); 
    } 
    
    sort(houses.begin(), houses.end()); 
    
    int start = 1; 
    int end = houses[n-1] - houses[0];
    int result = 0;  
    
    while (start <= end) { 
    	int mid = (start+end) / 2; 
        int cnt = 1; 
        int prev_house = houses[0]; 
        
        for (int i = 1; i < n; i++) { 
        	if (houses[i] - prev_house >= mid) { 
        		cnt++; 
                prev_house = houses[i]; 
            }
        }  
        if (cnt >= c) { 
            result = max (result, mid); 
            start = mid+1; 
        } 
        else end = mid-1; 
    } 
    cout << result; 
    return 0; 
}


