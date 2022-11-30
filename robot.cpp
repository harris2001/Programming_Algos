#include <iostream>
#include <string>
using namespace std;
struct st{
    long long int ways=0;
    long long int glyko=0;
};
st pin[1000][1000];

int main(){
long long int n,m;
cin>>n>>m;
string s;
long long int elem[n][m];
for(long long int i=0; i<n; i++){
    cin>>s;
    for(long long int j=0; j<m; j++){
        elem[i][j]=s[j];
    }
}
long long int countt=0,cw=0;
pin[0][0].ways=1;
if(elem[0][0]=='%'){
    pin[0][0].glyko=1;
}
else{pin[0][0].glyko=0;}
for(long long int i=0; i<n; i++){
    for(long long int j=0; j<m; j++){
        if(elem[i][j]=='x'){
            pin[i][j].ways=0;
            pin[i][j].glyko=0;
        }
        else{
            if(elem[i][j]=='%'){
                pin[i][j].glyko++;
            }
            if(i==0||j==0){
                pin[i][j].ways=1;
            }
            else{
                pin[i][j].ways=(pin[i-1][j].ways+pin[i][j-1].ways)% 1000000007;}
                pin[i][j].glyko=max(pin[i-1][j].glyko,pin[i][j-1].glyko);
        }
        cout<<pin[i][j].ways<<" ";
    }cout<<endl;
}
/*for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
        cout<<pin[i][j].glyko<<" ";
    }cout<<endl;
}*/
cout<<pin[n-1][m-1].glyko<<" "<<pin[n-1][m-1].ways<<"\n";

return 0;
}
