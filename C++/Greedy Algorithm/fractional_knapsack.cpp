#include <iostream>
#include <algorithm>
#define MAX 10

using namespace std;

struct item{
    float weight, value, ratio;
};

bool compare(const item &one, const item &two){
    return one.ratio > two.ratio;
}

int main(){ item items[MAX];
    int n,max,arr[MAX];
    cin>>n;
    float fraction[MAX], value[MAX];
    for(int i = 0; i < n; i++){
        cin>>items[i].weight>>items[i].value;
        items[i].ratio = items[i].value/items[i].weight;
    }
    cin>>"Enter the maximum weight allowed">>max;
    sort(items,items+n,compare);
    knapsack(items,n,max,arr,fraction,value);
    return 0;
}

knapack(struct items[], int n, int max, int arr[], float fraction[], int value[]){
    float remaining_weight = max;
    int i = 0;
    while(remaining_weight != 0){
        if(items[i].weight <= remaining_weight){
            remaining_weight -= items[i].weight;
            arr[i] = items[i].weight;
            fraction[i] = 1;
            value[i] = items[i].value;
            i++;
        }
        else{
            fraction[i] = remaining_weight/items[i].weight;
            arr[i] = fraction[i]*


