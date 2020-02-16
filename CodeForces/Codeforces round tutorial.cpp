#include <bits/stdc++.h>

using namespace std;

struct doo{
    int data;
    bool filled=0;
}
doo dp[1000003][2];
int ans;

int solve(int pos, int occ[],int N){
    ans=0;
    //dp[pos][0].filled=dp[pos][1].fille=1;
    if(pos>N-3){
        dp[pos][0].data=0;
        dp[pos][1].data=occ[pos]/3;
    }
    else{
        int opt0=occ[pos]/3;
        if(!dp[pos][0].filled){
            int minn=min()
            solve(pos,)
        }
        int opt1=min(dp[])
        dp[pos][0]=max(opt0,opt1)
    }
    dp[pos]=max()
}

int main(){
    
    int N,M;
    
    scanf("%d",&N,&M);
    
    int pin[N]={},occ[M]={};
    
    for(int i=0; i<N; i++){
        scanf("%d",&pin[i]);
        occ[pin[i]]++;
    }
    
    solve(i)
    
    return 0;
}
