#include <iostream>

using namespace std;
int main() {
    int t;
    cin>>t;
    int pin[t+1];
    pin[t]=0;
    for(int i=0; i<t; i++){
        cin>>pin[i];
    }
    int candies=0,n=0;
    bool b=false;
    for(int i=0; i<t; i++){
        n=0;
        while(pin[i]<pin[i+1]){
            n++;
            candies+=n;
            cout<<n<<" ";
            i++;
            if(i==t){b=true;break;}
        }
        if(b==false){
            n++;
            candies+=n;
            cout<<n<<" ";
        }
        b=false;
        n=0;
        while(pin[i]>=pin[i+1]){
            n++;
            candies+=n;
            cout<<n<<" ";
            i++;
            if(i==t){b=true;break;}
        }
        if(b==false){
            n++;
            candies+=n;
            cout<<n<<" ";
        }
    }
    cout<<candies<<endl;
    return 0;
}
