#include <bits/stdc++.h>
#include <iostream>

using namespace std;
    long long int dp[275];

long getWays(long n, vector < long > c){
    // Complete this function
    int ans=0;
    for(long long int ii=0; ii<c.size(); ii++){
        long long int i=ii+1;
            for(long long int v=c[ii]; v<=n; v++){
                if(v==c[ii]){
                    dp[v]=max((dp[v]+dp[v-c[ii]]),1+dp[v]);
                }
                else{
                    dp[v]=dp[v]+dp[v-c[ii]];
                }
            }
        /*for(long long int v=0; v<=n; v++){
            cout<<dp[v]<<" ";
        }cout<<endl;*/
    }

    return dp[n];
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<long> c(m);
    for(int c_i = 0; c_i < m; c_i++){
       cin >> c[c_i];
    }
    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
    long ways = getWays(n, c);
    if(m==0){cout<<"1"<<endl;}
    else{cout<<ways<<endl;}
    return 0;
}
