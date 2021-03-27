#include<bits/stdc++.h>
using namespace std;

int main(){

        int T,N,Q;
        scanf("%d%d%d",&T,&N,&Q);
        for(int t=1; t<=T; t++){
            int arr[N];
            arr[0]=1;
            arr[1]=2;
            int median;
            for(int i=1; i<N-1; i++){
                arr[i+1]=i+2;
                printf("%d %d %d\n",arr[i-1],arr[i],arr[i+1]);
            
                scanf("%d",&median);
            
            
                if(median==arr[i-1]){
                        arr[i-1]=arr[i];
                        arr[i]=median;
                }
                else if(median==arr[i+1]){
                        arr[i+1]=arr[i];
                        arr[i]=median;
                }
            }
            for(int i=0; i<N; i++){
                printf("%d ",arr[i]);
            }
            printf("\n");
            int a;
            cin>>a;
        }
        return 0;
}
