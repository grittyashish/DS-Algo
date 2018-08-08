#include <iostream>
#include <math.h>
#define MAX 9
int Mat[MAX][MAX],size;
int prev[MAX][MAX];
using namespace std;


void take_input(){
	cout<<"Enter the size of sudoku (4 for 4x4, 5 for 5x5, ... 9 for 9x9) "<<endl;
	do{
		cin>>size;
	}while(size <= 0 || size > 9);
	cout<<"Enter the initial board status (for blank cell enter '0')"<<endl;
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			cin>>Mat[i][j];
	return;
}

bool isPossible(int r , int c, int num){

	//If number is present in the same column
	for(int i = 0; i < size; i ++)
		if(num == Mat[i][c])
			return false;

	//If number is present in the same row
	for(int i = 0; i < size; i++)
		if(num == Mat[r][i])
			return false;

	int s = sqrt(size);

	r = (r/s)*s;//Lower bound of row for the current grid
	c = (c/s)*s;//Lower bound of cloumn for the current grid
	//Higher bound of row and column for the current grid is r + s and c + s respectively

	//If number is present in the same grid
	for(int i = r; i < r + s; i++)
		for(int j = c; j < c + s; j++)
			if(num == Mat[i][j])
				return false;

	//If number is suitable to be filled
	return true;
}

bool nextpos(int &r, int &c){
	for(int i = 0; i < size; i++)
		for(int j = 0 ; j < size; j++)
			if(Mat[i][j] == 0){
				r = i;
				c = j;
				return true;
			}
	//If sudoku has been completely filled
	return false;
}


bool Solve_Sudoku( ){
	//bool flag = false;
	int row,col;
	
	//If no next position to be filled, i.e, the board is full and solved!!
	if(!nextpos(row,col))
		return true;
	
	//Checking by trial and error if a number is possible or not
	//If a number is possible then we fill and break out of the loop
	for(int i = 1; i <= size; i++){
		if(isPossible(row,col,i)){
			Mat[row][col] = i;
			if(Solve_Sudoku())
				return true;
			Mat[row][col] = 0;
		}
	}
	return false;
}

int main(){
take_input();
if(Solve_Sudoku()){
	cout<<"Solved!!!"<<endl;
	cout<<"Solution is : "<<endl;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++)
			cout<<Mat[i][j]<<" ";
		cout<<endl;
	}
}

else
cout<<"Solution is not possible : "<<endl;
return 0;
}




