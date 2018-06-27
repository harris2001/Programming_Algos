#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

typedef vector<int>vi;
typedef vector<vi>vii;

vii AdjList;
vi visited;
int pin[20000][20000];
int countt=0;

void dfs(int s,int m){
    visited[s]=1;
    countt--;
    //cout<<countt<<endl;
    for(int j=0; j<AdjList[s].size(); j++){
        if(visited[AdjList[s][j]]==0){
            dfs(AdjList[s][j],m);
        }
    }
}

int main(){
int n,m,q;
scanf("%d %d %d",&n,&m,&q);
AdjList.assign(n*m+10,vi());
visited.assign(n*m+10,0);
for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
        scanf("%d",&pin[i][j]);
    }
}
int form;
for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
        form=m*i-(m-j);
        if(pin[i][j]==1){
            countt++;
            if(pin[i-1][j]==1){
                AdjList[form].push_back((m*(i-1)-(m-j)));
            }
            if(pin[i][j-1]==1){
                AdjList[form].push_back((m*i-(m-(j-1))));
            }
            if(pin[i+1][j]==1){
                AdjList[form].push_back((m*(i+1)-(m-j)));
            }
           if(pin[i][j+1]==1){
                AdjList[form].push_back((m*i-(m-(j+1))));
            }
        }
    }
}
int x,y;
for(int i=0; i<q; i++){
    scanf("%d %d",&x,&y);
    if(visited[m*x-(m-y)]==0&&pin[x][y]==1){
            //cout<<"ok";
        dfs(m*x-(m-y),m);
    }
    printf("%d\n",countt);
}


return 0;
}
