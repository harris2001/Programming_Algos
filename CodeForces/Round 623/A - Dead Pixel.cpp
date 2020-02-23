#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
   int t;
   scanf("%d",&t);
   int n,m,x,y;
   while(t--){
       scanf("%d%d%d%d",&n,&m,&x,&y);
       int ans=max((max(n-x-1,x)*m),(n*max(m-y-1,y)));
       printf("%d\n",ans);
       
   }
   
 
    return 0;
}
