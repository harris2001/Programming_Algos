#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > graph;
vector<bool>visited;

vector<vector<int> >dfs_tree;

void dfs(int N){
    visited[N]=1;
    for(int i=0; i<graph[N].size(); i++){
        if(visited[graph[N][i]]==0){
            dfs_tree[N].push_back(graph[N][i]);
            dfs_tree[graph[N][i]].push_back(N);
            dfs(graph[N][i]);
        }
    }
}

int main(){

int N,E;

scanf("%d%d",&N,&E);

int a,b;

for(int i=0; i<E; i++){
    scanf("%d%d",&a,&b);
    graph[a].push_back(b);
    graph[b].push_back(a);
}
    dfs(0);
    
    
    return 0;
}
