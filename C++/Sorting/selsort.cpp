#include <iostream>
#define MAX 100
using namespace std;

int main()
{
   int A[MAX],n;
   cin>>n;
   for(int i = 0; i < n; i++)
   		cin>>A[i];
   int min_index,temp;
   for(int i = 0;i < n ; i++){
   		min_index = i;
   		for(int j = i; j < n ; j++){
   			if(A[min_index] > A[j])
				min_index = j;
		}
		temp = A[i];
		A[i] = A[min_index];
		A[min_index] = temp;
	}
   for(int i = 0 ; i < n; i++)
	cout<<A[i]<<" ";
   return 0;
}

