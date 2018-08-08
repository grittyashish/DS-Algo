#include <iostream>
#include <cstring>
using namespace std;

int query(int [], int , int);
void constructBIT(int [], int [], int);
void updateBIT(int [], int , int, int []);

int main(){
	int size;
	cin>>size;
	int array[size], BIT[size + 1];
	for(int i = 0; i < size; i++)
		cin>>array[i];
	memset(BIT,0,(size+1)*sizeof(int));
	constructBIT(BIT,array,size);
	cout<<"The prefix range sum for 6 elements is "<<query(BIT,size,6);
	cout<<endl;
	updateBIT(array,2,size,BIT);
	cout<<"The prefix range sum after update "<<query(BIT,size,6);
	return 0;
}

//Constructing Binary Indexed Tree
void constructBIT(int BIT[],int array[], int size){
	BIT[0] = 0;
	int index;
	for(int i = 0; i < size+1; i++){
		 index = i + 1;
		 BIT[index] += array[i];
		 while(index < size + 1){
			index += index & (-index);
			BIT[index] += array[i];
		}
	}
}

int query(int BIT[],int size, int prefix_range){
	int sum = 0;
	int i = prefix_range;
	while( i > 0){
		sum += BIT[i];
		i -= (i & (-i));
	}
	return sum;
}

//Update Binary Indexed Tree
void updateBIT(int array[],int index, int size, int BIT[]){
	int difference, update;
	cout<<"Enter the new element : ";
	cin>>update;
	difference = update - array[index];
	BIT[index + 1] = difference;
	int i = index + 1;
	while(i < size + 1){
		i += i & (-i);
		BIT[i] += difference;
	}
	cout<<endl;
}
