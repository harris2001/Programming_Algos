#include <bits/stdc++.h>
#define INF 9999999
using namespace std;

vector<vector<int> >graph;
vector<bool>visited;
vector<int>dp;

void dfs(int curr,int stop,int orders){
    visited[curr]=1;
    dp[curr]=min(dp[curr],orders);
    
    if(curr==stop){
        return;
    }
    int a=0;
    for(int i=0; i<graph[curr].size(); i++){
        if(visited[graph[curr][i]]==0){
            a++;
        }
        if(a>1){break;}
    }
    for(int i=0; i<graph[curr].size(); i++){
        if(visited[graph[curr][i]]==0){
            if(a>1){
                dfs(graph[curr][i],stop,orders+1);
            }
            else{
                dfs(graph[curr][i],stop,orders);
            }
        }
    }
}

int main(){
    int n,u,v;
    scanf("%d",&n);
    graph.assign(0,vector<int>());
    visited.assign(n,false);
    dp.assign(n,INF);
    for(int i=0; i<n; i++){
        scanf("%d%d",&u,&v);
        graph[u].push_back(v);
    }
    scanf("%d%d",&u,&v);
    dp[u]=0;
    dfs(u,v,0);
    printf("%d\n",dp[v]);
    return 0;
}
