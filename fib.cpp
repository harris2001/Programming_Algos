#include<iostream>
using namespace std;
int f[1000000];
long long int fib(long long int n){
    f[0]=0;
    f[1]=1;
    for(int i=2; i<=n; i++){
        f[i]=f[i-1]+f[i-2];
    }
    return f[n];
}

int main(){
cout<<fib(500)<<endl;

}
