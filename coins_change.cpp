#include<iostream>
using namespace std;
long long int dp[300][300];
int main(){
long long int poso,t;
cin>>poso>>t;
long long int pin[t];
for(long long int i=0; i<t; i++){
    cin>>pin[i];
}
for(long long int i=0; i<t; i++){
    for(long long int j=0; j<=poso; j++){
        if(j>=pin[i]){dp[j]++;}
        cout<<dp[j]<<" ";
    }
    cout<<"\n";
}
    cout<<dp[poso]<<"\n";

return 0;
}
