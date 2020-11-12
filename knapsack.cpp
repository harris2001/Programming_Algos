#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
long long int v,t;
//cin>>v>>t;
scanf("%lld %lld",&v,&t);
pair<long long int,long long int> pin[t];
for(long long int i=1; i<=t; i++){
    //cin>>pin[i].first>>pin[i].second;
    scanf("%lld %lld",&pin[i].first,&pin[i].second);
}
long long int dp[t][v+1];
long long int ff;
for(long long int i=0; i<=t; i++){
    for(long long int f=0; f<=v; f++){
        if(i==0||f==0){
            dp[i][f]=0;
        }
        else if(pin[i].first<=f){
            ff=pin[i].first;
//                cout<<pin[i].second<<endl;
            dp[i][f]=max(pin[i].second+dp[i-1][f-ff],dp[i-1][f]);
        }
        else{dp[i][f]=dp[i-1][f];}
        //cout<<i<<","<<f<<":"<<dp[i][f]<<" ";
    }//cout<<endl;
}
//cout<<dp[t-1][v-1]<<"\n";
printf("%lld",dp[t][v]);

return 0;
}
