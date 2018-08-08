/*Floyd Warshall Implementation for calculation of All Pair Shortest Paths
 * By Ashish Kumar Choubey
 */
 
#include <iostream>
 #define INF 99999
#define MAX 100

 using namespace std;
 
int Graph[MAX][MAX],Dist[MAX][MAX];
 int main()
 {
	 int N,E,A,B,W;
	cin>>N>>E;
	
	//Initializing graph matrix to infinity or 0
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++){
			if(i == j)
				Graph[i][j] = 0;
			else
			Graph[i][j] = INF;
		}

	//Taking input
	for(int k = 0; k < E; k++){
		cin>>A>>B>>W;
		if(Graph[A-1][B-1] > W){//Takes care of multiple edges between a single pair of nodes
			Graph[A-1][B-1] = W;
			Graph[B-1][A-1] = W;//Edges are is bidirectional/undirected
		}
	}
	
	//Initializing Distance matrix
	 for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			Dist[i][j] = Graph[i][j];
	
	//Algorithm launched
	 for(int k = 0; k < N; k++)
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				if(Dist[i][j] > Dist[i][k] + Dist[k][j])
					Dist[i][j] = Dist[i][k] + Dist[k][j];
	
	for(int i = 0; i < N; i++)
	{
		cout<<"The shortest distances from vertex "<< i+1 <<" to the below vertices are : "<<endl;
		for(int j = 0; j < N; j++)
		{
			cout<<"Distance to vertex "<<j+1<<" is  :  ";
			cout<<Graph[i][j]<<endl;
		}
	}
	return 0;
}
