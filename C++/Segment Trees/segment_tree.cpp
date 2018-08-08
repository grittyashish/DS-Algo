/*Segment Tree without Lazy Propagation
 * Query can be made only for finding the minimum within a range or minimum range query
 * By Ashish Kumar Choubey
 * Inspired by Tushar Roy and codemonk
*/
#include<iostream>
#define INF 100000000
#define MAX 10000
using namespace std;

int segTree[MAX],array[MAX];
int min(int a, int b){
	if(a < b)
		return a;
	return b;
}
//Construct the Segment Tree
void construct(int low, int high, int pos){//low and high denote the square bracketted range  and pos denotes the current node
	if(low == high)//leaf node
	{
		segTree[pos] = array[low];
		return ;
	}
	int mid = (high + low)/2;
	construct(low, mid, 2*pos + 1); //Dividing and diving into the left half
	construct(mid + 1, high, 2*pos + 2); // Dividing diving into the right half
	segTree[pos] = min(segTree[2*pos + 1], segTree[2*pos + 2]);// after the left and right child nodes are dealt with, their minimum is stored at their parent
}

int query(int qlow, int qhigh, int low, int high,int pos){
	
	if(qlow > high || qhigh < low)// If no overlap
		return INF;
	if(qlow <= low && qhigh >= high)//Total overlap
		return segTree[pos];
	//If partial overlap => go in both the directions
	int mid = (high+ low)/2;
	return min(query(qlow,qhigh,low,mid,2*pos + 1),query(qlow,qhigh,mid+1,high,2*pos + 2));
}

int main(){
	int no_of_elements,qno,qlow,qhigh;;
	cin>>no_of_elements;//Enter the no. of elements in the array
	for(int i = 0 ;i < no_of_elements; i++)
		cin>>array[i];
	construct(0,no_of_elements - 1,0);
	cin>>qno;//Enter the no. of queries
	while(qno-- > 0){
		cin>>qlow>>qhigh;
		cout<<query(qlow,qhigh,0,no_of_elements - 1,0)<<endl;
	}
	return 0;
}
