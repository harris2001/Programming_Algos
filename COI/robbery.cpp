#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>

#define mxN 100009

using namespace std;

typedef long long int ll;
typedef pair<ll,ll>pp;

ll dist[mxN][mxN];
vector<vector<pp> >graph;

void dijkstra(ll node){
    queue<pp>q;
    q.push(make_pair(node,0));
    while(!q.empty()){
        ll curr = q.front().first;
        ll cost = q.front().second;
        q.pop();
        if(cost>dist[curr]){
            continue;
        }
        for(int i=0; i<graph[curr].size(); i++){
            pp next = graph[curr][i];
            if(dist[next.first][road]>cost+next.second){
                dist[next.first][road]=cost+next.second;
                q.push(make_pair(next.first,dist[next.first]));
            }
        }
    }
}


int main(){

ll N,E,A,S;
scanf("%lld %lld %lld %lld",&N,&E,&A,&S);

graph.assign(N,vector<pp>());

ll a,b,w;
for(ll i=0; i<E; i++){
    scanf("%lld %lld %lld",&a,&b,&w);
    graph[a].push_back(make_pair(b,w));
}
    
    return 0;
}
