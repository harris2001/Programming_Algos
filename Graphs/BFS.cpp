#include<bits/stdc++.h>
#define MAXN 1000

using namespace std;

bool visited[MAXN];
vector<vector<int>>graph;

//Traverses a graph by visiting all the children of a node and then proceeding to the grandchildren
void bfs(int n){
    visited[n]=0;
    //We create a queue to store all children of a node we visit
    queue<int>q;
    //First node to visit is the node we start the BFS from
    q.push_back(n,0);
    //While there are nodes to explore, keep exploring
    while(!q.empty()){
        int node = q.front();
        q.pop_front();
        //For every children of the node we are currently add do the following:
        for(int i=0; i<graph[node].size(); i++){
            int child = graph[node][i];
            //Add all children of a node we haven't visited in the queue
            if(!visited[child])
                q.push_back(child);
        }
    }
}

int main(){
    return 0;
}