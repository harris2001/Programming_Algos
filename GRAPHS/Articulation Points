#include <bits/stdc++.h>
#define INF 99999999
using namespace std;

vector<vector<int> > graph;
vector<bool>visited;
vector<vector<int> >dfs_tree;
vector<int>low;
vector<int>timetable;


void dfs(int N,int timet){

    visited[N]=1;

    bool check=true;

    for(int i=0; i<graph[N].size(); i++){
        if(visited[graph[N][i]]==0){
            dfs_tree[N].push_back(graph[N][i]);
            dfs_tree[graph[N][i]].push_back(N);
            dfs(graph[N][i],timet+1);
        }
    }
}
int timec=0;

void articulation(int N,int parent){
    int timet=timec;
    visited[N]=0;
    low[N]=timetable[N]=timet;
    bool boo=true;
    cout<<"aaaa: "<<N<<" "<<dfs_tree[N].size()<<endl;
    if(parent==-1 && dfs_tree[N].size()>1){
        printf("a: %d\n ",N);
    }
    else{
        for(int i=0; i<graph[N].size(); i++){
            int v=graph[N][i];
            
            if(visited[v]==1){timec++;
                cout<<v<<" not visited\n";
                articulation(v,N);
                low[N]=min(low[N],timetable[v]);
                cout<<N<<" <-> "<<timet<<endl;
                if(low[N]==timet&&dfs_tree[N].size()>1){
                    cout<<"Smaller\n";
                    boo=false;
                }
            }
            else if(v!=parent){
                cout<<v<<" not in dfs\n";
                low[N]=min(low[N],timetable[v]);
                cout<<N<<" <-> "<<timet<<endl;
                if(low[N]==timet&&dfs_tree[N].size()>1){
                    cout<<"Smaller\n";
                    boo=false;
                }
            }
            
        }
        cout<<N<<" "<<low[N]<<endl;
        if(boo==false){
            printf("------------> %d ",N);
        }    
    }
}

int main(){

int N,E;

scanf("%d%d",&N,&E);

graph.assign(N,vector<int>());
dfs_tree.assign(N,vector<int>());
visited.assign(N,0);
low.assign(N,0);
timetable.assign(N,0);
int a,b;

for(int i=0; i<E; i++){
    scanf("%d%d",&a,&b);
    graph[a].push_back(b);
    graph[b].push_back(a);
}
    dfs(0,0);
    printf("Articulation Points: ");
    articulation(0,-1);
    for(int i=0; i<N; i++){
        printf("%d ",low[i]);
    }
    
    return 0;
}
