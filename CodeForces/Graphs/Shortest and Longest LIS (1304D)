#include <bits/stdc++.h>

using namespace std;

struct my{
    int value=-1;
    int order;
};

my travel(int i,int tt,my pin[],int method){
    if(method==1){
        if(pin[i].order==1){
            travel(i+1,tt,pin,method);
            pin[i].value=pin[i+1].value+1;
        }
        if(pin[i].order==-1){
            if(i==0||pin[i-1].order==1){
                pin[i].value=1;
            }
            else{
                pin[i].value=pin[i-1].value+1;
            }
            
        }
    }
    if(method==2){
        if(pin[i].order==1){
            travel(i+1,tt,pin,method);
            pin[i].value=pin[i+1]+1;
        }
        if(pin[i].order==-1){
            if(i==0||pin[i-1].order==1){
                pin[i].value=1;
            }
            else{
                pin[i].value=i;
            }
            
        }
    }
    return pin;
}

int main(){

int t;
scanf("%d",&t);

while(t--){
    int tt;
    scanf("%d",&tt);
    char c;
    my tree[tt+1];
    my tree2[tt+1];
    for(int i=0; i<tt; i++){
        scanf("%c",&c);
        if(c=='>'){
            tree[i].order=1;
            tree2[i].order=1;
        }
        else{
            tree[i].order=-1;
            tree2[i].order=-1;
        }
    }
    tree[tt].order=-1;
    for(int i=0; i<tt; i++){
        if(tree[i].value==-1){
            travel(i,tt,tree);
        }
        printf("%d ",tree[i])
    }cout<<endl;
    for(int i=0; i<tt; i++){
        if(tree2[i].value==-1){
            my arr=travel(i,tt,tree2);
        }
        printf("%d ",tree2[i]);
    }cout<<endl;
}

    return 0;
}
