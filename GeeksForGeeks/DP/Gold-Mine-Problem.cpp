#include <bits/stdc++.h>
using namespace std;

int pin[105][105];
int dp[105][105];
int n,m;

int solve(int i,int j){
    //cout<<i<<" "<<j<<endl;
    if(i==0||j==0||i>n||j>m){
        return 0;
    }
    if(j==1){
        dp[i][j]=pin[i][j];
        return dp[i][j];
    }
    else{
        if(dp[i-1][j-1]==-1){
            solve(i-1,j-1);
        }
        if(dp[i][j-1]==-1){
            solve(i,j-1);
        }
        if(dp[i+1][j-1]==-1){
            solve(i+1,j-1);
        }
        dp[i][j]=max(dp[i-1][j-1],max(dp[i][j-1],dp[i+1][j-1]))+pin[i][j];
        //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
    }
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--){
	    dp[n][m]={};
	    scanf("%d%d",&n,&m);
	    pin[n+2][m+2]={};
	    for(int i=1; i<=n; i++){
	        for(int j=1; j<=m; j++){
	           scanf("%d",&pin[i][j]);
	           dp[i][j]=-1;
	        }
	    }
	    int maxn=0;
	    for(int i=1; i<=n; i++){
	        solve(i,m);
	        maxn=max(maxn,dp[i][m]);
	    }
	    printf("%d\n",maxn);
	}
	return 0;
}
