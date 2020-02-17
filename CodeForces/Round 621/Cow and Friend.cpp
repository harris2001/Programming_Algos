#include<bits/stdc++.h>

using namespace std;

int main(){

int t;
scanf("%d",&t);

int n,x;

while(t--){
    scanf("%d%d",&n,&x);
    int pin[n];
    int maxn=0;
    bool bb=false;
    for(int i=0; i<n; i++){
        scanf("%d",&pin[i]);
        if(pin[i]==x){
            bb=true;
        }
        maxn=max(pin[i],maxn);
    }
    int ans=x/maxn;
    int rem=x%maxn;
    if(bb==true){
        cout<<"1\n";
    }
    else if(rem==0){
        printf("%d\n",ans);
    }
    else if(maxn>x){
        printf("2\n");
    }
    else if(rem<maxn){
        printf("%d\n",ans+1);
    }

}


return 0;
}
