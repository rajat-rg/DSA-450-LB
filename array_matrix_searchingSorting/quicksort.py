# ye abke aakhri bar bna rha hu dekhe bne ke na
def partition(a, low, high):
    pivot = a[low]
    i = low+1
    j = high
    while True:
        while i <= j and a[i] < pivot:
            i = i+1
        while a[j] > pivot and i <= j:
            j = j-1
        if i < j:
            print(i,j)
            a[i], a[j] = a[j], a[i]
        else:
            break
    a[low], a[j] = a[j], a[low]
    return j


def quick(a, low, high):
    if low < high:
        pivot = partition(a, low, high)
        quick(a, low, pivot-1)
        quick(a, pivot+1, high)


a = []
n = int(input("Enter size"))
print("Enter array")

for i in range(n):
    a.append(int(input()))
quick(a,0,n-1)
print(a)