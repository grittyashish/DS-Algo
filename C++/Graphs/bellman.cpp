/*Bellman-Ford Algorithm
*By Ashish Kumar Choubey
*Inspired by www.hackerearth.com and geeksforgeeks.org also MIT:Intro to Algorithm lectures
*Algorithm: Storing the graph as a pair of vertices will be best(as we have to traverse the graph edge by edge)
*Loop for n - 1 times traversing the whole of graph edge by edge and Relaxing
*/
using namespace std;
#include  <iostream>
#include <utility>
#define INF 99999

//First int stores the edge weights
pair <int,pair<int,int> > p[8];

int main()
{
	
	//Distance array
	int distance[6] = {INF,INF,INF,INF,INF,0};
	p[0] = make_pair(2,make_pair(0,2));
	p[1] = make_pair(1,make_pair(1,0));
	p[2] = make_pair(-2,make_pair(2,1));
	p[3] = make_pair(-4,make_pair(3,0));
	p[4] = make_pair(-1,make_pair(3,2));
	p[5] = make_pair(1,make_pair(4,3));
	p[6] = make_pair(8,make_pair(5,4));
	p [7]= make_pair(10,make_pair(5,0));
	
	//Bellman-Ford
	for(int i = 0 ; i < 5; i++)
	{
		for(int j =0; j < 8;j++)
		{
			if(distance[p[j].second.second] > distance[p[j].second.first] + p[j].first)
				distance[p[j].second.second] = distance[p[j].second.first] + p[j].first;
		}
	}
	
	int flag = 0;
	//Checking for a negative edge cycle
	for(int i = 0 ; i < 5; i++)
	{
		for(int j =0; j < 8;j++)
		{
			if(distance[p[j].second.second] > distance[p[j].second.first] + p[j].first)
				flag = 1;
		}
	}
	
	if(flag == 1)
	{
		cout<<"Negative edge cycle exists in the graph ";
		return 0 ;
	}
	for(int i = 0; i < 6; i++)
		cout<<"Distance of Source from "<<i + 1<<" the vertex is : "<<distance[i]<<endl;
}

void bellman()
{
	
}
				
