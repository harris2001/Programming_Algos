#include <iostream>
using namespace std;

int main(){
int t;
cin>>t;
int pin[10000];
pin[0]=1;
pin[1]=2;
for(int i=2; i<1000; i++){
    pin[i]=(pin[i-1]+pin[i-2])% 1000000007;
}
cout<<pin[t-1]<<endl;
return 0;
}
