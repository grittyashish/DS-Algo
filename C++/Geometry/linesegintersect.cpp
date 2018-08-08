/*
 *Find if two line segments intersect or not
 *By Ashish Kumar Choubey
 *Inspired by SaurabhSchool
 */

#include <iostream>
using namespace std;
struct Point{
	float x,y;
};

bool onseg(Point,Point,Point);
float CrossProduct(Point,Point,Point);

int main(){
	Point P1,P2,P3,P4;
	cin>>P1.x>>P1.y>>P2.x>>P2.y>>P3.x>>P3.y>>P4.x>>P4.y;
	float D1,D2,D3,D4;
	D1 = CrossProduct(P1,P2,P3);
	D2 = CrossProduct(P1,P2,P4);
	D3 = CrossProduct(P3,P4,P1);
	D4 = CrossProduct(P3,P4,P2);

	if(D1*D2 < 0 && D3*D4 < 0)
		cout<<"Intersect";
	else if(D1 == 0 && onseg(P1,P2,P3)){cout<<"Line segments intersect";}
	else if(D2 == 0 && onseg(P1,P2,P4)){cout<<"Line segments intersect";}
	else if(D3 == 0 && onseg(P3,P4,P1)){cout<<"Line segments intersect";}
	else if(D4 == 0 && onseg(P3,P4,P2)){cout<<"Line segments intersect";}
	else
	cout<<"Line segments do not intersect ";
	return 0;
	}

float CrossProduct(Point X, Point Y, Point Z){
	float XVector1 = Y.x - X.x;
	float YVector1 = Y.y - X.y;
	float XVector2 = Z.x - X.x;
	float YVector2 = Z.y - X.y;

	return XVector1*YVector2 - YVector1 - XVector2;
}

bool onseg(Point X,Point Y,Point Z){
	if(Z.x <= max(X.x,Y.x) && Z.y <= max(X.y,Y.y) && Z.x >= min(X.x,Y.x) && Z.y >= min(X.x,Y.x))
		return true;
	return false;
}

float max(int a,int b){
	return a>b?a:b;
}
float min(int a, int b){
	return a<b?a:b;
} 
