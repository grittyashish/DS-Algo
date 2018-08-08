/*Topological Sort on a graph of 6 edges and 6 vertices
 * Topological Sort is only for DAGs(Directed "Acyclic Graph) so we don't need to worry about cycles
 * Algorithm: Run DFS such that whole of graph is traversed(Start node can be any one)
 * In this DFS(modified), initially dfs is called on a random node. We recursively run dfs for its neighbours
 * We continue to do so untill we encounter a node which has no outgoing edges(no neighbours), we push it onto the "order" stack and "mark it visited". Then we 
 * return to previous call
 * We check at the start of each dfs whether node u is visited and exit accordingly
 * Inspired by Tushar Roy www.youtube.com and Shubham Prabhu
 */  


#include <iostream>
#include <vector>
#include <stack>
#define MAX 10

using namespace std; 

//Graph Adjacency List Representation
vector <int> v[MAX];

//Order Stack
stack <int> s;
void dfs(int u);
char visited[MAX];
int main()
{
	int u,v,nodes;edges;
	cin>>nodes>>edges;
	while(edges-- > 0){
		cin>>u>>v;
		v[u - 1].push_back(v - 1];
	}
	memset(visited,'n',sizeof(char)*nodes);
	while(true)
	{
		for(int i = 0; i < nodes; i++)
			if(visited[i] == 'n')
				break;
				
		//Calling dfs on the unvisited node
		if(i != nodes)
			dfs(i);
		else 
			break;
	}
	
	//Displaying the topologically sorted order
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
	return 0;
}

void dfs(int u)
{
	//Checks if an already visited node has been called
	if(visited[u] == 'y')
		return;
	
	vector <int>::iterator iter = v[u].begin();
	//Explore untill all the neighbours have been exhausted
	while(iter != v[u].end())
	{
		//Below, I was just cross-checking
		//if(visited[*iter] == 0)
		//{
			dfs(*iter);
		//}
		iter++;
	}
	
	//Push onto stack
	s.push(u);
	
	//Mark visited
	visited[u] = 1;
}
	
