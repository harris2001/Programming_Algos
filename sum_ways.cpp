#include <stdio.h>
#include <iostream>
#define INF 9999999

using namespace std;

typedef long long int ll;
ll aa=1;
ll pin[INF];ll dp[INF];

void assign(ll t){
    for(int i=0; i<t; i++){
        dp[i]=0;
    }
}

ll sum(ll n,ll t){
    if(n==0){
        dp[n]=max(dp[n],aa);
        return dp[n];
    }
    else{
        bool b=false;
        for(int i=0; i<t; i++){
            if(n<pin[i]){
                break;
            }
            b=true;
            dp[n]+=sum(n-pin[i],t);
            
        }
        if(b==false){
            return 0;
        }
    }
}

int main() {
    ll t;
    cin>>t;
    while(t--){
        ll tt,n;
        cin>>tt>>n;
        assign(tt);
        for(int i=0; i<tt; i++){
            cin>>pin[i];
        }
        sum(n,tt);
        cout<<dp[n]<<"\n";
    }
return 0;
}

