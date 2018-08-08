/*Djistra's Algorithm using array
 * By Ashish Kumar Choubey
 * Inspired by hackerearth.com and MIT Open Courseware
 */

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

#define NIL 0
#define INFINITY 10000
using namespace std;

int* minimum(int*,int*);
void memset(int* a,int c,int b)
{
       for(int i = 0; i < b; i++)
       {
              *a = c;
              a++;
       }
}

int i = 0;

int main()
{
       //Graph Adjacency List Representation. First integer is the neighbour and second one is the weight between the neighbours
       //Third integer contains the parent of the node in the shortest path from the start vertex to it which initially is 0
       vector <pair<int,int>  > v[5];
       
       //variables for launching Djistra's Algorithm
       int distance[5];
       memset(distance,INFINITY,5);
       
       //array for holding dynamic distances
       int dist[5];
       
       //Removal variable. 0 means no node has been removed or processed and Q[i] = 1 means ith node has been removed 
       //and its minimum distance from the source vertex has been found out.
       int Q[5];
       
       int S[5];
       memset(S,NIL,5);
       memset(Q,1,5);
       memset(dist,INFINITY,5);
       
       //ith index will store the parent of i
       int parent[5];
       memset(parent,NIL,5);
       
       //Creating Graph DS
       v[0].push_back(pair<int,int>(make_pair(1,10)));
       v[0].push_back(pair<int,int>(make_pair(2,3)));
       v[1].push_back(pair<int,int>(make_pair(3,2)));
       v[1].push_back(pair<int,int>(make_pair(2,1)));
       v[2].push_back(pair<int,int>(make_pair(1,4)));
       v[2].push_back(pair<int,int>(make_pair(4,2)));
       v[2].push_back(pair<int,int>(make_pair(3,8)));
       v[3].push_back(pair<int,int>(make_pair(4,7)));
       v[4].push_back(pair<int,int>(make_pair(3,9)));
       int node;

       //Input start node
       cin>>node;
       
       //this node(starting node) is inducted into S
       S[node] = 1;
       
       //Distance of start node from itself is 0
       distance[node] = 0;
       dist[node] = 0;
       i = 0;
       int flag = 0;
       //index variable for S
       int j = 0;
       while(flag != 5)
       {
              flag = 0;
              j = 0;
              while(j < 5)
                     if(S[j++] == 1)
                            flag++;
              if(flag == 5)
                     break;
                     
              int* min = minimum(dist,dist + 5);
              i = (min - dist);//ith node has the minimum distance
              //and it is removed from Q
              Q[i] = 0;
              
              //Literally moving the ith node into S from Q
              S[i] = 1; 
              vector <pair<int,int> >::iterator iter;
              iter = v[i].begin();
              
              //Processing i's neighbours
              while(iter != v[i].end())
              {
                     //Relaxing neighbouring edges if neccessory
                     if(distance[(*iter).first] > distance[i] + (*iter).second)
                     {
                            distance[(*iter).first] = distance[i] + (*iter).second;
                            dist[(*iter).first] = dist[i] + (*iter).second;
                            parent[iter->first] = i;
                     }
                     iter++;
              }
              dist[i] = INFINITY + 1;
       }
       
       i = 0;
       while(i < 5)
       {
              cout<<"Shortest Paths to "<<i + 1<<" has a distance of "<<distance[i]<<" and the path is given below : "<<endl;
              j = i;
              cout<<j + 1;
              while(j !=node)
			{
				j = parent[j];
				cout<<"->"<<j + 1;
			}
			cout<<endl;
              i++;
       }

       return 0;
}

int* minimum(int* a,int* b)
{
       int* min = a;
       while(a != b)
       {
              if(*a < *min)
                     min = a;
              a++;
       }
       return min;
}

