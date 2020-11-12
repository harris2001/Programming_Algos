#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#define INF 20000000
using namespace std;
typedef pair<int, int>ii;

priority_queue<ii,vector<ii>, greater<ii> >pq;
vector<vector<int> > dist;
vector<vector<ii> >AdjList;
void dijkstra(int s,int i){
    dist[i][s]=0;
    pq.push(ii(s,0));
    while(!pq.empty()){
        ii frontt=pq.top();
        pq.pop();
        int note=frontt.first;
        int weight=frontt.second;
        if(dist[i][note]<weight){
            continue;
        }
        for(int j=0; j<AdjList[note].size(); j++){
            ii n=AdjList[note][j];
            if(dist[i][n.first]>dist[i][note]+n.second){
                dist[i][n.first]=dist[i][note]+n.second;
            }
        }
    }
}

int main(){

    int v,e,a,s;
    scanf("%d %d %d %d",&v,&e,&a,&s);
    a--;
    s--;
    AdjList.assign(v,vector<ii>());
    dist.assign(v,vector<int>());
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            dist[i].push_back(INF);
        }
    }
//    cout<<"OK";
    int aa,b,w;
    for(int i=0; i<e; i++){
        scanf("%d %d %d",&aa,&b,&w);
        aa--;
        b--;
        AdjList[aa].push_back(ii(b,w));
        //cout<<"OK";
    }
    for(int k=0; k<v; k++){
        dijkstra(k,k);
    }
/*   for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            cout<<dist[i][j]<<" ";
        }cout<<endl;
    }
    cout<<"_______________\n";*/
    int minn=INF;
    int d;
    for(int i=0; i<v; i++){
        d=dist[a][i];
        //cout<<d<<" ";
        d+=dist[i][s];
        //cout<<d<<" ";
        d+=dist[s][i];
        //cout<<d<<" ";
        d+=dist[i][a];
            if(d<minn){
                minn=d;
            }
        //cout<<d<<endl;
    }
    printf("%d\n",minn);
return 0;
}
