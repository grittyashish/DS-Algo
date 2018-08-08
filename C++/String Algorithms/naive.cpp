#include <iostream>
#include <stdio.h>
#include <string.h>
int main()
{
	char T[20],P[5];
	gets(T);
	gets(P);
	int j,sT = strlen(T), sP = strlen(P);
	for(int i = 0; i < sT - sP; i++)
	{
		for(j = 0; j < sP; j++)
		{
			if(T[i + j] != P[j])
				break;
		}
		if(j == sP)
			std::cout<<"Match found at "<<i<<std::endl;
	}
	return 0;
}
