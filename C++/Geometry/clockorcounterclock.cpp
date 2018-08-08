/*
 *Program to find if one vector is closer
 *to the other in clockwise
 *or counter clockwise direction
 *Origin is at (0,0) or the desired point
 *Algorithm:
 *Find cross product and if it is negative
 *then situated closer in clockwise direction
 *else in counter clockwise direction 
 */

#include <iostream>
using namespace std;

struct Point{
	float x,y;
};

int main(){
	Point P1,P2,P3;
	std::cin>>P1.x>>P1.y;
	std::cin>>P2.x>>P2.y;
	char choice;
	cout<<"(0,0) is the origin?";
	cin>>choice;
	
	if(choice == 'y'){
		//Cross Product:
		float cross = P1.x*P2.y - P1.y*P2.x;
		if(cross < 0)
			std::cout<<"Clockwise angular direction is nearer from first to second vector ";
		else if(cross > 0)
			std::cout<<"Counter clockwise direction is nearer from first to second vector";
		else
			std::cout<<"Both vectors are parallel of same ";
	}
	else{
		cout<<"Enter the origin ";
		cin>>P3.x>>P3.y;
		float cross = (P1.x - P3.x)*(P2.y-P3.y) - (P1.y - P3.y)*(P2.x - P3.x);
			if(cross < 0)
			std::cout<<"Clockwise angular direction is nearer from first to second vector ";
		else if(cross > 0)
			std::cout<<"Counter clockwise direction is nearer from first to second vector";
		else
			std::cout<<"Both vectors are parallel of same ";
	}
	return 0;
}	
		
