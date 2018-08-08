/*By Ashish Kumar Choubey
 * Inspired by www.hackerearth.com/codemonk, Tushar Roy and MIT Algorithms lecture
 * Rabin Karp String Matching Algorithm
 * Here I am using interconvertiblity of stl string using c_str() to C string for convenience
 * Deque stores the current window
 * It is cleared for hash call for pattern and for the call by the first window
 */ 
#include <iostream>
#include <deque>
#include <math.h>
#include <string.h>
#include <string>
#include <stdio.h>
using namespace std;
deque <char> sub;

int roll_hash(const char Ts[],int old_hash,int m){
int new_hash = 0;
if(old_hash == 0)//If function is being called for the first time for a sub string or the pattern
{
	sub.clear();
	for(int i = 0; i < m; i++)
	{
		sub.push_back(Ts[i]);
		new_hash += (int)(sub.back() )*pow(101,i);
	}
	return new_hash;
}
new_hash = old_hash - sub.front() ;//Subtract the old value
new_hash = new_hash / 101;//Divide by the prime number to literally shift the the rest of the m -1 characters towards left to accomodate the new character
sub.pop_front();// Dropping the first character
sub.push_back(Ts[m - 1]);//Adding the last character of the current window
new_hash  += (int)sub.back() *pow(101,m - 1);
return new_hash;
}

int main()
{
	string T,p,temp;
	getline(std::cin,T);
	getline(std::cin,p);
	int m = p.length(), n = T.length();
	int pat_hash = roll_hash(p.c_str(),0,m);
	int sub_hash = 0;
	for(int i = 0; i <= n - m; i++)
	{
		temp = T.substr(i,m );
		sub_hash = roll_hash(temp.c_str(),sub_hash,m);
		if(sub_hash == pat_hash)//Then we need to compare the strings character by character
			if(temp.compare(p) == 0)
				cout<<"Match found at "<<i<<endl;
	}
	return 0;
}
