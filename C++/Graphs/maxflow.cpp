/*
 * Ford Fulkerson Method
 * Using Edmond Karp Algorithm
 * For finding the Max Flow
 * In a Network
 * Edmond Karp Algorithm Provides minimum time complexity for Ford Fulkerson(O(E*MaxFlow) = O(E*VE))
 * But here I have used matrix representation for graph so O(V*E^3)
 * By Ashish Kumar Choubey
 * Inspired by geeksforgeeks.org & Tushar Roy
 */

#include <iostream>
#include <queue>
#include <cstring>
#define MAX 100
#define INF 999999999
using namespace std;
int Graph[MAX][MAX],rGraph[MAX][MAX];

void initialize(int);
bool bfs(int,int,int, int []);
int FordFulkerson(int [], int);

int main(){
	int vertices,edges, parent[MAX];
	cin>>vertices>>edges;
	int v, u,w;
	while(edges-- > 0){
		cin>>u>>v>>w;
		Graph[u][v] = w;
		rGraph[u][v] = 0;
	}
	
	for(int i = 0; i < vertices; i++)
		for(int j = 0; j < vertices; j++)
			rGraph[i][j] = Graph[i][j];
	
	cout<<"The maximum flow through the network is "<<FordFulkerson(parent,vertices);
	return 0;
}

int FordFulkerson(int parent[], int vertices){
	int bottleneck = 0, maxflow = 0;
	//If augmenting path exists
	while(bfs(vertices,0,vertices - 1,parent)){//While there is path from source to sink
		int i = vertices - 1, min_flow = INF;
		while(i != 0){//Finding the bottleneck
			min_flow= min(rGraph[parent[i]][i],min_flow);
			i = parent[i];
		}
		bottleneck = min_flow;
		maxflow += bottleneck;
		 i = vertices  - 1;
		 while(parent[i] != INF){
			rGraph[parent[i]][i] -= bottleneck;
			rGraph[i][parent[i]] += bottleneck;
			i = parent[i];
		}
	}
	return maxflow;
}

void initialize(int v){
	for(int i = 0; i < v; i++)
		for(int j = 0; j < v; j++){
			if(i == j)
				Graph[i][j] = 0;
			else
				Graph[i][j] = INF;
		}
}

bool bfs(int v, int start , int terminal,int parent[]){
	bool visited[MAX],found_path = false;
	memset(visited,false,v);
	for(int i = 0; i < v; i++)
		parent[i] = INF;
	queue <int> q;
	
	//Standard BFS
	q.push(start);
	while(!q.empty() && found_path == false){
		found_path = false;
		int curr = q.front();
		q.pop();
		visited[curr] = true;
		for(int j = 0; j < v; j++){
			if(visited[j] == false && rGraph[curr][j] > 0 && rGraph[curr][j] != INF){//Neighbouring node not visited and Network Flow Graph has capacity > 0
				q.push(j);
				parent[j] = curr;//j was introduced by curr node
				visited[j] = true;
				if(j == terminal){
					found_path = true;
					break;
				}
			}
		}
	}
	if(found_path)
		return true;
	return false;
}


