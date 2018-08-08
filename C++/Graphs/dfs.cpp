/*
 * DFS on undirected graph
 * By Ashish Kumar Choubey
 * Inspired by Code Monk
 */
 
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string.h>
using namespace std;
void dfs(vector <int>,int);
int main()
{
	int start_node,nodes,edges,n1,n2,i = 0;
	cin>>nodes>>edges;
	//Graph Adjacency List Representation
	vector <int> v[nodes];
	
	//Creating Graph DS
	while(i < edges){
	cin>>n1>>n2;
	v[n1].push_back(n2);
	v[n2].push_back(n1);
	}
	int node;
	
	cin>>start_node;
	
	//This is my finger(index)
	vector <int>::iterator iter;
	stack <int> s;
	
	//Visited node
	char visited[nodes];
	i = 0;
	int* p = NULL;
	
	//Inititalising to some value which does not represent a node to avoid accidental finding
	memset(visited,'N',nodes);
		s.push(start_node);
	
	//Heart and Soul of the program
	while(!s.empty())
	{
		
		//Checking is node already visited
		p = find(visited,visited + 6,s.top());
		if(p != visited + 6)
		{
			//Popping to avoid going into infinite loop
			s.pop();
			continue;
		}
		visited[i] = s.top();
		s.pop();
	
		iter = v[visited[i]].begin();
		
		//Iterate on this node to find all adjacent nodes 
		while(iter != v[visited[i]].end())
		{
			//Pushing the adjacent nodes on the stack
			s.push(*iter);
			iter++;
		}
		
		//printing the visited node
		cout<<visited[i];
		i++;	
	}
	return 0;
}
