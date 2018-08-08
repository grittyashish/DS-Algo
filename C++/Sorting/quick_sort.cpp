#include <iostream>
#define MAX 10
using namespace std;

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int [], int, int);

int main(){
    int Arr[MAX];
    int n;
    cin>>n;
    for(int i = 0; i < n - 1; i++)
        cin>>Arr[i];
    quicksort(Arr,0,n-1);
    cout<<"The sorted array is : ";
    for(int i = 0; i < n - 1; i++)
        cout<<Arr[i]<<" " ;
    return 0;
}

void quicksort(int arr[], int low, int high){
    if(low >= high)
        return;
    int mid = (low + high)/2;
    int left = low;
    int right = high;
    while(left <= right){
        while(arr[left] < arr[mid])//Move to misplaced element
            left++;
        while(arr[right] > arr[mid])//Move to misplaced element
            right--;

        //Swapping the misplaced element
        swap(&arr[left],&arr[right]);
        left++;
        right--;
    }

    quicksort(arr,low,mid);
    quicksort(arr,mid + 1,high);
}

