#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

set<long long int> dp;
set<long long int>::iterator it;
long long int pin[10003];

void solve(int N){
    dp.insert(1);
    int i=0;
    for(it=dp.begin(); it!=dp.end() && i<10002; it++){
        dp.insert(*it*2);
        dp.insert(*it*3);
        dp.insert(*it*5);
        i++;
    }
    i=1;
    for(it=dp.begin(); it!=dp.end() && i<=10001; it++){
        pin[i]=*it;
        i++;
    }    
}

int main() {
	int T,N;
	scanf("%d",&T);
	    solve(N);
	while(T--){
	    scanf("%d",&N);
	    printf("%lld\n",pin[N]);
	}
	return 0;
}
