#include<vector>
#include<queue>
#include<set>
#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

vector<vector<int> >graph;
vector<bool>visited;
int ans=0;

void dfs(int node,int K){
    //cout<<node<<endl;
    int next;
    visited[node]=1;
    for(int i=0; i<graph[node].size(); i++){
        next = graph[node][i];
        if(next==K){
            ans++;
            break;
            //cout<<"HIT"<<endl;
        }
        if(visited[next]==0){
            dfs(next,K);
        }
    }
}

int main(){

int N,M,K,a,b;

//scanf("%d%d%d",&N,&M,&K);
cin>>N>>M>>K;
graph.assign(N,vector<int>());

set<int>touch;
set<int>::iterator it;

for(int i=0; i<M; i++){
    //scanf("%d%d",&a,&b);
    cin>>a>>b;
    if(a==2){
        continue;
    }
    if(b==2){
        touch.insert(a);
    }

    graph[a].push_back(b);
}
vector<int>ans_v;
for(it=touch.begin(); it!=touch.end(); it++){
    visited.assign(N,0);
    ans = 0;
    int n=*it;
    dfs(n,K);

    if(ans==1){
        ans_v.push_back(*it);
    }
}
cout<<ans_v.size()<<endl;
sort(ans_v.begin(),ans_v.end());
for(int i=0; i<ans_v.size(); i++){
    cout<<ans_v[i]<<endl;
}

return 0;
}/*6 9 2
0 1
0 3
0 2
1 3
1 2
3 4
4 2
1 5
5 2
*/
