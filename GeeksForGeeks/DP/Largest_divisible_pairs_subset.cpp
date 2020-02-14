#include <iostream>
#include <algorithm>

using namespace std;

int solve(int i,int dp[],int pin[]){
    //cout<<i<<endl;
    if(i==0){
        dp[i]=1;
    }
    else{
        for(int j=i-1; j>=0; j--){
            if(dp[j]==0){
                solve(j,dp,pin);
            }
            if(pin[i]%pin[j]==0){
                dp[i]=max(dp[j]+1,dp[i]);
            }
            else{
                dp[i]=max(dp[j],dp[i]);
            }
            //cout<<i<<": "<<dp[i]<<", "<<j<<": "<<dp[j]<<endl;
        }
    }
    return dp[i];
}

int main(){

    int t;
    scanf("%d",&t);
    int pin[t];
    int dp[t]={};
    for(int i=0; i<t; i++){
        scanf("%d",&pin[i]);
    }
    sort(pin,pin+t);
    printf("%d\n",solve(t-1,dp,pin));
    
    return 0;
}
