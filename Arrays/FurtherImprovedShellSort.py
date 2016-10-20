def shellsort (arr) :
    n = len(arr)
    gap = n/2
    while gap > 0:
        i = gap
        while i < n:
            temp = arr[i]
            j = i
            while j >= gap and temp < arr[j- gap]:
                arr[j] = arr[j-gap]
                j = j-gap
            arr[j] = temp
            i += 1
        gap /= 2    
    
    
    
print ("Enter the elements of the array");
arr = map (int, raw_input().split())
shellsort (arr)
for x in arr:
    print x,