#include<vector>
#include<queue>
#include<set>
#include<iostream>
#include<stdio.h>
#define INF 99999999
using namespace std;

vector<vector<pair<int,int> > >graph;
vector<int>dist;

vector<vector<int> >timetable;
int modulos[30000];

int wait(int timer,int route,int dest){
    //cout<<"Timer = "<<timer<<"Dest= "<<dest<<": ";
    int i=timer%modulos[route];
    int ans=0;
    while(timetable[route][i]!=dest){
        timer++;
        i=timer%modulos[route];
        ans++;
    }
    //cout<<ans<<endl;
    //cout<<" Route = "<<route<<" Dest= "<<dest<<endl;
    return ans;
}

void dijkstra(int node){
    int timer=0;
    queue<pair<int,int> >q;
    q.push(make_pair(node,0));
    dist[node]=0;
    int weight;
    pair<int,int>next;
    while(!q.empty()){
        node = q.front().first;
        weight = q.front().second;
        //cout<<"Now: "<<node<<" "<<dist[node]<<endl;
        //cout<<"From: "<<node<<" to: ";

        q.pop();
        if(dist[node]<weight){
            continue;
        }
        for(int i=0; i<graph[node].size(); i++){
            next = graph[node][i];
            int ww = wait(dist[node],next.second,node);

            if(dist[next.first]>dist[node]+ww+1){
                dist[next.first]=dist[node]+ww+1;
                q.push(make_pair(next.first,dist[next.first]));
                //cout<<"push: "<<next.first<<" "<<dist[next.first]<<endl;
            }
        }
    }
}


int main(){

int nodes,trains;

scanf("%d%d",&nodes,&trains);

graph.assign(nodes+1,vector<pair<int,int> >());
dist.assign(nodes+1,INF);
timetable.assign(nodes+1,vector<int>());

int data;

for(int i=0; i<trains; i++){
    scanf("%d",&modulos[i]);
    for(int j=0; j<modulos[i]; j++){
        scanf("%d",&data);
        timetable[i].push_back(data);
        if(j==modulos[i]-1){
            graph[timetable[i][j]].push_back(make_pair(timetable[i][0],i));
        }
        if(j>0){
            graph[timetable[i][j-1]].push_back(make_pair(timetable[i][j],i));
        }
    }
}



dijkstra(1);

for(int i=2; i<=nodes; i++){
    if(dist[i]==INF){
        printf("-1 ");
        continue;
    }
    printf("%d ",dist[i]);
}printf("\n");

return 0;
}
