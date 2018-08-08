import random
num = int(input())
arr = [random.randint(0,100) for i in range(num)]

def quicksort(arr,low,high) : 
    part = partition(arr,low,high)
    print(part)
    quicksort(arr,low,part)
    quicksort(arr,part,high)

def partition(arr,low,high) : 
    left,right = 0,0
    print(arr[low:high])
    pivot = arr[low]
    while left <= right : 
        while arr[left] <= pivot and left < high-low : 
            left += 1
        while arr[right] >= pivot and right > low: 
            right -= 1
        arr[left],arr[right] = arr[right],arr[left]
        print(arr[low:high])
    return right
quicksort(arr,0,len(arr))
print(arr)
