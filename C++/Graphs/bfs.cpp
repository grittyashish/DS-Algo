#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

//bfs without find() as it increases the time complexity
queue <int> q;
int visited[10];
int i = 0;

void bfs(int);

int main()
{
	//Graph Adjacency List Representation
	vector <int> v[5];
	
	//Creating Graph DS
	v[0].push_back(1);
	v[0].push_back(2);
	v[1].push_back(3);
	v[1].push_back(4);
	v[1].push_back(0);
	v[2].push_back(0);
	v[3].push_back(1);
	v[4].push_back(1);
	int node;
	
	//Input start node
	cin>>node;
	q.push(node);
	while(i < 10)
		visited[i++] = 0;
	i = 0;

	//bfs(node);
	while(!q.empty())
	{
		//Storing true for q.front(). This denotes that q.front() has been visited
		visited[q.front()] = 1;
		
		//storing the front of q into i for accessing its neighbours
		i = q.front();
		q.pop();
		vector <int>::iterator iter;
		iter = v[i].begin();
		while(iter != v[i].end())
		{
			//checking if *iter node has been visited. Notice that no find function has been used
			if(!visited[*iter])
				q.push(*iter);
			iter++;
		}
		cout<<i;
	}
	
	return 0;
}

/*void bfs(int node)
{
	if(q.empty())
		return;
	if(!q.empty())
		bfs(q.front());
}
*/
