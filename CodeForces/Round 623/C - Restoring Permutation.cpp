#include <bits/stdc++.h>

using namespace std;

int findd(int num,int pin[],int T){
    for(int i=num; i<T*2+1; i++){
        if(pin[i]==0){
            return i;
        }
    }
    return -1;
} 

int main(){
   int t;
   scanf("%d",&t);
   int tt;
    while(t--){
        scanf("%d",&tt);
        
        int pin[tt*2+1];
        int used[tt*2+1]={};
        
        for(int i=0; i<tt*2; i+=2){
            scanf("%d",&pin[i]);
            used[pin[i]]=1;
        }
        
        bool b=true;
        
        for(int i=0; i<tt*2; i+=2){
            pin[i+1]=findd(pin[i],used,tt);
            if(pin[i+1]==-1){
                b=false;
            }
            else{
                used[pin[i+1]]=1;
            }
        }
        if(b==false){
            printf("-1\n");
        }
        else{
            for(int i=0; i<tt*2; i++){
                printf("%d ",pin[i]);
            }
            printf("\n");
        }
    }

    return 0;
}
