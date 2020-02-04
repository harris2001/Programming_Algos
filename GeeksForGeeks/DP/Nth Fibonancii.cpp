#include <iostream>
using namespace std;

long long int table[10000];

long long int fib(int N){
    //cout<<N<<endl;
    if(N<=2){
        table[N]=1;
        return 1;
    }
    long long int ans=0;
    if(table[N-1]==0){
        fib(N-1)%1000000007;
    }
    if(table[N-2]==0){
        fib(N-2)%1000000007;
    }
    table[N] = (table[N-1]+table[N-2])%1000000007;

    return table[N];
}

int main() {
	int T,N;
	scanf("%d",&T);
	fib(1000);
	while(T--){
	    scanf("%d",&N);
	    printf("%lld\n",table[N]);
	}
	return 0;
}
