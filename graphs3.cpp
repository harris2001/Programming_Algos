#include<iostream>
#include<vector>
using namespace std;

typedef vector <int> vi;
vector<vi> A;

int main(){
int e,v,a,b;
cin>>e>>v;

A.assign(e,vi());
while(v--){
    cin>>a>>b;
    A[a-1].push_back(b-1);
}
for(int i=0; i<e; i++){
    cout<<i+1<<":";
    for(int j=0; j<A[i].size(); j++)
        cout<<A[i][j]+1<<"";
    cout<<endl;
}
return 0;
}
