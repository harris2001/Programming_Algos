#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define INF 1000005
using namespace std;

vector<vector<pair<int,int> > >graph;
vector<bool> visited;
vector<int> dist;

void dijkstra(int S,int E){
    queue<pair<int,int> >q;
    q.push(make_pair(0,S));
    dist[S]=0;
    while(!q.empty()){
        int node = q.front().second;
        int weight = q.front().first;
        q.pop();
        //cout<<node<<endl;
        if(weight>dist[node]){
            continue;
        }
        for(int i=0; i<graph[node].size(); i++){
            pair<int,int>next = graph[node][i];
            if(dist[next.first]>dist[node]+next.second){
                dist[next.first]=dist[node]+next.second;
                q.push(make_pair(dist[next.first],next.first));
            }
        }
    }
}    
  
int main(){
    
    int N,M,S,E,a,b;
    
    scanf("%d%d%d%d",&N,&M,&S,&E);
    
    graph.assign(N,vector<pair<int,int> >());
    visited.assign(N,0);
    dist.assign(N,INF);
    string s;
    
    for(int i=0; i<M; i++){
        scanf("%d%d",&a,&b);
        cin>>s;
        if(s=="apple"){
            graph[a].push_back(make_pair(b,1));
            graph[b].push_back(make_pair(a,1));    
        }
        else{
            graph[a].push_back(make_pair(b,0));
            graph[b].push_back(make_pair(a,0));
        }
    }
    
    dijkstra(S,E);
    printf("%d\n",dist[E]);
    return 0;
}
