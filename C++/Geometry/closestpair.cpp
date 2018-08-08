/*
 *Finding the closest pair of points
 *out of all the given pair of points
 *Algorithm:
 *Sort the points based on x coordinate
 *Find the mid value of x, m
 *Find the closest pair in l to m
 *Find the closest pair in m+1 to r
 *Select a strip of length of minimum of above two
 *One by one select each point on the left side of the strip
 *Correspondingly select at max 6 points on the right of the strip
 *Repeat the above steps
 *By Ashish Kumar Choubey
 *Inspired by SaurabhSchool
 */

#include <iostream>
#include <math.h>
#include <cmath>//for float abs(float x)
#include <cstdlib>
#define MAX 10
#define INF 999999999
using namespace std;

struct Point{
	float x;
	float y;
};

Point px[MAX],py[MAX];
Point strip[MAX];

int compareY (const void* p1, const void* p2);
int compareX (const void* p1, const void* p2);
float dist(Point p1, Point p2);
float bruteforce(int );
float closest_pair(int l, int r);
float closestinstrip(Point [],int, float);			

int main(){
	int points;
	cin>>points;
	for(int i = 0; i < points; i++)
		cin>>px[i].x>>px[i].y;
	for(int i = 0 ; i < points; i++)
		py[i] = px[i];

	qsort(px,points,sizeof(Point),compareX);
	qsort(py,points,sizeof(Point),compareY);

	float closest_distance = closest_pair(0,points - 1);
	cout<<closest_distance;
	return 0;
}

float closest_pair(int l, int r){
	if(r - l + 1 <= 3)
		return bruteforce(r - l + 1);

	int mid = (l+r)/2;//Divides the points into two halves
	float midx = px[mid].x;//This is my dividing line

	float delta1 = closest_pair(l, mid);//Delta for left set of points
	float delta2 = closest_pair(mid+ 1, r);//Delta for right set of points

	float delta = min(delta1,delta2);//Net minimum


	float leftbound = midx- delta;//left side of strip

	int lp;
	float min = INF;

	//Marking the first point inside the strip from the left side
	for(int i = 0; px[i].x < leftbound; i++)
		lp = i;
	int s = 0;
	//Storing all points inside the strip
	for(int j = 0; px[lp].x <= midx + delta && lp < r - l + 1; j++,lp++){
		strip[j] = px[lp];//Contains all the points inside the strip
	}
	min = closestinstrip(strip,j,delta);

	return min < delta? min: delta;
}

float closestinstrip(Point strip[],int size, float delta){
	float min = INF;
	for(int i = 0; i < size; i++)
		for(int k = i + 1; k < size ; k++)
			if(dist(strip[i],strip[k]) < min)
				min = dist(strip[i],strip[k]);
	return min;
}



int compareY (const void* p1, const void* p2){
	Point *p = (Point*) p1;
	Point *q = (Point*)p2;
	return p->y - q->y;
}

int compareX (const void* p1, const void* p2){
	Point *p = (Point*) p1;
	Point *q = (Point*)p2;
	return p->x - q->x;
}

float dist(const Point p1,const Point p2){
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

float bruteforce(int n){
	float min = INF;
	/*for(int i = l; i <= r; i++)
	  for(int j = i + 1; j <=r ; j++)
	  if(dist(px[i],px[j]) < min){
	  min = sqrt((px[i].x - px[j].x)*(px[i].x - px[j].x) + (px[i].y - px[j].y)*(px[i].y - px[j].y));
	  }
	 */
	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++)
			if(dist(px[i],px[j]) < min)
				min = dist(px[i],px[j]);

	return min;
}
