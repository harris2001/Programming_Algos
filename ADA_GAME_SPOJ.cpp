#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main(){
int t,tt;
scanf("%d",&t);
string pin;
for(int i=0; i<t; i++){
    cin>>pin;
    scanf("%d",&tt);
    if(tt==0){printf("Vinit\n");}
    else if(pin=="9999"){printf("Vinit\n");}
    else{printf("Ada\n");}
}



return 0;
}
