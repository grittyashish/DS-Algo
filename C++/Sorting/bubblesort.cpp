#include <iostream>
#define MAX 1000
using namespace std;

int main()
{
   int A[MAX],n;
   cin>>n;
   for(int i = 0; i < n; i++)
   		cin>>A[i];
   int temp;
   for(int i = 0;i < n  - 1; i++){
   		for(int j = 0; j < n - i -1; j++)
   			if(A[j] >A[j+1]){
   				temp = A[j];
   				A[j] = A[j + 1];
   				A[j + 1] = temp;
   			}
		}
   for(int i = 0 ; i < n; i++)
	cout<<A[i]<<" ";
   return 0;
}

