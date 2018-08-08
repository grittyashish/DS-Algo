#include <iostream>
#include <string.h>
#define MAX 5

void swap(char * a,char* i, char* j){
char temp;
temp = *i;
*i = *j;
*j = temp;
}

void permutation(char* a,int i, int j){
if(i == j){
	std::cout<<a<<std::endl;
	return;
}
int k = i ;
for( ; k <= j; k++){
swap(a,a+k,a+i);
permutation(a,i + 1 ,j);
swap(a,a+i,a+k);
}
}
int main(){
char a[MAX] = {'\0'};
std::cout<<"Enter any string"<<std::endl;
std::cin>>a;
permutation(a,0,strlen(a) - 1);
return 0;
}


