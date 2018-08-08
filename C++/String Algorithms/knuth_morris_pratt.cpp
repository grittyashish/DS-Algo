//lps means largest proper prefix which is also a proper suffix
#include<iostream>
#include <stdio.h>
#include <string.h>
#define MAX 1000
using namespace std;
void Prefix_Table(char [], int,int []);  // Initializes the prefix table
void KMPalgo(char [] ,char [], int,int); // Runs KMP

int main(){
char  str[MAX], p[MAX];
gets(str);
gets(p);
KMPalgo(str,p,strlen(str),strlen(p));
return 0;
}

void Prefix_Table(char p[], int size,int prefix_table[]){
int i = 0, j = 1 ;// i for holding the size of the lps and j for iterating over the pattern
prefix_table[0] = 0;
//iterating over the entire pattern
for( ;j < size; j++)
{
	//if an lps already exists and upon increasing j we does not get a perfect suffix which is also a perfect prefix of length greater than the last lps
	while(i > 0 && p[i] != p[j])
		i = prefix_table[i  - 1];//IMP: This is being done so that we jump to the previous largest prefix which is also a suffix
	if(p[i] == p[j])
		i++;
	prefix_table[j] = i;
}
}
	
void KMPalgo(char T[], char p[], int n, int m){
int prefix_table[m], j = 0,i = 0;
Prefix_Table(p,m,prefix_table); //Initializing prefix table
while(i < n )//Run until the pattern hits the bottom of the text
{
	while(j < m && T[i] == p[j]){//comparing until j == m
		j++;
		i++;
	}
	if(j != m )//if jth character of p does not match ith character of T
	if(!j)//if the very first character is a mismatch
		i++;//only i must be incremented
	else 	
		j = prefix_table[j - 1];
	else if(j == m )//m - 1 not used as j is incremented upon the last successful comparison.
	{
		cout<<"Match found at "<<i - m<<endl;//i - m denotes relative i
		j = 0;
		i--;//As successful matching of pattern increments i and j unnecessarily so i must be decremented so as not to skip any character
	}
}
}
