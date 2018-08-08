#include <iostream>
#include <queue>
#define INF 10000
#define NIL -1
#define MAX 100
using namespace std;


//First integer is the distance from start_ node to the vertex which is the second integer
priority_queue <pair<int,int>,vector <pair<int,int> >,greater<pair<int,int> > > pq;

int d[MAX],p[MAX]; 
int count;
int start_node;


//First int is the vertex and second is the weight
//For G[i], the first integer is the neighbouring vertex and the second integer is the weight between the two
vector <pair<int,int> > G[MAX];

void Relax(int u, int v,int d);
void djistra(int,int,int);

int nodes,edges;
    
int main()
{
    cin>>nodes>>edges;
    int u,v,w;
    int e = edges;
    cin>>start_node;
    d[start_node - 1] = 0;
    count = nodes;
    while(e-- > 0)
    {
        cin>>u>>v>>w;
        G[u - 1].push_back(make_pair(v - 1,w));
        G[v - 1].push_back(make_pair(u - 1,w));
    }
	//init (p,NIL,5)
	for(int i = 0; i < nodes; i++)
		p[i] = NIL;
	//init (d,INF,5);
	for(int i = 0; i < nodes; i++)
		d[i] = INF;
    
	for(int i = 0; i < nodes; i++)
		if(i != start_node - 1)
			pq.push(make_pair(INF,i));
	
	pq.push(make_pair(0,start_node - 1));
	d[start_node - 1] = 0;
	p[start_node - 1] = 0;
	count = nodes;
	djistra(start_node,nodes,edges);//vector<pair<int,int> > &G);
}

void djistra(int start,int nodes, int edges)//, vector<pair<int,int> > G)
{
	while(!pq.empty())
	{
		pair<int,int> min_p = pq.top();
		pq.pop();//Log(V) step
		vector<pair<int,int> >::iterator iter = G[min_p.second].begin();
		while(iter != G[min_p.second].end() )//Iterating over all the neighbours
		{
			Relax(min_p.second, iter->first, iter->second);
			iter++;
		}
	}
	
	for(int i = 0 ; i < nodes; i++)
		cout<<d[i]<<endl;
	for(int i = 0; i < nodes; i++)
		cout<<p[i]<< "  ";
	cout<<endl;
	for(int i = 0 ; i < nodes; i++)
	{
		if(i != start_node - 1)
		{
			cout<<"The shortest path between "<<start_node <<" and "<<i + 1 <<" with a distance of " << d[i]<<" is : "<<endl;
			for(int j = i; j > 0; j = p[j])
				cout<<i + 1<<" -> ";
			cout<<start_node<<endl;
		}
	}
				
}

void Relax(int u , int v, int w)
{
    if(d[v] > d[u] + w)
    {
        d[v] = d[u] + w;
        pq.push(make_pair(d[v],v));
        p[v] = u;
    }
}

