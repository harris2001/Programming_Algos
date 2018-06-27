#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
struct point{
    int x;
    int y;
};
int dp[200][200];

int main(){

for(int i=0; i<200; i++){
    for(int j=0; j<200; j++){
        dp[i][j]=9999999;
    }
}

int v,e;
scanf("%d%d",&v,&e);
int pin[v][e];
for(int i=1; i<=v; i++){
    for(int j=1; j<=e; j++){
        scanf("%d",&pin[i][j]);
    }
}
int q;
scanf("%d",&q);
point p1,p2;
vector<pair<int,point> >v;
string s;
    while(q--){
        scanf("%d%d%d%d",&p1.x,&p1.y,&p2.x,&p2.y);
        int i=p1.x+1;
        int j=p1.y+1;
        dp[i][j+1]=pin[i][j+1];
        v.push_back(make_pair(dp[i][j+1],i,j));
        dp[i+1][j]=pin[i+1][j];
        //v.push_back(make_pair(dp[i][j+1]),s);
        dp[i+1][j+1]=min(dp[i+1][j],dp[i][j+1])+pin[i+1][j+1];
        //v.push_back(make_pair(dp[i][j+1]),s);
    }

return 0;
}
