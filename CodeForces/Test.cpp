#include<bits/stdc++.h>

using namespace std;

vector<vector<long long int> >graph;
bool visited[200005];

struct my{
    long long int zero=999999999;
    long long int one=9999999999;
};

vector<my>supvec;
//vector<my>::iterator it1,it2;

void solve(long long int n,my dp[],long long int N,long long int prev,long long int check[]){
    //cout<<n<<endl;
    visited[n]=true;
        //cout<<n<<endl;
    dp[n].zero=min(dp[n].zero,dp[prev].zero+1);
    dp[n].one=min(dp[n].one,dp[prev].one+1);
    if(n==1){
        dp[n].zero=0;
    }
    if(n==N){
        dp[n].one=0;
    }
    for(long long int i=0; i<graph[n].size(); i++){
            long long int next=graph[n][i];
        if(visited[next]==0){
            solve(next,dp,N,n,check);
        }
        dp[n].zero=min(dp[next].zero+1,dp[n].zero);
        dp[n].one=min(dp[next].one+1,dp[n].one);
    }
    if(check[n]==1){
        supvec.push_back(dp[n]);
    }
    //cout<<n<<": "<<dp[n].zero<<"/"<<dp[n].one<<endl;
}

int main(){

long long int N,M,K;

scanf("%lld%lld%lld",&N,&M,&K);

graph.assign(N+1,vector<long long int>());

long long int a,b,super[K],check[N+1]={};

for(long long int i=0; i<K; i++){
    scanf("%lld",&super[i]);
    check[super[i]]=1;
}

bool stop=false;

for(long long int i=0; i<M; i++){
    scanf("%lld%lld",&a,&b);
    graph[a].push_back(b);
    graph[b].push_back(a);
    if(check[super[a]]==1 && check[super[b]]==1){
        stop=true;
    }
}
my dp[N+1]={};
//cout<<"ok";
solve(N,dp,N,0,check);

if(stop==true){
    printf("%lld\n",dp[N].one);
}
else{
    long long int ans=9999999999;
    long long int ii,jj;
    sort(supvec.begin(),supvec.end());
    long long int it1=supvec.back().one;
    supvec.pop_back();
    long long int it2=supvec.back().one;
    printf("%lld",abs(it1-it2)-1);
    /*for(long long int i=0; i<K; i++){
        for(long long int j=i+1; j<K; j++){
            //cout<<super[i]<<" "<<super[j]<<endl;
            bool bb=false;
                for(long long int k=0; k<graph[super[i]].size(); k++){
                    if(graph[super[i]][k]==super[j]){bb=true;}
                }
            if(bb==true){
                ans=0;
                i=K+1;
                j=K+1;
                break;
            }
            else{
                ans=min(abs(dp[super[i]].one-dp[super[j]].one)-1,ans);
            }
        }
    }*/
    long long int ka=0;
    ans=max(ka,ans);
    printf("%lld\n",dp[N].zero-ans);
}
return 0;
}
