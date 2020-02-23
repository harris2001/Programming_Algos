#include <bits/stdc++.h>

using namespace std;

int main(){
   int t;
   scanf("%d",&t);
   int a,b,p;
   string s;
   while(t--){
       int aa;
       scanf("%d%d%d",&a,&b,&p);
       cin>>s;
       vector<pair<int,int> >pin;
       int ans=0;
       if(s[0]=='A'){
           aa=a;
       }
       else{
           aa=b;
       }
       pin.push_back(make_pair(1,aa));
       for(int i=1; i<s.size()-1; i++){
           if(s[i]!=s[i-1]){
                if(s[i]=='A'){
                    aa=a;
                }
                else{
                    aa=b;
                }
                pin.push_back(make_pair(i+1,aa));
           }
       }
       ans=0;
       int i=s.size();
       while(!pin.empty()&&ans+pin.back().second<=p){
               ans+=pin.back().second;
               i=pin.back().first;
           pin.pop_back();
       }
       printf("%d\n",i);
   }
   

    return 0;
}
