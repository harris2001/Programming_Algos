#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int> > >road;
vector<bool>visited;
int dist[1005][1005];
priority_queue<pair<int, pair<int,int> > >q;
int edges = 0;

void mst(int N){
    while(!q.empty()){
        pair<int,pair<int,int> >edge = q.top();
        q.pop();
        int a,b,w;
        w = edge.first*-1;
        a = edge.second.first;
        b = edge.second.second;
        //cout<<w<<" "<<a<<" "<<b<<endl;
        if(edges<N-1&&(visited[a]==0||visited[b]==0)){
            //cout<<"okey";
            visited[a]=1;
            visited[b]=1;
            edges++;
            road[a].push_back(make_pair(b,w));
            road[b].push_back(make_pair(a,w));
            //printf("Connect: %d with %d and distance: %d\n",a,b,w);
        }
    }
}

void dfs(int node,int cost,int root,int pre){
    for(int i=0; i<road[node].size(); i++){
        if(road[node][i].first!=pre){
            int next = road[node][i].first;
            int cc=cost+road[node][i].second;
            //cout<<root<<" "<<next<<" "<<cc<<endl;
            dist[root][next]=cc;
            //printf("Root: %d to Node: %d, distance: %d\n",root,next,dist[root][next]);
            dfs(next,cc,root,node);
        }
    }
}

int main(){
    int N,M,Q;
    
    scanf("%d%d%d",&N,&M,&Q);
    
    road.assign(N+1,vector<pair<int,int> >());
    visited.assign(N+1,0);

    int a,b,w;
    
    for(int i=0; i<M; i++){
        scanf("%d%d%d",&a,&b,&w);
        q.push(make_pair(-1*w,make_pair(a,b)));
    }
    mst(N);
    for(int i=1; i<=N; i++){
        dfs(i,0,i,-1);
    }
    
    for(int i=0; i<Q; i++){
        scanf("%d%d",&a,&b);
        printf("%d\n",dist[a][b]);
    }
    
    return 0;
}
