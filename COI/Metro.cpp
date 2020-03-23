#include<bits/stdc++.h>

using namespace std;

priority_queue< pair< int,pair<int,int> > >pq;
vector<vector<pair<int,int> > >graph;
vector<bool>visited;
int dist[1005][1005];

void mst(){
        while(!pq.empty()){
                pair <int, pair <int,int> >pp = pq.top();
                pq.pop();
                int w = pp.first * -1;
                int a = pp.second.first;
                int b = pp.second.second;
                if(visited[a] == 0|| visited[b] == 0){
                        graph[a].push_back(make_pair(b,w));
                        graph[b].push_back(make_pair(a,w));
                        visited[a] = visited[b] = 1;
                        //cout<<a<<" "<<b<<" "<<w<<endl;
                }
        }
}

void bfs(int node,int prev,int cost,int root){
        queue< pair< int, int > > q;
        dist[root][node]=cost;
        //cout<<"DIST: "<<root<<" "<<node<<": "<<cost<<endl;
        for(int i=0; i<graph[node].size(); i++){
                if(graph[node][i].first != prev)
                        q.push(graph[node][i]);
        }
        while(!q.empty()){
                int next = q.front().first;
                int w = q.front().second;
                q.pop();
                if(next!=node)
                        bfs(next,node,cost+w,root);
        }
}

int main(){

int N,M,Q;

scanf("%d%d%d",&N,&M,&Q);

graph.assign (N+1 , vector<pair<int, int> >());
visited.assign (N+1 , 0);

int a,b,w;

for(int i=0; i<M; i++){
        scanf("%d%d%d",&a,&b,&w);
        pq.push (make_pair (-1*w , make_pair(a,b)));
}
mst();

for(int i=1; i<=N; i++){
        bfs(i,-1,0,i);
}

for(int i=0; i<Q; i++){
        scanf("%d%d",&a,&b);
        printf("%d\n",dist[a][b]);
}

        return 0;
}
