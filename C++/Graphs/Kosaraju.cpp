/*
 * Kosaraju Algorithm for finding the strongly connected components
 * By Ashish Kumar Choubey
 * Inspired by Tushar Roy and www.hackerearth.com/codemonk
 * Algo:
 * DFS on the graph while pushing the nodes into the stack so as to order them according to their finish times
 * Reverse every edge of the graph
 * DFS on the graph by popping from the stack one by one and running DFS on the popped element
 */
#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#define MAX 7

using namespace std;
void dfs(int,char*,int );

vector <int>Graph[MAX];
vector <int> ReverseGraph[MAX];
stack <int> s;
int main(){
	int vertices,edges,u,v,i;
	cin>>vertices>>edges;
	for( i = 0; i < edges; i++){
		cin>>u>>v;
		Graph[u - 1].push_back(v-1);
	}
	char visited[MAX];
	memset(visited,'n',vertices);

	while(true){
	for(i = 0; i < vertices; i++)
		if(i != vertices && visited[i] == 'n')
			break;
	if(i == vertices)
		break;
		dfs(i,visited,1);//First pass
	}
	memset(visited,'n',vertices);

	//Second Pass:
	while(!s.empty()){
		int i = s.top();
		s.pop();
		if(visited[i] == 'n')
			dfs(i,visited,2);
		cout<<endl;
	}
	return 0;
}

//Start exploring the graph from the given node and return when we exhaust all nodes which are recheable from the given node
//If pass == 1 => first pass
//If pass == 2 => second pass
void dfs(int i, char* visited, int pass){

	//First pass 
	if(pass == 1){
		visited[i] = 'y';
		vector <int>::iterator iter = Graph[i].begin();
	//	if(iter != Graph[i].end())
	//		ReverseGraph[*iter].push_back(i);//Reversing the graph	
		while(iter !=Graph[i].end()){
			ReverseGraph[*iter].push_back(i);
			if (visited[*iter] == 'n')
				dfs(*iter,visited,1);
		iter++;
		}	
		
		s.push(i);
	}
		
	//Second pass
	else{
		vector<int>::iterator iter = ReverseGraph[i].begin();
		visited[i] = 'y';
		cout<<i<<" ";
		
		while(iter != ReverseGraph[i].end()){
			if(visited[*iter] != 'y'){
				dfs(*iter,visited,2);
			}
			iter++;
			}
		}
}
		
		
	
	
		
			
