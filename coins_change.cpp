#include<iostream>
#include<algorithm>
#define INF 999999
using namespace std;
typedef long long int ll;

ll dp[INF];

void init(){
    for(ll i=0; i<INF; i++){
        dp[i][j]=0;
    }
}

int main(){

ll price,money,t;
cin>>price>>money>>t;
    
ll pin[t],change=money-price;

for(long long int i=0; i<t; i++){
    cin>>pin[i];
}
 sort(pin,pin+t);
 init();
for(ll i=0; i<t; i++){
    for(ll j=0; dp[j]<=change-pin[i]; j++){
        dp[dp[j]+pin[i]]++;
    }
    cout<<"\n";
}
    cout<<"There are "<<dp[change]<<"ways of giving changes\n";

return 0;
}
