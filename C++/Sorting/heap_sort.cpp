/*Heap Sort: Inspired By hackerearth.com/codemonk
 * Get and array in any order
 * Algorithm:
 * 1. Build a max heap from the array : For each node 1 to n/2 run max_heapify in bottom up approach( Since n/2 to n are leaf nodes and are themselves elementary heaps)
 * 2. Swap the top element with the last element in the heap and visually decrement the heap size by decrementing variable mark from n to n--
 * 3. Call build_max_heap whose implementation has been described in step 1
 * 4. Repeat above steps 2 and 3 untill mark > 0
 * O(NLogN)
 * By Ashish Kumar Choubey
 * Inspired by www.hackerearth.com/codemonk
 */



#include <iostream>

using namespace std;
int A[10];

//Swaps by reference 
void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

//Corrects a single violation in max heap property
void max_heapify(int n, int i)
{
	int largest = i;
	int left = 2*i, right = 2*i+ 1;
	
	//If left is less than heap size and left child is greater than the parent
	if(left <= n && A[left] > A[i])
		largest = left;
	
	//If left is less than heap size and left child is greater than the parent
	if( right <= n && A[right] > A[largest])
		largest = right;
	
	//If largest is not equal to i implies that one of the children is greater than the parent
	if(largest != i)
	{
		swap(A[largest],A[i]);
		
		//Max heapify the parent which has been swapped to a new location
		max_heapify(n,largest);
	}
}

//Builds a max heap
void build_max_heap(int n)
{
	
	//Iterating over all non-leaf nodes and correcting every single violation if they exist
	for(int i = n/2; i > 0; i--)
		max_heapify(n,i);
}

void heap_sort(int);
int main()
{
	
	for(int i = 1; i < 10; i++)
		cin>>A[i];
	heap_sort(9);
	return 0;
}

void heap_sort( int n)
{
	//Marker for the "dynamic" heap size
	int mark = n;
	build_max_heap(mark);
	int i = 1;
	
	//Untill visual heap size decreases to 1
	while( mark >= 1)
	{
		
		//Swap the max element in heap with the last element
		swap(A[i],A[mark]);
		mark--;
		build_max_heap(mark);
	}
	for(int j = 1; j <= n; j++)
		cout<<A[j]<<" ";
}
