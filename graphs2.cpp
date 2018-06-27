#include <iostream>
#define N 6
using namespace std;
int adj_matrix[N][N];
int main(){
int city1,city2,cities;
cin>>cities;
while(city2--){
 cin>>city1>>city2;
 adj_matrix[city1-1][city2-1]=1;
 }
 for(int i=0;i<N;i++){
 for(int j=0;j<N;j++)
 cout<<adj_matrix[i][j]<<" ";
 cout<<endl;
 }
return 0;
}
