#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int ll;
set<ll>pin;
set<ll>::iterator it,pp,popo;

int main() {
    ll v,w,n;
    scanf("%lld%lld",&v,&w);
    pin.insert(0);
    for(ll i=0; i<v; i++){
        scanf("%lld",&n);
        ll po=pin.size()+1;
        it=pin.begin();
        ll nn=n;
        while(po--){
            if(nn>w){
                break;
            }
            pin.insert(nn);
            nn=n+*it;
            //cout<<nn<<" ";
            it++;

        }//cout<<"\n";
    }
    ll minn=0;
    popo=pin.end();
    it=pin.begin();
    popo--;
/**
    for(it; it!=popo; it++){
        cout<<*it<<" ";
    }cout<<"\n";**/
    ///it=pin.lower_bound();
    ///cout<<*it<<"\n";
    //ll pop=pin.size();

    cout<<w-*popo<<"\n";
    return 0;
}
