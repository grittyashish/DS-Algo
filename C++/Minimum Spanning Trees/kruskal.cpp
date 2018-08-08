/*Graph is stored in the form of 0,1,2... and values are entered in the form of 1,2,3....
 * Input is taken and the edges are stored in an array of pairs with their respective edge weights
 * initialize() is called and the union disjoint set data structure is initialized
 * sort() is called and the arrays are sorted based on their weights
 * Kruskal(int,int) is called where: a loop is run on the array of pairs
 * In each iteration, root(u) == root(v) is checked and if it is true that means connecting u and v will form a cycle
 * Thus it is neglected. The qualified nodes are registered into the mst array of pairs and union operation is now performed on them.
 */


#include <iostream>
#include <utility>
#include <algorithm>

#define MAX 10

using namespace std;
int kruskal(int,int);
int root(int);
void union_operation(int,int);
int find(int,int);
void initialize(int);

bool compare(const pair<long long, pair<int, int> >&i, const pair<long long, pair<int, int> >&j)
	{
		return i.first < j.first;
	}

//First one contains the weight the second is u and third is v
//Storing in this form makes it easy to sort the edges according to their weight
pair <long long, pair<int, int> > p[(int)MAX],mst[(int)MAX];
int Arr[(int)MAX];
int size[(int)MAX];

int main()
{
	int nodes,edges,u,v,weight;
	cin>>nodes>>edges;
	initialize(nodes);
	for(int i = 0; i < edges ; i++)
	{
		//Input taken in the form: 1,2,3....
		cin>>u>>v>>weight;
		p[i].first = weight;
		
		//Values are stored the form of 0,1,2...
		p[i].second.first = u - 1;
		p[i].second.second = v - 1;
		cout<<p[i].second.first<<" --"<<p[i].second.second<<" : "<<p[i].first<<endl;
	}
	cout<<endl;
	
	sort(p,p + edges,compare);
	int min_cost = kruskal(nodes,edges);
	cout<<min_cost;
}


int root(int i)
{
	while(Arr[i] != i)
		i = Arr[Arr[Arr[Arr[i]]]];
	return i;
}

int find(int u,int v)
{
	if(root(u) == root(v))
		return 1;
	return 0;
}

void union_operation(int u, int v)
{
	int rootu = root(u);
	int rootv = root(v);
	if(size[rootu] > size[rootv])
	{
		Arr[rootv] = rootu;
		size[rootu] += size[rootv];
	}
	
	else
	{
		Arr[rootu] = rootv;
		size[rootv] += size[rootu];
	}
}
void initialize(int nodes)
{
	for(int i = 0; i < nodes; i++)
	{
		Arr[i] = i;
		size[i] = 1;
	}
}

int kruskal(int nodes,int edges)
{
	//mst_edges are less than actual nodes in the graph so count of mst edges is required to display the mst tree
	int cost = 0,mst_edges = 0;
	int j = 0;//counter to count the no. of edges included, If j = nodes - 1(as in a tree, no. of edges = nodes - 1), stop the loop
	//looping over all the edges
	for(int i = 0 ; i < edges; i++)
	{	
		if(root(p[i].second.first) != root(p[i].second.second))
		{
			union_operation(p[i].second.first ,p[i].second.second );
			cost += p[i].first;
			mst[j].first = p[i].first;
			mst[j].second.first = p[i].second.first;
			mst[j].second.second = p[i].second.second;
			j++;
			mst_edges++;
		}
		if (j == nodes - 1)
			break;
	}
	
	cout<<"The graph is : "<<endl;
	for(int i = 0; i < edges; i++)
	{
			cout<<p[i].second.first + 1<<" --"<<p[i].second.second + 1<<" : "<<p[i].first<<endl;
	}
	
	cout<<"The Minimum Spannig Tree is : "<<endl;
	for(int i = 0; i < mst_edges; i++)
	{
		cout<<mst[i].second.first + 1<<" --"<<mst[i].second.second + 1<<" : "<<mst[i].first<<endl;
	}
		
	return cost;
}
