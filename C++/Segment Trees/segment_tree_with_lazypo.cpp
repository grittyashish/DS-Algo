/*Segment Tree with Lazy Propagation
 * Query can be made only for finding the minimum within a range
 * By Ashish Kumar Choubey
 * Inspired by Tushar Roy and codemonk
*/
#include<iostream>
#include<string.h>

#define INF 100000000
#define MAX 10000
using namespace std;

int segTree[MAX],array[MAX],lazy[MAX];
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
	construct(low, mid, 2*pos + 1); //Dividing into the left half
	construct(mid + 1, high, 2*pos + 2); // Dividing into the right half
	segTree[pos] = min(segTree[2*pos + 1], segTree[2*pos + 2]);// after the left and right child nodes are dealt with, their minimum is stored at their parent
}

int query(int qlow, int qhigh, int low, int high,int pos){
	
	if(low > high)
		return INF;
	//previous operations not updated, we need to propagate the value
	if(lazy[pos] != 0)
	{
		segTree[pos] += lazy[pos];
		if(low != high)//If not a leaf node
		{
			lazy[2*pos + 1] = lazy[pos];
			lazy[2*pos + 2] = lazy[pos];
		}
		lazy[pos] = 0;
	}
	if(qlow > high || qhigh < low)// If no overlap
		return INF;
		
	if(qlow <= low && qhigh >= high){//Total overlap
		return segTree[pos];
	}	
	
	//If partial overlap => go in both the directions
	int mid = (high+ low)/2;
	return min(query(qlow,qhigh,low,mid,2*pos + 1),query(qlow,qhigh,mid+1,high,2*pos + 2));
}

void updatesegtree(int qlow, int qhigh,int low, int high, int delta, int pos){
	if(low > high)
		return ;
	
	if(lazy[pos] != 0)//Previous update not propagated
	{
		segTree[pos] += lazy[pos]; //updating current node in segtree
		if(high != low)//Not a leaf node
		{
			lazy[2*pos + 1] += lazy[pos];//updating the left child to signify that everything below this including this is not updated
			lazy[2*pos + 2] += lazy[pos];//updating the right child to signify that everything below this including this is not update
		}
		lazy[pos] = 0;//Since the value at the current node has been update in segtree, it must be zero in lazytree
	}
	//All updates have been applied at the current position and lazy[pos] = 0 for sure
	
	if(low >= qlow && high <= qhigh)//Total overlap
	{	
		segTree[pos] += delta;
		if(low != high)
		lazy[2*pos + 1] += delta;//+= used as this child may have some value already
		lazy[2*pos + 2] += delta;// if the above code block was executed
		return;
	}
	
	if(low > qhigh || high < qlow)//No overlap
		return;
	int mid = (low + high)/2;
	updatesegtree(qlow,qhigh,low,mid,delta,2*pos + 1);
	updatesegtree(qlow,qhigh,mid + 1,high,delta,2*pos + 2);
	segTree[pos] = min(segTree[2*pos + 1],segTree[2*pos + 2]);
}

int main(){	
	int no_of_elements,updateqno,qno,qlow,qhigh,delta;
	cin>>no_of_elements;//Enter the no. of elements in the array
	for(int i = 0 ;i < no_of_elements; i++)
		cin>>array[i];
	construct(0,no_of_elements - 1,0);
	memset(lazy,0,no_of_elements);
	cin>>updateqno>>qno;//Enter the no. of queries
	
	while(updateqno-- > 0){
		cin>>qlow>>qhigh>>delta;
		updatesegtree(qlow, qhigh,0,no_of_elements - 1, delta,0);
	}
	int qans;
	while(qno-- > 0){
		cin>>qlow>>qhigh;
		qans = query(qlow,qhigh,0,no_of_elements - 1,0);
		cout<<qans<<endl;
	}
	return 0;
}
