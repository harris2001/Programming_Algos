#include<iostream>
#include<vector>
#include<algorithm>
#include<list>

using namespace std;

vector<int> row;
vector< vector<int> > lista(1000, row);
vector<int> path;
list<int>l;
bool v[1000];

void dfs(int start,int stop,int k){
    path.push_back(start);
    if(start==stop){
        if(path.size()==k-2){
        while(path.size()>0){
            l.push_back(path.back());
        path.pop_back();
        }
        while(l.size()>0){
            cout<<l.back()<<endl;
        l.pop_back();
        }
        }
        //else{
        //    cout<<"-1"<<endl;
        //}
    }
    v[start]=true;
    for(int i=0; i<lista[start].size(); i++){
        if(v[lista[start][i]]==false){
            dfs(lista[start][i],stop,k);
        }
    }
    path.pop_back();
}

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int n,m;
    for(int i=0; i<c; i++){
        cin>>n>>m;
    lista[n].push_back(m);
    lista[m].push_back(n);
    }
    dfs(a,b,c);
return 0;
}
