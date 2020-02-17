#include<bits/stdc++.h>

using namespace std;

int main(){

string s;

cin>>s;

vector<string>dp;
string ss;
for(int i=0; i<s.size(); i++){
    int k=1;
    //cout<<i<<":"<<endl;
    ss="";
    ss+=s[i];
            dp.push_back(ss);
    while(i+k<s.size()){
    ss="";
    ss+=s[i];
        for(int j=i+k; j<s.size(); j+=k){
            ss+=s[j];
            dp.push_back(ss);
            //cout<<dp.back()<<"\n";
        }
    k++;

    }
}
sort(dp.begin(),dp.end());

bool b=false;
int ans=0;
int maxn=1;
for(int i=0; i<dp.size(); i++){
    //cout<<dp[i]<<endl;
    if(i!=0){
        if(dp[i]==dp[i-1]){
            if(b==false){
                b=true;
                ans+=2;
            }
            else{
                ans++;
            }
            maxn=max(maxn,ans);
        }
        else{b=false;ans=0;}
    }
}

printf("%d\n",maxn);

return 0;
}
