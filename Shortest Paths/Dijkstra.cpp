#include<bits/stdc++.h>
#define MAXN 1000

using namespace std;

vector<int> topological;
bool visited[MAXN];
vector<vector<int>>graph;

//Use this array to keep the minimum distance required to traverse
//to node [i] from the starting node 
int dist[MAXN];

//Calculates the minimum distance between a node s and every other node in the graph
void dijkstra(int s){
    dist[s] = 0;
    //Create a priority queue to sort nodes based on their distance from the starting node
    priority_queue<int,int>pq;
    //First distance to add is distance 0 of reaching starting point from itself :)
    pq.push_back(make_pair(0,s));
    //While there are unexplored edges:
    while(!pq.empty()){
        //Get cost and point you want to visit
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        //If we already know a faster path, disreguard this entry
        if(dist[node]<cost)
            continue;
        //Otherwise, check to see if by using this edge we can find a shortest way
        //to reach any of its children (formaly known as edge relaxation)
        for(int i=0; i<graph[node].size(); i++){
            pair<int,int> v = graph[node][i];
            if(dist[v.first]>dist[node]+v.second){
                dist[v.first] = dist[node]+v.second;
                pq.push_back(dist[v.first],v.first);
            }
        }
    }
}