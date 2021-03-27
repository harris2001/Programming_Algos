#include<bits/stdc++.h>

using namespace std;

int ans=0;

int* Reverse(int L[],int start,int end){
        stack<int>tmp;
        for(int i=start; i<end; i++){
                tmp.push(L[i]);
        }
        ans+=tmp.size();
        int i=start;
        while(!tmp.empty()){
                L[i]=tmp.top();
                tmp.pop();
                i++;
        }
        return L;
}

int Reversort(int L[],int sorted[],int N){
        ans = 0;
        for(int i=0; i<N; i++){
                int jj=i;
                for(int j=i; j<N; j++){
                        if(L[j]==sorted[i]){
                                jj=j;
                                break;
                        }
                }
                L = Reverse(L,i,jj+1);
        }
        return ans-1;
}

int main(){
    int T;//Testcases
    scanf("%d",&T);
    for(int t=1; t<=T; t++){
        int tt;//array size
        scanf("%d",&tt);
        int arr[tt];
        int sorted[tt];
        for(int i=0; i<tt; i++){
                scanf("%d",&arr[i]);
                sorted[i]=arr[i];
        }
        sort(sorted,sorted+tt);
        printf("Case #%d: %d\n",t,Reversort(arr,sorted,tt));
    }
    return 0;
} 
