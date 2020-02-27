#include <bits/stdc++.h>
#define INF 99999999

using namespace std;

struct my{
    int to_node;
    int weight;
    int type;
};

vector<my>list;
vector<vector<my> >graph(list,INF);
vector<bool>visited;



int main() {
    int N,M;
    scanf("%d%d",&N,&M);
    int a,b,w;
    for(int i=0; i<M; i++){
        scanf("%d%d%d",&a,&b,&w);
        graph.assign(N,vector<pair<int,int> >());
        visited.assign(0,N);
    }
    
	return 0;
}
