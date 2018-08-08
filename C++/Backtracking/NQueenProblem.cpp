/*This program gives one solution
 * to place N Queens on an NxN board 
 * such that they do not attack each other
 * By Ashish Kumar Choubey
 */


#include <iostream>
#include <math.h>
#define MAX 9

int Mat[MAX][MAX],size;
using namespace std;

bool isPossible(int r , int c);
bool Solve_NQueen( );
void initialize();

int main(){
cout<<"Enter the board size"<<endl;
cin>>size;
initialize();
if(Solve_NQueen()){
	cout<<"Solved!!!"<<endl;
	cout<<"Solution is : "<<endl;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++)
			cout<<Mat[i][j]<<" ";
		cout<<endl;
	}
}
else
	cout<<"Solution is not possible "<<endl;
return 0;
}



//Checks if the given cell is under attack by a Queen already present on the board completed thus far
bool isPossible(int r , int c){
	//If Queen is present in the same row on the left
	for(int i = c; i >= 0; i--)
		if(1 == Mat[r][i])
			return false;
	
	//If a Queen is present in the upper left diagonal
	for(int i = r,j = c; i >= 0 && j >= 0; i--,j--)
                if(Mat[i][j] == 1)
                        return false;
         
         //If a Queen is present in the lower left diagonal
	 for(int i = r,j = c; i < size && j >= 0; i++,j--)
                if(Mat[i][j] == 1)
                        return false;
                        
	return true; // This position is not attacked by any queen
}

//The main function
bool Solve_NQueen( ){
	if(size == 2 || size == 3)
		return false;
	int solution_row[size],k ;// It stores the row no. of the Queen of kth column. This array helps to jump to the particular row of previous column when backtracking
	bool flag = true;// If it is true, we will start our iteration from 0th row else from the next row(this is done if we backtrack)
	k = 0;
int j = 0;

for(int i = 0; i < size; i++){//Iterating over the column
	if(flag) //If no backtrack occured
		j = 0;
	for(; j < size; j++){//Iterating over the row
		if(isPossible(j,i)){//If this position is not attacked
			Mat[j][i] = 1;
			solution_row[k++] = j;//Store the row position of the Queen
			flag = true;//To ensure that the next time iteration will start from the begininng
			break;//Move to the next column
		}
	}
	if(j == size){//No possible position found for the queen:
		//backtrack
		Mat[solution_row[--k]][--i] = 0;
		i--;//To counter the i++ in the for loop: We need to move our iteration to the previous column
		j = solution_row[k] + 1; // Move to the row next to the position of the Queen
		flag = false; //Helps to retain the value of j mentioned above
	}
}
	
	if(k == size)//All the Queens have been placed with their row nos. in solution_row
		return true;
}
void initialize(){
	for(int i = 0 ; i < size; i++)
		for(int j = 0; j < size; j++)
			Mat[i][j] = 0;
}
