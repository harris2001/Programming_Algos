#include <iostream>
#include <stdio.h>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef vector<pair<pair<double,long long int>,long long int > >viii;
int main() {
long long int t,v;
scanf("%lld %lld",&v,&t);
viii vv;
pair<long long int,long long int>pin[t+1];
	double m;
for(int i=1; i<=t; i++){
	scanf("%lld %lld",&pin[i].second,&pin[i].first);
	m=pin[i].second;
	m/=pin[i].first;
	vv.push_back(make_pair(make_pair(m,pin[i].first),pin[i].second));
}
sort(vv.begin(),vv.end());
//cout<<vv[t-1].first.first<<" "<<vv[t-1].first.second<<" "<<vv[t-1].second<<endl;
/*
long long int dp[t+1][v+1];
for(int i=0; i<=t; i++){
	for(int f=0; f<=v; f++){
		if(i==0||f==0){
			dp[i][f]=0;
		}
		else if(pin[i].first<=f){
			long long int ff=pin[i].first;
			dp[i][f]=max(pin[i].second+dp[i-1][f-ff],dp[i-1][f]);
		}
		else{
			dp[i][f]=dp[i-1][f];
		}
	}
}
printf("%lld\n",dp[t][v]);
*/
long long int ans=0;
for(int i=t+1; i>=0; i--){
    if(vv[i].first.second<=v){
        ans+=vv[i].second;
        v-=vv[i].first.second;
            //cout<<ans<<" "<<v<<" "<<vv[i].first.second<<endl;
    }
}
printf("%lld\n",ans);
	return 0;
}
