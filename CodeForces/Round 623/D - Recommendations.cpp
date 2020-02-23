#include <bits/stdc++.h>

using namespace std;

int dp[200004][2];

long long int solve(pair<int,int> pin[],int pos,int T){
    int j=pos+1;
    while(j<T&&pin[pos]==pin[j]){
        j++;
    }
    j--;
    while(j>i){
        long long int ans=min(solve())
    }
}

bool check(pair<int,int>A,pair<int,int>B){
    if(A.first<B.first || A.first==B.first &&A.second>B.second){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int t;
    scanf("%d",&t);
    pair<int,int> a[t];
    for(int i=0; i<t; i++){
        scanf("%d",&a[i].first);
    }
    for(int i=0; i<t; i++){
        scanf("%d",&a[i].second);
    }
    sort(a,a+t,check);
    
    solve(a,0,t);
    
    return 0;
}
