#include<stdio.h>
#include<time.h>
#include<stdlib.h>
//clock_t begin,end;
//double timespent;
//int B[2]
void merge(int [],int begl,int m,int endl);
void sort(int [],int beg,int end);
int main()
{
	int A[20];
	time_t t;
	srand((unsigned) time(&t));
	
	FILE* fp = fopen("file.txt","w");
	for(int j = 0 ; j < 20; j++)
		fprintf(fp,"%d\n",rand()%100);
	fclose(fp);
	
	for(int i = 0 ; i < 20; i++)
		scanf("%d",&A[i]);
	
	int size=(sizeof(A)/sizeof(A[0]));
	//begin = clock();
 	sort(A,0,size-1); 
	//for(int j = 0 ; j < 2; j++)
		//printf("%d",B[0]);
	//end = clock();
	//timespent = (end - begin)/CLOCK_PER_SEC;
	for (int i = 0 ; i < size ; i++)
		printf("%d ",A[i]);
	return 0;
}

void sort(int a[], int beg, int end)
{
	//int B[end-beg+1];
	//for(int i = 0; i < end-beg+1; i++)
	//	B[i] = a[i];
	if (beg == end)
		return;
	
	int m = beg+(end-beg)/2;
	sort(a,beg,m);
	sort(a,m + 1,end);
	merge(a,beg,m,end);
}

void merge(int a[], int beg,int m,int end)
{
	int n1=m-beg+1;
	int n2=end-m;
	int A[n1],B[n2];
	int i,j,k;
	
	//copying one half in B
	for(i = 0; i < n1; i++)
	{
		A[i]  = a[beg+i];
	}
	
	//copying other half in A
	for(j = 0; j < n2; j++)
	{
		B[j] = a[m+1+j];
	}

	i = 0;
	j = 0;
	k = beg;
	while(i<n1 && j<n2)
	{
		if(A[i] <= B[j])
		{
			a[k] = A[i];
			i++;
		}
		else
		{
			a[k] = B[j];
			j++;
		}
		k++;
	}	
		//array B has been exhausted
		while (i < n1)
		{
			
				a[k] = A[i];
				i++;
				k++;
			
		}
		
		//array A has been exhausted
		while ( j < n2)
		{
		
				a[k] = B[j];
				j++;
				k++;
			
		}
	
	for(i = 0; i < 8; i++)
		printf("%d	", a[i]);
	printf("\n");
}

