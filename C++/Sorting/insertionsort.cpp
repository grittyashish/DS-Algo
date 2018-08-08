#include <iostream>
#define MAX 100
using namespace std;

int main()
{
   int A[MAX],n;
   cin>>n;
   for(int i = 0; i < n; i++)
   		cin>>A[i];
   int temp,j;
   for(int i = 1;i < n ; i++){
	j = i;
	temp = A[j];
	while(temp < A[j - 1] && j >0){
		A[j] = A[j - 1];
		j--;
	}
	A[j] = temp;
  }
		
   for(int i = 0 ; i < n; i++)
	cout<<A[i]<<" ";
   return 0;
}

