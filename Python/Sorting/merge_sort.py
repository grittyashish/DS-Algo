def merge_sort(arr):
    mid = len(arr)//2
    if mid > 1:
        left_half = merge_sort(arr[:mid])
        right_half = merge_sort(arr[mid:])
        return merge(left_half, right_half)
    return arr

def merge(left, right):
    merged = []
    i,j = 0,0
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            merged.append(left[i])
            i += 1
        else:
            merged.append(right[j])
            j += 1

    while i < len(left):
            merged.append(left[i])
            i += 1
    while j < len(right):
            merged.append(right[j])
            j += 1
    return merged

from random import randint
def main():
    arr = [randint(-100,100) for i in range(10)]
    print(arr)
    print(merge_sort(arr))

if __name__ == '__main__':
    main()
