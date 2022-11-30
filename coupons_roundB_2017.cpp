#include<iostream>
#include<vector>
using namespace std;

    vector<vector<int> > dp;
int main(){

int t;
cin>>t;
    dp.assign(t,vector<int>());
int pin[t],n;
for(int i=0; i<t; i++){
    cin>>n;
    if(n%10!=0){
        n=n-(n%10)+10;
    }
    pin[i]=n/10;
}
    int v;
    cin>>v;

    for(int i=0; i<t; i++){
        for(int j=i+1; j<t; j++){
    cout<<i<<" "<<j<<"\n";
            if(i==0){dp[i].push_back(pin[j]);
                     dp[i].push_back(pin[j]);
                    }
            else if(dp[i].back()+pin[j]<=v){
                int n;
                dp[i].back()=n;
                dp[i].pop_back();
                dp[i].push_back(pin[j]);
                dp[i].push_back(n+pin[j]);
            }
            else{
                dp[i]=dp[i-1];
            }
        }
    }
    int maxx=0;
    int note;
    for(int i=0; i<t; i++){
        if(dp[i].back()>maxx){
            maxx=dp[i].back();
            note=i;
        }
        cout<<maxx<<endl;
    }
    for(int i=0; i<dp[note].size(); i++){
        cout<<dp[note][i]<<"\n";
    }
return 0;
}
