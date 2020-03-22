#include<bits/stdc++.h>

using namespace std;

struct my{
    vector<int> children;
    bool inter;
};

my tree[200];
int maxn = 0;

int bfs(int Node,int prev,int k,int dist){
    queue<int>q;
    for(int i=0; i<tree[Node].children.size(); i++){
        q.push(tree[Node].children[i]);
    }
    while(!q.empty()){
        int next = q.first();
        q.pop();
        if(next!=prev&&dist+1<=k){
            if(tree[next].inter == 1){
                k--;
                maxn = max(maxn,dist);
            }
            bfs(next,Node,k,dist+1);
        }
    }
}

int main(){
    int N,k;
    
    scanf("%d%d",&N,&k);
    
    int interesting[N],countt = 0;
    
    for(int i=0; i<N; i++){
        scanf("%d",&interesting[i]);
    }
    
    int a,b;
    
    for(int i=0; i<N; i++){
        scanf("%d%d",&a,&b);
        tree[a].children.push_back(b);
        tree[b].children.push_back(a);
        tree[a].inter = interesting[a];
        tree[b].inter = interesting[b];
    }
    
    int minn=N-1;
    
    for(int i=0; i<N; i++){
        if(interesting[i]==1)
            minn = min(bfs(i,-1,k,0),minn);
    }
    printf("%d\n",minn);
    return 0;
}
