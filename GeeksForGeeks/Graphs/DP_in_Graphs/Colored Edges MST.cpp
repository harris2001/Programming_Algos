#include <bits/stdc++.h>
#define INF 99999999

using namespace std;

struct my{
    int to_node;
    int weight;
    char type;
};

vector<my>list;
vector<vector<my> >graph(list,INF);
vector<bool>visited;



int main() {
    int N,M;
    scanf("%d%d",&N,&M);
        graph.assign(N,vector<my>());
        visited.assign(0,N);
    int a,b,w;
    vector<my> fill;
    for(int i=0; i<M; i++){
        scanf("%d%d%d",&a,&b,&w);
    //////////////////////////////////
        fill.to_node=b;
        fill.weight=w;
        fill.type='B';
        graph[a].push_back(fill);   
    //////////////////////////////////
        fill.to_node=b;
        fill.weight=w;
        fill.type='W';
        graph[a].push_back(fill); 
    //////////////////////////////////
    }
    
	return 0;
}
//Unfinished
