def partition(a, low, high):

    pivot = a[low]
    i = low+1
    j = high
    while(True):

        while(i <= j and a[i] < pivot):
            i += 1

        while(i <= j and a[j] > pivot):
            j -= 1

        if(i < j):
            a[i], a[j] = a[j], a[i]
        else:
            break

    a[low], a[j] = a[j], a[low]
    return j


def sort(a, low, high):
    if low < high:

        p = partition(a, low, high)
        sort(a, low, p-1)
        sort(a, p+1, high)


def findPair(arr, L, N):
    # code here
    sort(arr, 0, L-1)
    # print(arr)
    for i in range(L):
        if arr[i]+N in arr:
            return 1
    return -1

a = [1,2,3,4,5,6,7,8,9,44]
n,x = 10,7
print(findPair(a,n,x))