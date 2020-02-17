#include<bits/stdc++.h>

using namespace std;

int main(){

int t;
scanf("%d",&t);
int n,d;
while(t--){
    scanf("%d%d",&n,&d);
    int pin[n];
    int ans=0;
    int time=0;
    for(int i=0; i<n; i++){
        scanf("%d",&pin[i]);
        for(int j=0; j<pin[i]; j++){
            if(time+i<=d){
                ans++;
                time+=i;
            }
        }
    }
    printf("%d\n",ans);
}

return 0;
}
