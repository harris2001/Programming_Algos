#include <iostream>
#define N 6

using namespace std;

//We represent the connectivity between nodes/cities as a 2D adjacency list
int adj_matrix[N][N];

//Problem with this representation:
// * array is very spare (full of zeros)

int main(){

// A commonly used example that requires graphs to be solved is
// the routing system between cities

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
