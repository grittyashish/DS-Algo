/*Prim's algorithm
 * Pick a random start node
 * An array marked keeps the record of the nodes which have been included in the MST
 * Important Concept: If marked[i] == 1 && marked[j] == 1 it means that i and j are in the same MST. This check is important to avoid cycles.
 * Graph is stored in adjacency list form as a pair
 * A deque is taken to maintain the record of the edges includes so that their neighbours can be tested for min
 * In prims(int , int) : Parent loop runs for nodes - 1 times
 * In each iteration of this loop we iterate over the entire deque elements one by one.
 * In each iteratin of the deque element, we iterate over the neighbours of the curr_vertex and check if min > iter->first with a pre condition that the concerned 
 * edges has not been already included in the MST.
 * We add on the min_cost and display the result'
 * Inspired by www.hackerearth.com/codemonk
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <cstring>
#define MAX 5
using namespace std;
typedef pair <long, int>  PLI;
bool marked[MAX] ;

//Graph
vector <PLI> adj[5];

void prims(int start_node,int nodes);


int main()
{
	int nodes,edges;
	cin>>nodes>>edges;
	int u,v,w;
	for(int i = 0; i < edges; i++)
	{
		cin>>u>>v>>w;
		adj[u - 1].push_back(make_pair(w,v - 1));
		adj[v - 1].push_back(make_pair(w,u - 1));
	}
	memset(marked,0,MAX);
	prims(0,nodes);
	return 0;
}

void prims(int start,int nodes)
{
	int curr_vertex = start;//Denotes the current vertex whose neighbours are being examined
	int min_cost  = 0,min = 0;//min is used for finding the minimum
	int min_vertex;//once the minimum has been found, the min_vertex stores the corresponding vertex to be marked 
	vector <PLI>::iterator iter = adj[start].begin();
	deque <int> q;//Stores the included nodes so that their neighbours can be traversed and minimum could be found out
	q.push_back(curr_vertex);
	deque <int>::iterator iterq = q.begin();//iterates over the current "partial" MST to find the next minimum edges
	while(nodes-- > 1)//runs for nodes - 1 times
	{
		iterq = q.begin();
		min = MAX;
		min_vertex = iter->second;
		while(iterq != q.end())
		{
			curr_vertex = *iterq;
			iter = adj[curr_vertex].begin();
			while(iter != adj[curr_vertex].end())
			{
				//Second Condition in if tests if the concerned edges has been included in MST or not
				if( (min > iter->first)  &&  !(marked[*iterq] == 1 && marked[iter->second] == 1) )
				{
					min = iter->first;
					min_vertex = iter->second;
				}
				iter++;
			}
			iterq++;
		}
			marked[min_vertex] = 1;
			min_cost += min;
			marked[curr_vertex] = 1;
		
		q.push_back(min_vertex);
	}	
		cout<<min_cost;
}

