#include<bits/stdc++.h>
                             
using namespace std;                                       
                                                           
int* Reverse(int L[],int start,int end){
        cout<<"Reversing "<<start<<" with "<<end<<endl;
        stack<int>tmp;                                     
        for(int i=start; i<end; i++){
                tmp.push(L[i]);        
        }                
        int i=start;
        while(!tmp.empty()){                               
                L[i]=tmp.top();
                tmp.pop();
                i++;         
        }                                                  
        return L;
}

void Reversort(int sorted[],int N,int C){

        int NN=N;
        stack<int>costs;

        C-=N-1;
        N--;

        while(C>0){
                N=min(N,C);
                C-=N;
                costs.push(N);
                N--;
        }

        while(!costs.empty()){
                int sz = costs.top();
                costs.pop();
                //cout<<">>>>>"<<sz<<endl;
                sorted = Reverse(sorted,NN-sz-1,NN);
        }

        for(int i=0; i<NN; i++){
        cout<<sorted[i];
                if(i!=NN-1)
                        cout<<" ";
        }
        cout<<"\n";
}


int main(){
    int T;//Testcases
    scanf("%d",&T);
    for(int t=1; t<=T; t++){
        int tt;//array size
        int c; //desired cost
        scanf("%d%d",&tt,&c);
        int total=0;
        int sorted[tt];
        for(int i=0; i<tt; i++){
                sorted[i]=i+1;
                total+=i+1;
        }
        printf("Case #%d: ",t);
        if(c>=total or c<tt-1){
                printf("IMPOSSIBLE\n");
                continue;
        }
        Reversort(sorted,tt,c);
    }
    return 0;
}       ⏎ 
