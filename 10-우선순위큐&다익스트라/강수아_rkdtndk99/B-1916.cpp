#include <stdio.h>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int node[1005][1005];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
int value[1005];

int main(){
	int n,m;
	int u,v,w;
	int start,end;
	
	scanf("%d %d",&n,&m);
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			node[i][j] = INF;
	
	for(int i=1;i<=n;i++){
		node[i][i] = 0;
		value[i] = INF;
	}
	
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&u,&v,&w);
		if(node[u][v]>w)
		node[u][v] = w;
	}
	
	scanf("%d %d",&start,&end);
	
	value[start] = 0;
	
	pq.push(make_pair(0,start));
	
	while(!pq.empty()){
		int x = pq.top().first;
		int U = pq.top().second;
		pq.pop();
		
		for(int i=1;i<=n;i++){			
			int V = i;
			int W = node[U][i];
			
			if(W==INF) continue;
			
			if(x+W<value[V]){
				value[V] = x+W;
				pq.push(make_pair(x+W,V));
			}
		}
	}
	
	printf("%d",value[end]);
	
	return 0;
}
