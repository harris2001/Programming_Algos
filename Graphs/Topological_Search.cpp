#include<bits/stdc++.h>
#define MAXN 1000

using namespace std;

vector<int> topological;
bool visited[MAXN];
vector<vector<int>>graph;

//Traverses a graph by visiting the children further away from the root first
void dfs(int n){
    visited[n]=true;
    for(int i=0; i<graph[n].size(); i++){
        int child = graph[n][i];
        if(visited[child]==false){
            dfs(child);
        }
    }
    //Returns the nodes sorted topologically (first visits all the children and then adds itself
    topological.push_back(n);
}

int main(){

return 0;
}
