#include<iostream>
#include<algorithm>
using namespace std;
int main(){
int n,kokos=0;
cin>>n;
int arr[n];
int lis[n];

for(int i=0; i<n; i++){
    cin>>arr[i];
    lis[i]=0;
}

for(int i=0; i<n; i++){
    int ans=1;
    for(int j=0; j<i; j++){
        if(arr[i]>arr[j]){
            ans=max(ans,1+lis[j]);
            lis[i]=ans;
        if(kokos<lis[i]){
            kokos=ans;
        }
        }
    }
}
for(int i=0; i<n; i++){
    cout<<lis[i]<<" ";

}
cout<<endl;
return 0;
}
