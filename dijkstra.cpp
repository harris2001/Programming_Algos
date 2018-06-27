#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int>ii;
typedef vector<ii>vi;
typedef vector<vi>vii;
priority_queue<ii,vector<ii>,greater<ii> >pq;
#define inf 1000000

vii AdjList;
vector<int>dist;

void dijkstra(int s){
    dist[s]=0;
    pq.push(make_pair(0,s));
    while(!pq.empty()){
        ii frontt = pq.top();
        pq.pop();
        int weight=frontt.first;
        int next=frontt.second;
        if(weight>dist[next]){
            continue;
        }
        for(int i=0; i<AdjList[next].size(); i++){
            ii v=AdjList[next][i];
            if(dist[next]+v.second<dist[v.first]){
                dist[v.first]=dist[next]+v.second;
                pq.push(make_pair(dist[v.first],v.first));
            }
        }

    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        AdjList.clear();
        int v,e;
        cin>>v>>e;
        AdjList.assign(v,vi());
        dist.assign(v,inf);
        int a,b,w;
        for(int i=0; i<e; i++){
            cin>>a>>b>>w;
            a--;
            b--;
            AdjList[a].push_back(make_pair(b,w));
        }
        int st,en;
        cin>>st>>en;
        st--;
        en--;
        dijkstra(st);
        if(dist[en]!=0&&dist[en]!=inf){
            cout<<dist[en]<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        /*cout<<"________________"<<endl;
        for(int jj=0; jj<v; jj++){
            cout<<dist[jj]<<endl;
        }
        cout<<"_________________\n";*/
    }


return 0;
}
